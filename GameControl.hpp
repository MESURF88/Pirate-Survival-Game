
/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  06/10/2019
** Description: Class Specification file for GameControl. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP
#include <string>
#include <vector>
#include "Space.hpp"
#include "Galley.hpp"
#include "Hall.hpp"
#include "Maindeck.hpp"
#include "Bowsprit.hpp"
#include "Opendeck.hpp"
#include "Item.hpp"
#include "PrintText.hpp"
#include "LocHandler.hpp"


//Defines the interface of the GameControl Class.
class GameControl
{
private:
  //Declare private variables for GameControl
  //General game flow variables
  int in_session;
  int function_select;
  int steps;
  int step_limit;
  int f_x;
  int wind_gust;
  int rope_attached;
  int anchor_dropped;
  std::string resumeplay;

  //player variable holds position data in game
  int player_data[3];
  //player movement variables
  int move;
  int open;
  int in_bounds_act;
  std::string user_input1;

  //Declare vector of linked list of space nodes
  std::vector<Space*> settings;
  //Player points to specific setting in game
  Space *player;

  //Declare vector of inventory items
  std::vector<Item*> inventory;
  int get;

  //print text object initialization
  PrintText printer;
  //determine location of player object to see if in bounds or near interaction
  LocHandler check;
public:
  //Constructors.
  GameControl();
  //Desructors.
  ~GameControl();
  //member functions.
  void initializeInventory();
  void initializeMap();
  void printMap();
  void interaction();
  void inclementWind();
  void transistionUp();
  void transistionDown();
  int requestInputs();
  int requestActionObject();
  void accept();
  void start();
};
#endif
