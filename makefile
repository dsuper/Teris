H = AbstractBlock.h TBlock.h LBlock.h func.h Poisition.h Container.h ZBlock.h IBlock.h Timer.h RZBlock.h OBlock.h RLBlock.h
OBJ = main.o abstractblock.o lblock.o poisition.o func.o tblock.o container.o iblock.o zblock.o timer.o rzblock.o oblock.o rlblock.o

Teris:$(OBJ) $(H)
	g++  -o Teris $(OBJ) -lncurses
main.o:main.cpp
	g++ -g -c main.cpp
abstractbloc.o:abstractblock.cpp AbstractBlock.h
	g++ -g -c abstractblock.cpp
rtblock.o:rtblock.cpp RTBlock.h
	g++ -g -c rtblock.cpp
tblock.o:tblock.cpp TBlock.h
	g++ -g -c tblock.cpp
oblock.o:oblock.cpp OBlock.h
	g++ -g -c oblock.cpp
lblock.o:lblock.cpp LBlock.h
	g++ -g -c lblock.cpp
rzblock.o:rzblock.cpp RZBlock.h
	g++ -g -c rzblock.cpp
zblock.o:zblock.cpp ZBlock.h
	g++ -g -c zblock.cpp
iblock.o:iblock.cpp IBlock.h
	g++ -g -c iblock.cpp
container.o:Container.h container.cpp
	g++ -g -c container.cpp
poisition.o:Poisition.h poisition.cpp
	g++ -g -c poisition.cpp
func.o:func.cpp func.h
	g++ -g -c func.cpp
timer.o:Timer.h timer.cpp
	g++ -g -c timer.cpp

clean:
	rm *.o
