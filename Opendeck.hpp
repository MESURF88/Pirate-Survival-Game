/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Class Specification file for Opendeck. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef OPENDECK_HPP
#define OPENDECK_HPP
#include <string>
#include "Space.hpp"

//Defines the interface of the Opendeck Class.
class Opendeck: public Space{
private:
  //Declare private variables for Opendeck

public:

  //Constructors.
  Opendeck();
  //Member functions.

  //Mutators
  void setPlayer(int, int);
};
#endif
