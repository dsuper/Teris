#include "AbstractBlock.h"


AbstractBlock::AbstractBlock(){
	v = 1;
	speed = 1024  / 4 ;
	shift_x = 6;
	shift_y = 1;
}
AbstractBlock::AbstractBlock(Act type){
	v = 1;
	if(type == single){
		speed = 1024  * 5 ;
	}
	else{
		speed = 1024 / 4;
	}
	act = type;	
	shift_x = 6;
	shift_y = 2;
}


void AbstractBlock::paint() const{
	
	mvprintw(poi.y[0], poi.x[0], "X");
	mvprintw(poi.y[1], poi.x[1], "X");
	mvprintw(poi.y[2], poi.x[2], "X");
	mvprintw(poi.y[3], poi.x[3], "X");
}

void AbstractBlock::clean(const Poisition &in) const{
	mvprintw(in.y[0], in.x[0], " ");
	mvprintw(in.y[1], in.x[1], " ");
	mvprintw(in.y[2], in.x[2], " ");
	mvprintw(in.y[3], in.x[3], " ");
}

Poisition AbstractBlock::accDown(){
	poi.y[0] += 1;
	poi.y[1] += 1;
	poi.y[2] += 1;
	poi.y[3] += 1;
	
	return poi;
	
}

void AbstractBlock::setPoisition(const Poisition& in_poi){
	poi = in_poi;
}
