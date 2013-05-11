#include "Poisition.h"

using namespace std;

Poisition::Poisition():x(4), y(4){
/*	x.push_back(1);
	y.push_back(1);
	x.push_back(1);
	y.push_back(1);
	x.push_back(1);
	y.push_back(1);
	x.push_back(1);
	y.push_back(1);
	
	for(int i = 0; i < 4; i++){
		x[i] = 1;
		y[i] = 1;
	}
*/	type = 0;
}

bool Poisition::operator== (Poisition const &in) const{
	if(floor(x[0]) == floor(in.x[0]) && floor(y[0]) == floor(in.y[0])){
		if(floor(x[1]) == floor(in.x[1]) && floor(y[1]) == floor(in.y[1])){
			if(floor(x[2]) == floor(in.x[2]) && floor(y[2]) == floor(in.y[2])){
				if(floor(x[3]) == floor(in.x[3]) && floor(y[3]) == floor(in.y[3])){
					return true;
				}
			}
		}
	}
	return false;				
}

bool Poisition::operator!= (Poisition const &in) const{
	return( !(*this == in));
}


const Poisition& Poisition::operator= (const Poisition &in){
	for(int i =0; i < 4; ++i){
		x[i] = in.x[i];
		y[i] = in.y[i];
	}
	type = in.type;
	return (*this);
}

void Poisition::paint(){
	for(int i = 0; i < 4; ++i){
		mvprintw(15+i, 60,"x=%f, y=%f", x[i], y[i]);
		}
}
