#ifndef LBLOCK_H
#define LBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class LBlock : public AbstractBlock{
	public:
		LBlock();
		LBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
