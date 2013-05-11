#ifndef OBLOCK_H
#define OBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class OBlock : public AbstractBlock{
	public:
		OBlock();
		OBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
