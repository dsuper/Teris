#ifndef POI_H
#define POI_H

#include <vector>
#include <ncurses.h>
#include <cmath>
using namespace std;

class Container;

class Poisition{
	friend class  AbstractBlock;
	friend class  RLBlock;
	friend class  RZBlock;
	friend class  OBlock;
	friend class  LBlock;
	friend class  ZBlock;
	friend class  IBlock;
	friend class  TBlock;
	friend class  Container;
	friend bool  operator== (Poisition const&, Container const&);
	friend bool  operator!= (Poisition const&, Container const&);
	private:
		vector<double> x;
		vector<double> y;
		int type;
	public:	
		Poisition();
		bool operator== (Poisition const & in) const;
		bool operator!= (Poisition const & in) const;
		const Poisition& operator= (const Poisition &in);
		void paint();



};
#endif
