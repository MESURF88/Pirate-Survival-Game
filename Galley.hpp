/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/010/2019
** Description: Class Specification file for Galley. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef GALLEY_HPP
#define GALLEY_HPP
#include <string>
#include "Space.hpp"

//Defines the interface of the Galley Class.
class Galley: public Space{
private:
  //Declare private variables for Galley

public:

  //Constructors.
  Galley();
  //Member functions.

  //Mutators
  void setPlayer(int, int);
};
#endif
