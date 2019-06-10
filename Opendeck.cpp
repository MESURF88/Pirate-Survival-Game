/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Implementation file for Opendeck class. Sets and gets Opendeck
** objects. Has polymorphic function that sets player location.
******************************************************************************/


#include <iostream>
#include <string>
#include "Opendeck.hpp"

//Default Constructor.
Opendeck::Opendeck(): Space()
{
  setSetting(5);
  setRowLen(6);
  setColLen(6);
  //Initialize character grid
  for (int i=0; i<getRowLen(); i++)
  {
    for (int j=0; j<getColLen(); j++)
    {
      if (i==0 || i==getRowLen()-1)
      {
        if (j<2)
        {
          setElement(i,j,' ');
        }
        else
        {
          setElement(i,j,'-');
        }
      }
      else if (j==getColLen()-1)
      {
        setElement(i,j,'|');
      }
      else
      {
        if (j<2)
        {
          setElement(i,j,' ');
        }
        else
        {
          setElement(i,j,'#');
        }
      }
    }
  }
  setElement(1,2,'A');
  setElement(1,5,'=');
  //Place character marker intially
  setPlayerRow(1);
  setPlayerCol(4);
  setPlayer(getPlayerRow(),getPlayerCol());
}

void Opendeck::setPlayer(int row, int col)
{
  //place blank floor at original position
  setElement(getPlayerRow(),getPlayerCol(),'#');
  //move character to new space
  setElement(row,col,'P');
  setPlayerRow(row);
  setPlayerCol(col);
}
