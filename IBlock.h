#ifndef IBLOCK_H
#define IBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class IBlock : public AbstractBlock{
	public:
		IBlock();
		IBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
