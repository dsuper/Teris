#ifndef RZBLOCK_H
#define RZBLOCK_H

#include "AbstractBlock.h"
#include "Container.h"
#include <vector>

class RZBlock : public AbstractBlock{
	public:
		RZBlock();
		RZBlock(Container&, Act);
		Poisition down();
		Poisition right();
		Poisition left();
		Poisition rotate();
};


#endif
