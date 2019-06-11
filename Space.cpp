/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Implementation file for Space class.
*******************************************************************************/

#include "Space.hpp"
#include <iostream>

Space::Space()
{
  //make pointers to next spaces NULL
  left = NULL;
  right = NULL;
  bottom = NULL;
  top = NULL;
}

//mutators
void Space::setSetting(int num)
{
  setting_num = num;
}

void Space::setElement(int row, int col, char disp)
{
  board[row][col] = disp;
}

void Space::setColLen(int col)
{
  stride_col = col;
}

void Space::setRowLen(int row)
{
  stride_row = row;
}

void Space::setPlayerRow(int row)
{
  player_row = row;
}

void Space::setPlayerCol(int col)
{
  player_col = col;
}

//accessors
int Space::getSetting()
{
  return setting_num;
}

int Space::getColLen()
{
  return stride_col;
}

int Space::getRowLen()
{
  return stride_row;
}

char Space::getElement(int row, int col)
{
  return board[row][col];
}

int Space::getPlayerRow()
{
  return player_row;
}

int Space::getPlayerCol()
{
  return player_col;
}

void Space::setPlayer(int,int){}
