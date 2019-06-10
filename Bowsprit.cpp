/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Implementation file for Bowsprit class. Sets and gets Bowsprit
** objects. Has polymorphic function that sets player location.
******************************************************************************/


#include <iostream>
#include <string>
#include "Bowsprit.hpp"

//Default Constructor.
Bowsprit::Bowsprit(): Space()
{
  setSetting(4);
  setRowLen(6);
  setColLen(6);
  //Initialize character grid
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
  setElement(5,4,'D');
  setElement(1,4,'R');
  setElement(1,0,'=');
  //Place character marker intially
  setPlayerRow(4);
  setPlayerCol(4);
  setPlayer(getPlayerRow(),getPlayerCol());
}

void Bowsprit::setPlayer(int row, int col)
{
  //place blank floor at original position
  setElement(getPlayerRow(),getPlayerCol(),'#');
  //move character to new space
  setElement(row,col,'P');
  setPlayerRow(row);
  setPlayerCol(col);
}
