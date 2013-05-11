#include "IBlock.h"

IBlock::IBlock():AbstractBlock(){
	poi.x[0] = 3 + shift_x;
	poi.y[0] = 0;
	poi.x[1] = 3 + shift_x;
	poi.y[1] = 1;
	poi.x[2] = 3 + shift_x;
	poi.y[2] = 2;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 3;
}

IBlock::IBlock(Container &container, Act type):AbstractBlock(type){
	shift_y = 2;
	poi.x[0] = 3 + shift_x;
	poi.y[0] = 0 + shift_y;
	poi.x[1] = 3 + shift_x;
	poi.y[1] = 1 + shift_y;
	poi.x[2] = 3 + shift_x;
	poi.y[2] = 2 + shift_y;
	poi.x[3] = 3 + shift_x;
	poi.y[3] = 3 + shift_y;
	if(container == poi){
		container.setLose(true);
	}
}

Poisition IBlock::down(){
	poi.y[0] += v/speed;
	poi.y[1] += v/speed;
	poi.y[2] += v/speed;
	poi.y[3] += v/speed;
	
	return poi;
}

Poisition IBlock::right(){
	poi.x[0] += 1;
	poi.x[1] += 1;
	poi.x[2] += 1;
	poi.x[3] += 1;
	return poi;
}

Poisition IBlock::left(){
	poi.x[0] -= 1;
	poi.x[1] -= 1;
	poi.x[2] -= 1;
	poi.x[3] -= 1;

	return poi;

}

Poisition IBlock::rotate(){
	switch(poi.type){
		case 0:
			poi.x[0] = poi.x[1] + 1;
			poi.y[0] = poi.y[1];
			poi.x[2] = poi.x[1] - 1;
			poi.y[2] = poi.y[1];
			poi.x[3] = poi.x[1] - 2;
			poi.y[3] = poi.y[1];
			poi.type = 1;
		break;
		case 1:
			poi.x[0] = poi.x[1];
			poi.y[0] = poi.y[1] - 1;
			poi.x[2] = poi.x[1];
			poi.y[2] = poi.y[1] + 1;
			poi.x[3] = poi.x[1];
			poi.y[3] = poi.y[1] + 2;

			poi.type = 0;
		break;
		}
	return poi;

}

