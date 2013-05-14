#ifndef FUNC_H
#define FUNC_H

#include "Poisition.h"
#include "AbstractBlock.h"
#include "Container.h"
#include <cstdlib>
#include <ncurses.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Act.h"

#define PORT 9999
bool down(AbstractBlock &, Poisition &, Container &, Act);

void left(AbstractBlock &, Poisition &, Container &);

void right(AbstractBlock &, Poisition &, Container &);

void rotate(AbstractBlock &, Poisition &, Container &);

bool accDown(AbstractBlock &, Poisition &, Container &, Act);

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

void socket_set(int &, int &);

void socket_set(int &);

int send_receive(int sock, Container &container);

void send_Lose(int sock, Container &container);

void paint_next(int);

void paint();

void end_game(bool bool_win);
#endif
