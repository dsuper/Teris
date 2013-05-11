#ifndef ABSTRACTBLOCK_H
#define ABSTRACTBLOCK_H

#include <vector>
#include <cstdlib>
#include "Poisition.h"
#include <ncurses.h>
#include "Container.h"
#include "Act.h"

class AbstractBlock{
	protected:
		Poisition poi;
		int shift_x;
		int speed;
		int shift_y;
		double v;
		Act act;
	public:
		AbstractBlock();
		AbstractBlock(Act);
		virtual Poisition down() = 0;
		virtual Poisition left() = 0;
		virtual Poisition right() = 0;
		virtual Poisition rotate() = 0;
		Poisition accDown();
		void setPoisition(const Poisition&);
		void paint() const;
		void clean(const Poisition &in) const;
		
};


#endif
