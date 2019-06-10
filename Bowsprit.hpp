/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Class Specification file for Bowsprit. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef BOWSPRIT_HPP
#define BOWSPRIT_HPP
#include <string>
#include "Space.hpp"

//Defines the interface of the Bowsprit Class.
class Bowsprit: public Space{
private:
  //Declare private variables for Bowsprit

public:

  //Constructors.
  Bowsprit();
  //Member functions.

  //Mutators
  void setPlayer(int, int);
};
#endif
