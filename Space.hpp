
/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for Space. Declares variables.
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

//Defines the interface of the Space class.
class Space
{
  private:
    int stride_row;
    int stride_col;
    char board[6][6];
    int player_row;
    int player_col;
    int setting_num;
  protected:

  public:
    Space();
    //Pointers to nodes
    Space* left;
    Space* right;
    Space* top;
    Space* bottom;
    //mutators
    void setSetting(int);
    virtual void setPlayer(int,int);
    void setRowLen(int);
    void setColLen(int);
    void setElement(int,int,char);
    void setPlayerRow(int);
    void setPlayerCol(int);
    //accessors
    int getSetting();
    int getRowLen();
    int getColLen();
    int getPlayerRow();
    int getPlayerCol();
    char getElement(int,int);


};
#endif
