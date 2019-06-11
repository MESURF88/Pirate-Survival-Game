/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Implementation file for Galley class. Sets and gets Galley
** objects. Has polymorphic function that sets player location.
******************************************************************************/


#include <iostream>
#include <string>
#include "Galley.hpp"

//Default Constructor.
Galley::Galley(): Space()
{
  setSetting(0);
  setRowLen(6);
  setColLen(6);
  //Initialize ASCII character grid
  for (int i=0; i<getRowLen(); i++)
  {
    for (int j=0; j<getColLen(); j++)
    {
      if (i==0 || i==getRowLen()-1)
      {
        setElement(i,j,'-');
      }
      else if (j==0 || j==getColLen()-1)
      {
        setElement(i,j,'|');
      }
      else
      {
        setElement(i,j,'#');
      }
    }
  }
  //Set the interactions in the setting
  setElement(0,4,'D');
  setElement(1,1,'K');
  //Place player marker intially
  setPlayerRow(4);
  setPlayerCol(4);
  setPlayer(getPlayerRow(),getPlayerCol());
}

/************************************************
*               setPlayer                       *
*This polymorphic function sets the player in   *
*the next space and removes the old player      *
*It takes the integers row and column and puts  *
*the player in that location.                   *
************************************************/
void Galley::setPlayer(int row, int col)
{
  //place blank floor at original position
  setElement(getPlayerRow(),getPlayerCol(),'#');
  //move player to new space
  setElement(row,col,'P');
  setPlayerRow(row);
  setPlayerCol(col);
}
