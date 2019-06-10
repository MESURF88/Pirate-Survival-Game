/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/09/2019
** Description: Implementation file for LocHandler class. Sets and gets
** LocHandler objects.
******************************************************************************/


#include <iostream>
#include <string>
#include "LocHandler.hpp"

//Default Constructor.
LocHandler::LocHandler()
{

}

/************************************************
*             locationCheck                     *
*This function takes in the player_data array   *
*and checks if it is within bounds of respective*
*setting. If not returns 0 and player doesn't   *
*move. If within bounds then returns 1, and if  *
*next to object that requires action return 2.  *
*If next to door return 3. If in water return 4.*
************************************************/
int LocHandler::locationCheck(const int *player_arr)
{
  //Galley
  if (player_arr[0] == 0)
  {
    if ((player_arr[1] == 2 && player_arr[2] == 1) || (player_arr[1] == 1 && player_arr[2] == 2))
    {
      return 2;
    }
    if (player_arr[1] == 1 && player_arr[2] == 4)
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  //Hall 1
  if (player_arr[0] == 1)
  {
    if (player_arr[1] == 3 && player_arr[2] == 4)
    {
      return 2;
    }
    if ((player_arr[1] == 1 && player_arr[2] == 4) || (player_arr[1] == 4 && player_arr[2] == 4))
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  //Maindeck
  if (player_arr[0] == 2)
  {
    if ((player_arr[1] == 3 && player_arr[2] == 2) ||
    (player_arr[1] == 3 && player_arr[2] == 3) ||
    (player_arr[1] == 2 && player_arr[2] == 2) ||
    (player_arr[1] == 1 && player_arr[2] == 3) ||
    (player_arr[1] == 2 && player_arr[2] == 4))
    {
      return 2;
    }
    if ((player_arr[1] == 1 && player_arr[2] == 1) || (player_arr[1] == 4 && player_arr[2] == 4))
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  //Hall 2
  if (player_arr[0] == 3)
  {
    if (player_arr[1] == 3 && player_arr[2] == 4)
    {
      return 2;
    }
    if ((player_arr[1] == 1 && player_arr[2] == 4) || (player_arr[1] == 4 && player_arr[2] == 1))
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  //Bowsprit
  if (player_arr[0] == 4)
  {
    if ((player_arr[1] == 2 && player_arr[2] == 4) || (player_arr[1] == 1 && player_arr[2] == 3) || (player_arr[1] == 1 && player_arr[2] == 1))
    {
      return 2;
    }
    if (player_arr[1] == 4 && player_arr[2] == 4)
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  //Opendeck
  if (player_arr[0] == 5)
  {
    if ((player_arr[1] == 1 && player_arr[2] == 3) || (player_arr[1] == 2 && player_arr[2] == 2) || (player_arr[1] == 1 && player_arr[2] == 4))
    {
      return 2;
    }
    if (player_arr[2] == 1)
    {
      return 4;
    }
    else
    {
      return 1;
    }
  }
}

/************************************************
*             upCheck                           *
*This function takes in the player_data array   *
*and checks if it is within bounds of respective*
*setting. If not returns 0 and player doesn't   *
*move up. If within bounds then returns 1.      *
************************************************/
int LocHandler::upCheck(const int *player_arr)
{
  if (player_arr[1] == 1)
  {
    return 0;
  }
  else
  {
    if (player_arr[0] == 0)
    {
      if (player_arr[1] == 2 && player_arr[2] == 1)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 2)
    {
      if (player_arr[1] == 3 && player_arr[2] == 3)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 4)
    {
      if (player_arr[1] == 2 && player_arr[2] == 4)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 5)
    {
      if (player_arr[1] == 2 && player_arr[2] == 2)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }
}

/************************************************
*             leftCheck                         *
*This function takes in the player_data array   *
*and checks if it is within bounds of respective*
*setting. If not returns 0 and player doesn't   *
*move left. If within bounds then returns 1.    *
************************************************/
int LocHandler::leftCheck(const int *player_arr)
{
  if (player_arr[2] == 1)
  {
    return 0;
  }
  else
  {
    if (player_arr[0] == 0)
    {
      if (player_arr[1] == 1 && player_arr[2] == 2)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 2)
    {
      if ((player_arr[1] == 2 && player_arr[2] == 4) || (player_arr[1] == 4 && player_arr[2] == 3))
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 5)
    {
      if (player_arr[1] == 1 && player_arr[2] == 3)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }
}


/************************************************
*            downCheck                          *
*This function takes in the player_data array   *
*and checks if it is within bounds of respective*
*setting. If not returns 0 and player doesn't   *
*move down. If within bounds then returns 1.    *
************************************************/
int LocHandler::downCheck(const int *player_arr)
{
  if (player_arr[1] == 4)
  {
    return 0;
  }
  else
  {
    if (player_arr[0] == 0)
    {
      if (player_arr[1] == 5 && player_arr[2] == 5)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 2)
    {
      if ((player_arr[1] == 3 && player_arr[2] == 2) || (player_arr[1] == 1 && player_arr[2] == 3))
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }
}

/************************************************
*             rightCheck                        *
*This function takes in the player_data array   *
*and checks if it is within bounds of respective*
*setting. If not returns 0 and player doesn't   *
*move right. If within bounds then returns 1.   *
************************************************/
int LocHandler::rightCheck(const int *player_arr)
{
  if (player_arr[2] == 4)
  {
    return 0;
  }
  else
  {
    if (player_arr[0] == 0)
    {
      if (player_arr[1] == 5 && player_arr[2] == 5)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 2)
    {
      if ((player_arr[1] == 2 && player_arr[2] == 2) || (player_arr[1] == 4 && player_arr[2] == 1))
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
    if (player_arr[0] == 4)
    {
      if (player_arr[1] == 1 && player_arr[2] == 3)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }
  }
}
