#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class ZBlock : public AbstractBlock{
	public:
		ZBlock();
		ZBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
