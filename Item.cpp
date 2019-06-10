/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/02/2019
** Description: Implementation file for Item class.
*******************************************************************************/

#include "Item.hpp"
#include <iostream>
#include <string>

Item::Item()
{
  active = 0;
  description = " ";
}

//mutators
//set description of item for inventory and activate for using doors.
void Item::setDisplay(std::string desc)
{
  description = desc;
  active = 1;
}

//accessors
void Item::display()
{
  std::cout<<description;
}

int Item::getActive()
{
  return active;
}
