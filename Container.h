#ifndef CONTAIN_H
#define CONTAIN_H

#include "Poisition.h"
#include <cmath>
#include <cstring>
#include <ncurses.h>

class Container{
	friend bool  operator== (Poisition const&, Container const&) ;
	friend bool  operator!= (Poisition const&, Container const&) ;
	public:
		Container();
		Container(int, int);
		~Container();
		bool operator== (Poisition const &) const;
		bool operator!= (Poisition const &) const;
		void setPoi(Poisition const&);
		void rmPoi(Poisition const&);
		void paint();
		void setContainer();
		void check();
		void setLose(bool);
		char* getRow(int row) const;
		char* getOppRow(int row){return opp_game[row];}
		int* getOppScore(){return opp_score;}
		int getWidth() const{return width;}
		int getHeight() const{return height;}
		int getOppLose() const{return opp_score[2];}
		bool getLose() const{return bool_lose;}
		int* getScore() const;
	private:
		int **vec_game;
		int width;
		int height;
		int score;
		int total_score;
		int combo;
		char**opp_game;
		int *opp_score;
		int lose;
		bool bool_lose;
		void remove(int);
		void clean();




};
#endif
