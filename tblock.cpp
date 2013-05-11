#include "TBlock.h"

TBlock::TBlock():AbstractBlock(){
	poi.x[0] = 2 + shift_x;
	poi.y[0] = 0;
	poi.x[1] = 2 + shift_x;
	poi.y[1] = 1;
	poi.x[2] = 1 + shift_x;
	poi.y[2] = 1;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 1;
	
}
TBlock::TBlock(Container &container, Act type):AbstractBlock(type){
	poi.x[0] = 2 + shift_x;
	poi.y[0] = 0 + shift_y;
	poi.x[1] = 2 + shift_x;
	poi.y[1] = 1 + shift_y;
	poi.x[2] = 1 + shift_x;
	poi.y[2] = 1 + shift_y;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 1 + shift_y;
	if(container == poi){
		container.setLose(true);
	}
	
}

Poisition TBlock::down(){
	poi.y[0] += v/speed;
	poi.y[1] += v/speed;
	poi.y[2] += v/speed;
	poi.y[3] += v/speed;
	
	return poi;
}

Poisition TBlock::right(){
	poi.x[0] += 1;
	poi.x[1] += 1;
	poi.x[2] += 1;
	poi.x[3] += 1;
	return poi;
}

Poisition TBlock::left(){
	poi.x[0] -= 1;
	poi.x[1] -= 1;
	poi.x[2] -= 1;
	poi.x[3] -= 1;

	return poi;

}

	
Poisition TBlock::rotate(){
	switch(poi.type){
		case 0:
			poi.x[0] = poi.x[1] + 1;
			poi.y[0] = poi.y[1];
			poi.x[2] = poi.x[1];
			poi.y[2] = poi.y[1] - 1;
			poi.x[3] = poi.x[1];
			poi.y[3] = poi.y[1] + 1;
			poi.type = 1;
		break;
		case 1:
			poi.x[0] = poi.x[1];
			poi.y[0] = poi.y[1] + 1;
			poi.x[2] = poi.x[1] + 1;
			poi.y[2] = poi.y[1];
			poi.x[3] = poi.x[1] - 1;
			poi.y[3] = poi.y[1];

			poi.type = 2;
		break;
		case 2:
			poi.x[0] = poi.x[1] - 1;
			poi.y[0] = poi.y[1];
			poi.x[2] = poi.x[1];
			poi.y[2] = poi.y[1] + 1;
			poi.x[3] = poi.x[1];
			poi.y[3] = poi.y[1] - 1;
			
			poi.type = 3;
			break;
		case 3:
			poi.x[0] = poi.x[1];
			poi.y[0] = poi.y[1] - 1;
			poi.x[2] = poi.x[1] - 1;
			poi.y[2] = poi.y[1];
			poi.x[3] = poi.x[1] + 1;
			poi.y[3] = poi.y[1];
			poi.type = 0;
		break;
		}
	return poi;

}
