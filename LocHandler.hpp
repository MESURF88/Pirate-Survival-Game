/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for LocHandler. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef LOCHANDLER_HPP
#define LOCHANDLER_HPP
#include <string>
#include "LocHandler.hpp"

//Defines the interface of the LocHandler Class.
class LocHandler
{
private:
  //Declare private variables for LocHandler

public:

  //Constructors.
  LocHandler();
  //Member functions.
  int locationCheck(const int *);
  int upCheck(const int *);
  int leftCheck(const int *);
  int downCheck(const int *);
  int rightCheck(const int *);

};
#endif
