/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Class Specification file for Maindeck. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef MAINDECK_HPP
#define MAINDECK_HPP
#include <string>
#include "Space.hpp"

//Defines the interface of the Maindeck Class.
class Maindeck: public Space{
private:
  //Declare private variables for Maindeck

public:

  //Constructors.
  Maindeck();
  //Member functions.

  //Mutators
  void setPlayer(int, int);
};
#endif
