#ifndef RLBLOCK_H
#define RLBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class RLBlock : public AbstractBlock{
	public:
		RLBlock();
		RLBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
