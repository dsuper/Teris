#include "OBlock.h"

OBlock::OBlock():AbstractBlock(){
	poi.x[0] = 2 + shift_x;
	poi.y[0] = 0;
	poi.x[1] = 2 + shift_x;
	poi.y[1] = 1;
	poi.x[2] = 1 + shift_x;
	poi.y[2] = 1;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 1;
	
}
OBlock::OBlock(Container &container, Act type):AbstractBlock(type){
	poi.x[0] = 2 + shift_x;
	poi.y[0] = 0 + shift_y;
	poi.x[1] = 2 + shift_x;
	poi.y[1] = 1 + shift_y;
	poi.x[2] = 3 + shift_x;
	poi.y[2] = 0 + shift_y;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 1 + shift_y;
	if(container == poi){
		container.setLose(true);
	}
	
}

Poisition OBlock::down(){
	poi.y[0] += v/speed;
	poi.y[1] += v/speed;
	poi.y[2] += v/speed;
	poi.y[3] += v/speed;
	
	return poi;
}

Poisition OBlock::right(){
	poi.x[0] += 1;
	poi.x[1] += 1;
	poi.x[2] += 1;
	poi.x[3] += 1;
	return poi;
}

Poisition OBlock::left(){
	poi.x[0] -= 1;
	poi.x[1] -= 1;
	poi.x[2] -= 1;
	poi.x[3] -= 1;

	return poi;

}

	
Poisition OBlock::rotate(){
	return poi;
}
