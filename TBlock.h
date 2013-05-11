#ifndef TBLOCK_H
#define TBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class TBlock : public AbstractBlock{
	public:
		TBlock();
		TBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
