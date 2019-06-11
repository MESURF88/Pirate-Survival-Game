
/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for PrintText. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef PRINTTEXT_HPP
#define PRINTTEXT_HPP
#include <string>


//Defines the interface of the PrintText Class.
class PrintText
{
public:
  std::string resumegame;
  //Constructors.
  PrintText();
  //member functions.
  void introduction();
  void gameOver();
  void fallOver();
  void success();
  void keyExamine();
  void doorExamine();
  void portholeExamine();
  void wheelFail();
  void mastExamine();
  void ropeExamine();
  void overlookExamine();
  void fixExamine();
  void pullExamine();
  void leverExamine();
  void deckExamine();
  void windGusts();
  void acceptInfo();
};
#endif
