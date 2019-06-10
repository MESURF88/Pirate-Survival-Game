/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  05/31/2019
** Description: Main method file for StackQueue class. loops
** menu for user to choose if wants to keep playing or to quit program.
******************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include "menu.hpp"
#include "GameControl.hpp"



int main()
{
	int option_picked = 0;

	option_picked = menu();//Call initial function

  //Loop information system until user quits the menu.
	while (option_picked == 1)
	{
		GameControl game1;
		option_picked = menu();
  }


	return 0;
}
