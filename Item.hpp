
/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for Item. Declares variables.
******************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

//Defines the interface of the Item class.
class Item
{
private:
  //Declare Item private variables
  int active;
  std::string description;

public:
  //constructor
  Item();
  //mutators
  void setDisplay(std::string);
  //accessors
  void display();
  int getActive();
  void use();

};
#endif
