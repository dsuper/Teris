#include <menu.h>
#include <ncurses.h>
#include <cstdio>
#include <iostream>
#include "AbstractBlock.h"
#include "RZBlock.h"
#include "OBlock.h"
#include "RLBlock.h"
#include "ZBlock.h"
#include "IBlock.h"
#include "LBlock.h"
#include "TBlock.h"
#include "Poisition.h"
#include "Container.h"
#include "func.h"
#include "Timer.h"
#include <iostream>
#define RAND_NUM 7
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

using  namespace std;


int main(){
	bool go_on = true;
	int c;
	char s[1000];
	int width = 100;
	int height = 20;
	int block;
	int next_block;
	int socket_num = -1;
	bool bool_change = true;
	bool bool_win = false;
	int mysock;
	int inputsock;
	Act act = single;
	/*	WINDOW *my_menu_win;
		MENU *my_menu;
		ITEM **my_items;
	 */
	printf("Choose a mode to play\n");
	printf("1. Create an online game\n");
	printf("2. Join an online game\n");
	printf( "3. Play sigle mode\n");
	cin >> c;
	switch(c){
		case 1:
			act = server;
			socket_set(mysock, inputsock);
			srand( time(NULL));
			break;

		case 2:
			act = client;
			socket_set(mysock);
			srand( time(NULL) + 1);
			break;

		case 3:
			srand( time(NULL));

			break;
		default:	
		break;
	}

	initscr();
	start_color();
	cbreak(); // disable key buffering
	keypad(stdscr, TRUE);
	noecho(); // disable echoing keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	AbstractBlock *ptrBlock;
	Container container(14, 20);
	Poisition last_poi;
	Timer time;

	block = rand() % RAND_NUM;
	while( go_on ){
		while( (c=getch()) == ERR && go_on){
			if(bool_change){
				next_block = rand() % RAND_NUM;
				switch(block){
					case 0:
						ptrBlock = new TBlock(container, act);
						ptrBlock->paint();
						break;
					case 1:
						ptrBlock = new LBlock(container, act);
						ptrBlock->paint();
						break;
					case 2:
						ptrBlock = new ZBlock(container, act);
						ptrBlock->paint();
						break;
					case 3:
						ptrBlock = new IBlock(container, act);
						ptrBlock->paint();
						break;
					case 4:
						ptrBlock = new RZBlock(container, act);
						ptrBlock->paint();
						break;
					case 5:
						ptrBlock = new OBlock(container, act);
						ptrBlock->paint();
						break;
					case 6:
						ptrBlock = new RLBlock(container, act);
						ptrBlock->paint();
						break;
				}
				block = next_block;
				bool_change = false;
				paint_next(next_block);
				if(container.getLose()){
					go_on = false;
					time.stopTime();
					break;
				}
			}
			if(down(*ptrBlock, last_poi, container, act)){
				bool_change = true;
				delete ptrBlock;
			}
			if(act == server){
				if(send_receive(inputsock, container) == 1){
					go_on = false;
					bool_win = true;
				}
			}
			else if(act == client){
				if(send_receive(mysock, container) == 1){
					go_on = false;
					bool_win = true;
				}
			}
			
			time.setTime();
		}
		switch(c){
			case KEY_UP: 
				break;
			case KEY_DOWN:
				if(accDown(*ptrBlock, last_poi, container, act)){
					bool_change = true;
					delete ptrBlock;
				}		
				break;
			case KEY_LEFT:
				left(*ptrBlock, last_poi, container);
				break;
			case KEY_RIGHT:
				right(*ptrBlock, last_poi, container);
				break;
			case ' ':
				rotate(*ptrBlock, last_poi, container);
				break;
			case 'q':
				go_on = false;
				break;
			default:
				break;
		}
	}
	if(act == client){
		send_Lose(mysock, container);
	}
	else if(act == server){
		send_Lose(inputsock, container);
	}

	while( (c = getchar() != 'q')){
		time.displayTime();
		if(bool_win){
			mvprintw(30, 60, "YOU WIN");
		}
		else{
			mvprintw(30, 60, "YOU LOSE");
		}
			
	}
	endwin();
	cout << "YOU LOSE" << endl;
	close(mysock);
	close(inputsock);
	return 0;
}
