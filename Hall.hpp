/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for Hall. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef HALL_HPP
#define HALL_HPP
#include <string>
#include "Space.hpp"

//Defines the interface of the Hall Class.
class Hall: public Space{
private:
  //Declare private variables for Hall

public:

  //Constructors.
  Hall();
  //Member functions.

  //Mutators
  void setPlayer(int, int);
};
#endif
