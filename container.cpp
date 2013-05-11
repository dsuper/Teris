#include "Container.h"
#define WALL 9
#define BOUND 8

Container::Container(){}

Container::Container(int in_w, int in_h):width(in_w),height(in_h){
	vec_game = new int*[height];
	opp_game = new char*[height];
	for(int i = 0; i < height; i++){
		vec_game[i] = new int[width];
		opp_game[i] = new char[width];
	}
	opp_score = new int[3];
	bool_lose = false;
	lose = 0;
	score = 0;
	combo = 0;
	total_score = 0;
	setContainer();
}

Container::~Container(){
	for(int i = 0; i < height; i++){
		delete [] vec_game[i];
		delete [] opp_game[i];
	}
	delete [] opp_game;
	delete [] vec_game;
	delete [] opp_score;
}


void Container::setContainer(){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			vec_game[i][j] = 0;
		}
	}
	for(int i = 0; i < height; ++i){
		vec_game[i][0] = BOUND;
		vec_game[i][1] = WALL;
		vec_game[i][width-1] = BOUND;
		vec_game[i][width-2] = WALL;
		}
	for(int i = 0; i < width; ++i){
		vec_game[height-1][i] = BOUND;
	}
	vec_game[0][1] = BOUND;
	vec_game[0][width-2] = BOUND;
	vec_game[1][1] = BOUND;
	vec_game[1][width-2] = BOUND;
	opp_score[0] = -1;
	opp_score[1] = -1;
	opp_score[2] = 0;
}

bool Container::operator== (Poisition const &poi) const{
	for(int i = 0; i < 4; ++i){
		int x = floor(poi.x[i]);
		int y = floor(poi.y[i]);
		if((vec_game[y][x] == 1) || (vec_game[y][x] == BOUND) || (vec_game[y][x] == WALL)){
			return true;
		}
	}
	return false;
}

bool Container::operator!= (Poisition const &poi) const{
	return !((*this) == poi);
}

bool operator== (Poisition const& poi, Container const& con) {
	return (con == poi);
}

bool operator!= (Poisition const& poi, Container const& con) {
	return !(con == poi);
}


void Container::setPoi(Poisition const& poi){
	for(int i = 0; i < 4; i++){
		int x = floor(poi.x[i]);
		int y = floor(poi.y[i]);
		vec_game[y][x] = 1;
	}
}

void Container::paint(){
	init_pair(1, COLOR_RED, 0);
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < height; ++j){
			if(vec_game[j][i] == 1){
				attron(A_REVERSE);
				mvprintw(j, i, " ");
				attroff(A_REVERSE);
			}
			else if(vec_game[j][i] == WALL){
				attron(COLOR_PAIR(1));
				mvprintw(j, i, "|");
				attroff(COLOR_PAIR(1));

			}
		}
	}

	init_pair(1, COLOR_RED, 0);
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < height; ++j){
			if(opp_game[j][i] == '1'){
				attron(A_REVERSE);
				mvprintw(j, i + 30, " ");
				attroff(A_REVERSE);
			}
			else if(opp_game[j][i] == '9'){
				attron(COLOR_PAIR(1));
				mvprintw(j, i + 30, "|");
				attroff(COLOR_PAIR(1));

			}
			else if(opp_game[j][i] == '0'){
				mvprintw(j, i + 30, " ");
			}
		}
	}

	mvprintw(21, 0, "Combo : %d  ", combo);
	mvprintw(22, 0, "Score : %d  ", score);
	mvprintw(23, 0, "Total Score : %d", total_score);
	if(opp_score[0] != -1){
		mvprintw(21, 30, "Combo : %d  ", opp_score[0]);
		mvprintw(22, 30, "Score : %d  ", opp_score[1]);
	}
//	for(int i = 0; i < width; ++i){
//		for(int j = 0; j < height; ++j){
//				mvprintw(j, i+30, "%d", vec_game[j][i]);
//		}
//	}
}

void Container::check(){
	int row = 0, i = 0;
	combo = 0;
	score = 50;
	while(row != height-1){
		for(i = 2; i < width-2; ++i){
			if(vec_game[row][i] != 1){
				break;
			}
		}
		if(i == width -2){
			combo++;
			remove(row);
			row = 0;
		}
		else{
			++row;
		}

	}
	for(int i = 0; i < combo + 1; ++i){
		score += 100 * i;
	}
	total_score += score;
	clean();
	paint();
}

void Container::remove(int row){
	for(int i = row; i > 0; i--){
		for(int j = 2; j < width - 2; ++j){
			vec_game[i][j] =vec_game[i-1][j];
		}
	}
}

void Container::clean(){
	for(int i = 0; i < height - 1; ++i){
		for(int j = 1; j < width - 1; j++){
			mvprintw(i, j, " ");
		}
	}
}

void Container::rmPoi(const Poisition& poi){
	for(int i = 0; i < 4; ++i){
		int x = floor(poi.x[i]);
		int y = floor(poi.y[i]);
		vec_game[y][x] = 0;
	}
}

void Container::setLose(bool in_bool){
	bool_lose = in_bool;
	lose = 1;
}

char* Container::getRow(int row) const{
	char* temp= new char[width];
	for(int i = 0; i < width; ++i){
		temp[i] = vec_game[row][i] + '0';
	}
	return temp;
}

int* Container::getScore() const{
	int* tmp = new int[3];
	tmp[0] = score;
	tmp[1] = total_score;
	tmp[2] = lose;
	return tmp;
}




