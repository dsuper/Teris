#include "func.h"


bool down(AbstractBlock &block, Poisition &last_poi, Container &container, Act act){
	Poisition now_poi = block.down();

	if(last_poi != now_poi){
		if(container == now_poi){
			container.setPoi(last_poi);
			container.check();
			return true;
		}
		block.clean(last_poi);
	}
	block.paint();
	container.paint();
	last_poi = now_poi;
	return false;
}
void left(AbstractBlock &block, Poisition &last_poi, Container &container){
	Poisition now_poi = block.left();
	if(last_poi != now_poi){
		if(container == now_poi){
			block.setPoisition(last_poi);
			return;
		}
		block.clean(last_poi);
	}
	block.paint();
	last_poi = now_poi;
}
void right(AbstractBlock &block, Poisition &last_poi, Container &container){
	Poisition now_poi = block.right();
	if(last_poi != now_poi){
		if(container == now_poi){
			block.setPoisition(last_poi);
			return;
		}
		block.clean(last_poi);
	}
	block.paint();
	last_poi = now_poi;
}
void rotate(AbstractBlock &block, Poisition &last_poi, Container &container){
	Poisition now_poi = block.rotate();
	if(last_poi != now_poi){
		if(container == now_poi){
			block.setPoisition(last_poi);
			return;
		}
		block.clean(last_poi);
	}
	block.paint();
	last_poi = now_poi;
}
bool accDown(AbstractBlock &block, Poisition &last_poi, Container &container, Act act){
	Poisition now_poi = block.accDown();
	if(last_poi != now_poi){
		if(container == now_poi){
			container.setPoi(last_poi);
			container.check();
			return true;
		}
		block.clean(last_poi);
	}
	block.paint();
	container.paint();
	last_poi = now_poi;
	return false;
}
void socket_set(int &mysock, int &tempsock){

	struct sockaddr_in sin;
	struct sockaddr_in pin;
	socklen_t addrsize;
	char buf[100];
	int len1;
	char *str;
	mysock = socket(AF_INET, SOCK_STREAM, 0);
	if (mysock == -1) {
		perror("call to socket");
		exit(1);
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(PORT);

	if (bind(mysock, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
		perror("call to bind");
		exit(1);
	}
	if (listen(mysock, 20) == -1) {
		perror("call to listen");
		exit(1);
	}
	tempsock = accept(mysock, (struct sockaddr *)&pin, &addrsize);
	if (tempsock == -1){
		perror("call to accept");
		exit(1);
	}


}

void socket_set(int &mysock){
	struct sockaddr_in sin;
	struct sockaddr_in pin;
	socklen_t addrsize;
	char buf[100];
	int len1;
	char *str;
	bzero(&sin, sizeof(sin));
	pin.sin_family = AF_INET;
	pin.sin_addr.s_addr = inet_addr("140.116.82.246");
	pin.sin_port = htons(PORT);

	mysock = socket(AF_INET, SOCK_STREAM, 0);
	if (mysock == -1) {
		perror("call to socket");
		exit(1);
	}
	if (connect(mysock, (sockaddr *)&pin, sizeof(pin)) == -1) {
		perror("call to connect");
		exit(1);
	}

}

void send_Lose(int sock, Container &container){

	for(int i = 0; i < container.getHeight(); ++i){
		char* row = container.getRow(i);
		send(sock, row, container.getWidth(), 0);
		delete[] row;
	}
	int* score = container.getScore();
	send(sock, score, 12, 0);
	if(container.getOppLose()){
		mvprintw(30, 50, "%d!!!!!!!!!!!!", container.getOppLose());
	}

	
	delete[] score;

}
int send_receive(int sock, Container &container){

	for(int i = 0; i < container.getHeight(); ++i){
		char* row = container.getRow(i);
		send(sock, row, container.getWidth(), 0);
		recv(sock, container.getOppRow(i), container.getWidth(), 0);
		delete[] row;
	}
	int* score = container.getScore();
	send(sock, score, 12, 0);
	recv(sock, container.getOppScore(), 12, 0);

	
	delete[] score;

	return container.getOppLose();
}
void clean(){
	for(int i = 0; i < 4; ++i){
		mvprintw(5, i + 16, " ");
		mvprintw(6, i + 16, " ");
		mvprintw(7, i + 16, " ");
		mvprintw(8, i + 16, " ");
	}
}

void paint_next(int next){
	clean();
	init_pair(1, COLOR_RED, 0);
	attron(COLOR_PAIR(1));
	mvprintw(3, 16, "Next");
	attroff(COLOR_PAIR(1));

	int i = 16;
	switch(next){
		case 0:
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(6, 1 + i, "x");
			mvprintw(6, 3 + i, "x");

			break;
		case 1:
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(7, 2 + i, "x");
			mvprintw(7, 3 + i, "x");
			break;
		case 2:
			mvprintw(5, 1 + i, "x");
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(6, 3 + i, "x");

			break;

		case 3:
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(7, 2 + i, "x");
			mvprintw(8, 2 + i, "x");

			break;

		case 4:
			mvprintw(5, 2 + i, "x");
			mvprintw(5, 3 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(6, 1 + i, "x");


			break;

		case 5:
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(5, 3 + i, "x");
			mvprintw(6, 3 + i, "x");


			break;

		case 6:
			mvprintw(5, 2 + i, "x");
			mvprintw(6, 2 + i, "x");
			mvprintw(7, 2 + i, "x");
			mvprintw(7, 1 + i, "x");

			break;

	}
}

