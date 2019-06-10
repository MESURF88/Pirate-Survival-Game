###
### @file - Makefile
### @author - Kevin hillkev <hillkev@oregonstate.edu>
### @description - Makefile for the FinalProject, compiles files that have been changed
### with command 'make' and cleans object files with command 'make clean'.

#
# Valgrind Options
#
VOPT=--tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes
COMP=-Wall -std=c++11 -g

all: final

final: main.o menu.o inputValidateMenu.o GameControl.o Space.o Galley.o Hall.o Maindeck.o Bowsprit.o Opendeck.o Item.o PrintText.o LocHandler.o
	g++ $(COMP) main.o menu.o inputValidateMenu.o GameControl.o Space.o Galley.o Hall.o Maindeck.o Bowsprit.o Opendeck.o Item.o PrintText.o LocHandler.o -o final

GameControl.o: GameControl.cpp GameControl.hpp
	g++ -c $(COMP) GameControl.cpp

PrintText.o: PrintText.cpp PrintText.hpp
	g++ -c $(COMP) PrintText.cpp

LocHandler.o: LocHandler.cpp LocHandler.hpp
	g++ -c $(COMP) LocHandler.cpp

Space.o: Space.cpp Space.hpp
	g++ -c $(COMP) Space.cpp

Galley.o: Galley.cpp Galley.hpp
	g++ -c $(COMP) Galley.cpp

Hall.o: Hall.cpp Hall.hpp
	g++ -c $(COMP) Hall.cpp

Maindeck.o: Maindeck.cpp Maindeck.hpp
	g++ -c $(COMP) Maindeck.cpp

Bowsprit.o: Bowsprit.cpp Bowsprit.hpp
	g++ -c $(COMP) Bowsprit.cpp

Opendeck.o: Opendeck.cpp Opendeck.hpp
	g++ -c $(COMP) Opendeck.cpp

Item.o: Item.cpp Item.hpp
	g++ -c $(COMP) Item.cpp

main.o: main.cpp
	g++ -c $(COMP) main.cpp

inputValidateMenu.o: inputValidateMenu.cpp inputValidateMenu.hpp
	g++ -c $(COMP) inputValidateMenu.cpp

menu.o: menu.cpp menu.hpp
	g++ -c $(COMP) menu.cpp

valgrind:
	valgrind $(VOPT) ./final

clean: $(CLEAN)
	rm -f final
