/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  05/31/2019
** Description: Implementation file for GameControl.
*******************************************************************************/

#include "GameControl.hpp"
#include "inputValidateMenu.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include <iostream>
#include <string>
#include <vector>//For settings and inventory
#include <cstdlib>
#include <ctime>



//Default Constructor.
GameControl::GameControl()
{
  //Initial general control variables
  in_session = 1;
  function_select = 0;
  steps = 0;
  step_limit = 55;
  f_x = 0;
  rope_attached = 0;
  wind_gust = 0;
  anchor_dropped = 0;
  resumeplay = " ";
  //Initial setting and action data
  in_bounds_act = 0;
  open = 0;
  //Initial player data
  move = 0;
  //index 0 setting, index 1, row, index 2 column
  player_data[0] = 0; player_data[1] = 0; player_data[2] = 0;
  //Initialize inventory variables
  get = 0;

  //Start program
  initializeInventory();
  initializeMap();
  printer.introduction();
  start();
}

GameControl::~GameControl()
{
  //free up memory
  //remove pointers in vector to free up memory.
  for (int i=0; i<settings.size(); i++)
  {
    delete (settings.at(i));
  }
  settings.clear();
  for (int i=0; i<inventory.size(); i++)
  {
    delete (inventory.at(i));
  }
  inventory.clear();
}

/************************************************
*             accept                            *
*This function requests the user to press any   *
*button to continue.                            *
************************************************/
void GameControl::accept()
{
  resumeplay = " ";
  std::cout<<"\n"<<"Press the Enter key to continue";
  getline(std::cin, resumeplay);
}

/************************************************
*             requestInputs                     *
*This function asks the user to choose an option*
*from the menu. The function can move the player*
*using character inputs or quit the game.       *
************************************************/
int GameControl::requestInputs()
{
  move = 0;
  function_select = 0;

  std::cout<<"\n"<<std::endl;
  std::cout<<"Would you like to move?"<<"\n"<<std::endl;
  std::cout<<"Enter w for up, a for left, s for down and d for right."<<"\n"<<std::endl;
  std::cout<<"Enter q to quit the game. After letter, press enter."<<"\n"<<std::endl;
  while (function_select == 0)
  {
    getline(std::cin,user_input1);
    if (user_input1 == "w")
    {
      move = 1;//up
      function_select = move;
    }
    if (user_input1 == "a")
    {
      move = 2;//left
      function_select = move;
    }
    if (user_input1 == "s")
    {
      move = 3;//down
      function_select = move;
    }
    if (user_input1 == "d")
    {
      move = 4;//right
      function_select = move;
    }
    if (user_input1 == "q")
    {//user quits game to main menu
      function_select = 5;
    }
    if (function_select == 0)
    {//Invalid input.
      move = 0;
      std::cout<<"Invalid input. Try again."<<std::endl;
    }
  }
  return function_select;
}

/************************************************
*             requestActionObject               *
*This function asks the user to choose an option*
*from the menu. The function allows player to   *
*Look at item bringing up text or leave.        *
************************************************/
int GameControl::requestActionObject()
{
  function_select = 0;

  std::cout<<"\n"<<std::endl;
  std::cout<<"Would you like to inspect the object?"<<"\n"<<std::endl;
  std::cout<<"1. Examine"<<"\n"<<std::endl;
  std::cout<<"2. Leave"<<"\n"<<std::endl;
  function_select = inputValidateMenu(1,2);
  return function_select;

}

/************************************************
*             initializeInventory               *
*This function initializes the inventory.       *
************************************************/
void GameControl::initializeInventory()
{
  Item* item1 = new Item;
  inventory.push_back(item1);
  Item* item2 = new Item;
  inventory.push_back(item2);
}

/************************************************
*             initializeMap                     *
*This function initializes the map spaces with  *
*the children of Space class. A total of 6 child*
*nodes are linked.                              *
************************************************/
void GameControl::initializeMap()
{
  //Galley, setting 0
  Galley* gal = new Galley;
  //move player to galley initially
  player = gal;
  settings.push_back(gal);
  gal->left = NULL;
  gal->bottom = NULL;
  gal->right = NULL;
  //Hall, setting 1
  Hall* hall = new Hall;
  settings.push_back(hall);
  hall->left = NULL;
  hall->bottom = gal;
  hall->right = NULL;
  gal->top = hall;
  //Maindeck, setting 2
  Maindeck* main = new Maindeck;
  settings.push_back(main);
  main->left = NULL;
  main->bottom = hall;
  main->right = NULL;
  hall->top = main;
  //Hall number 2, setting 3
  Hall* hall2 = new Hall;
  settings.push_back(hall2);
  //Modify parameters to make different form hall 1
  hall2->setSetting(3);
  hall2->setPlayer(4,1);
  hall2->setElement(5,4,'-');
  hall2->setElement(5,1,'D');
  hall2->left = NULL;
  hall2->bottom = main;
  hall2->right = NULL;
  main->top = hall2;
  //Bowsprit, setting 4
  Bowsprit* bow = new Bowsprit;
  settings.push_back(bow);
  bow->top = NULL;
  bow->bottom = hall2;
  bow->right = NULL;
  hall2->top = bow;
  //Opendeck, setting 5
  Opendeck* open = new Opendeck;
  settings.push_back(open);
  open->top = NULL;
  open->bottom = NULL;
  open->right = bow;
  open->left = NULL;
  bow->left = open;
  //6 settings total

  //setup player location at setting 0, row 4, column 4
  player_data[0] = 0;
  player_data[1] = 4;
  player_data[2] = 4;

  //seed the random  number generator
  srand(time(0));
}

/************************************************
*             printMap                          *
*This function prints the location of the player*
*and surroundings of the deck of the ship. Using*
*ASCII characters.                              *
************************************************/
void GameControl::printMap()
{
  for (int i=0; i<settings.at(player_data[0])->getRowLen(); i++)
  {
    for (int j=0; j<settings.at(player_data[0])->getColLen(); j++)
    {
      std::cout<<settings.at(player_data[0])->getElement(i,j);
      std::cout<<' ';
    }
    if(i==0)
    {//Print inventory list
      std::cout<<'\t'<<"Inventory:";
    }
    if(i==1)
    {
      std::cout<<'\t'<<"Item 1: ";inventory.at(0)->display();
    }
    if(i==2)
    {
      std::cout<<'\t'<<"Item 2: ";inventory.at(1)->display();
    }
    std::cout<<std::endl;
  }
}

/************************************************
*             inclementWind                     *
*This function randomly by a chance of 25% blows*
*the ship with a wind gust. The step_limit is   *
*decreased by 5 each call of this function.     *
************************************************/
void GameControl::inclementWind()
{
  wind_gust = (rand()%99)+1;
  if ((step_limit-steps) > 6 && wind_gust>90)
  {
      printer.windGusts();
      //decrease step limit by 5
      step_limit-=5;
  }
}

/************************************************
*             interaction                       *
*This function prints the objects the player    *
*is currently examining and after asks it user  *
*wants to pick it up into inventory. Also       *
*Displays menu for user to enter doors.         *
************************************************/
void GameControl::interaction()
{

f_x = requestActionObject();
  if (f_x == 1)
  {
    //Galley, setting 0
    if(player_data[0] == 0)
    {
      if(in_bounds_act == 2 && inventory.at(0)->getActive() != 1)
      {
        get = 0;
        printer.keyExamine();
        std::cout<<"Would you like to pick up the object?"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        get = inputValidateMenu(1,2);
        if (get == 1)
        {
          //choose to pick up item
          inventory.at(0)->setDisplay("MasterKey");
          //set corner to empty pedestal
          settings.at(0)->setElement(1,1,'O');
        }
      }
      else if(in_bounds_act == 2)
      {
        std::cout<<"\n"<<"An empty pedestal."<<"\n"<<std::endl;
        accept();
      }
    }
    //Hall, setting 1 and 3
    if(player_data[0] == 1 || player_data[0] == 3)
    {
      if(in_bounds_act == 2)
      {
        //shows amount of time left
        printer.portholeExamine();
        std::cout<<step_limit-steps<<" ticks until impact."<<"\n"<<std::endl;
        accept();
      }
    }
    //Maindeck, setting 2
    if(player_data[0] == 2)
    {
      //Wheel
      if(in_bounds_act == 2 && player_data[1] == 3 && player_data[2] == 2)
      {
        if (rope_attached == 1)
        {
          //Successfully completed game exit to main menu
          printer.success();
          in_session = 0;
          step_limit = 100;
        }
        else
        {
          printer.wheelFail();
        }
      }
      else if(in_bounds_act == 2)
      {
        //Mast
        if (inventory.at(1)->getActive() == 1 && rope_attached == 0)
        {
          get = 0;
          std::cout<<"\n"<<"Noticing, the rope you hold, you get an idea to steady the mast."<<std::endl;
          std::cout<<"Would you like to replace the rope"<<"\n"<<std::endl;
          std::cout<<"1. Yes"<<"\n"<<std::endl;
          std::cout<<"2. No"<<"\n"<<std::endl;
          get = inputValidateMenu(1,2);
          if (get == 1)
          {
            printer.fixExamine();
            //remove rope from inventory
            inventory.at(1)->setDisplay(" ");
            rope_attached = 1;
          }
        }
        else if (rope_attached == 1)
        {
          std::cout<<"\n"<<"The rope is securely attached. The sail is full."<<std::endl;
        }
        else
        {
          printer.mastExamine();
        }
      }
    }
    //Bowsprit, setting 4
    if(player_data[0] == 4)
    {
      if(in_bounds_act == 2 && inventory.at(1)->getActive() != 1 && player_data[2] != 1)
      {
        get = 0;
        printer.ropeExamine();
        std::cout<<"Would you like to pick up the object?"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        get = inputValidateMenu(1,2);
        if (get == 1)
        {
          //choose to pick up item
          inventory.at(1)->setDisplay("Rope");
          //set corner to hook
          settings.at(4)->setElement(1,4,'X');
        }
      }
      else if(in_bounds_act == 2 && player_data[2] != 1)
      {
        std::cout<<"\n"<<"An empty hook."<<"\n"<<std::endl;
        accept();
      }
      if(in_bounds_act == 2 && player_data[2] == 1)
      {
        open = 0;
        printer.overlookExamine();
        std::cout<<"Would you like to climb the rail"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        open = inputValidateMenu(1,2);
        if (open == 1)
        {
          //choose to cross into next area.
          transistionUp();
          //avoid door prompts
          in_bounds_act = 0;
        }
      }
    }
    //Opendeck, setting 5
    if(player_data[0] == 5)
    {
      if(in_bounds_act == 2 && anchor_dropped == 0 && player_data[2] == 3)
      {
        get = 0;
        printer.leverExamine();
        std::cout<<"Would you pull the lever?"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        get = inputValidateMenu(1,2);
        if (get == 1)
        {
          printer.pullExamine();
          //choose to pull the lever
          anchor_dropped = 1;
          //increase step_limit
          step_limit+=15;
        }
      }
      else if(in_bounds_act == 2 && anchor_dropped == 1 && player_data[2] == 3)
      {
        std::cout<<"\n"<<"The lever is lodged in place. The anchor has been released"<<"\n"<<std::endl;
        accept();
      }
      if(in_bounds_act == 2 && player_data[2] == 4)
      {
        open = 0;
        printer.deckExamine();
        std::cout<<"Would you like to climb the rail"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        open = inputValidateMenu(1,2);
        if (open == 1)
        {
          //choose to cross into previous area.
          transistionDown();
          //avoid door prompts
          in_bounds_act = 0;
        }
      }
    }
    //Door triggers
    if (in_bounds_act == 3)
    {
      open = 0;
      printer.doorExamine();
      if (inventory.at(0)->getActive() == 1)
      {//If key active open door and move to Door space
        std::cout<<"Would you like to open the door?"<<"\n"<<std::endl;
        std::cout<<"1. Yes"<<"\n"<<std::endl;
        std::cout<<"2. No"<<"\n"<<std::endl;
        open = inputValidateMenu(1,2);
        if (open == 1)
        {
          if (player_data[1] == 1)
          {
            //choose to open door up into next area.
            transistionUp();
          }
          else if(player_data[1] == 4)
          {
            //choose to open door down into next area.
            transistionDown();
          }
        }
      }
    }
  }

}

/************************************************
*             transistionUp                     *
*This function simply moves the player through  *
*a door. moving up through the settings.        *
************************************************/
void GameControl::transistionUp()
{
  //if adjacent look to the left node instead of top
  if (player->left!=NULL)
  {
    //go to next setting.
    player = player->left;
    player_data[0] = player->getSetting();
    player_data[1] = player->getPlayerRow();
    player_data[2] = player->getPlayerCol();
  }
  else
  {
    //go to next setting.
    player = player->top;
    player_data[0] = player->getSetting();
    player_data[1] = player->getPlayerRow();
    player_data[2] = player->getPlayerCol();
  }
}

/************************************************
*             transistionDown                   *
*This function simply moves the player through  *
*a door. moving down through the settings.      *
************************************************/
void GameControl::transistionDown()
{
  //if adjacent look to the right node instead of bottom
  if (player->right!=NULL)
  {
    //go to next setting.
    player = player->right;
    player_data[0] = player->getSetting();
    player_data[1] = player->getPlayerRow();
    player_data[2] = player->getPlayerCol();
  }
  else
  {
      //go to next setting.
      player = player->bottom;
      player_data[0] = player->getSetting();
      player_data[1] = player->getPlayerRow();
      player_data[2] = player->getPlayerCol();
  }
}

/************************************************
*             start                             *
*This function asks the user to choose an option*
*from the menu. then executes the function.     *
*Continues running until user quits to main menu*
************************************************/
void GameControl::start()
{
  while (in_session == 1)
  {
    printMap();
    inclementWind();
    //Request user to enter choice for function or to quit.
    f_x = requestInputs();
    //player movement
    if (move == 1)
    {
      //move player up if allowed by setting
      if(check.upCheck(player_data))
      {
        settings.at(player_data[0])->setPlayer(settings.at(player_data[0])->getPlayerRow()-1,settings.at(player_data[0])->getPlayerCol());
        player_data[1] = settings.at(player_data[0])->getPlayerRow();
        player_data[2] = settings.at(player_data[0])->getPlayerCol();
        steps++;
      }
    }
    if (move == 2)
    {
      //move player left if allowed by setting
      if(check.leftCheck(player_data))
      {
        settings.at(player_data[0])->setPlayer(settings.at(player_data[0])->getPlayerRow(),settings.at(player_data[0])->getPlayerCol()-1);
        player_data[1] = settings.at(player_data[0])->getPlayerRow();
        player_data[2] = settings.at(player_data[0])->getPlayerCol();
        steps++;
      }
    }
    if (move == 3)
    {
      //move player down if allowed by setting
      if(check.downCheck(player_data))
      {
        settings.at(player_data[0])->setPlayer(settings.at(player_data[0])->getPlayerRow()+1,settings.at(player_data[0])->getPlayerCol());
        player_data[1] = settings.at(player_data[0])->getPlayerRow();
        player_data[2] = settings.at(player_data[0])->getPlayerCol();
        steps++;
      }
    }
    if (move == 4)
    {
      //move player right if allowed by setting
      if(check.rightCheck(player_data))
      {
        settings.at(player_data[0])->setPlayer(settings.at(player_data[0])->getPlayerRow(),settings.at(player_data[0])->getPlayerCol()+1);
        player_data[1] = settings.at(player_data[0])->getPlayerRow();
        player_data[2] = settings.at(player_data[0])->getPlayerCol();
        steps++;
      }
    }
    std::cout<<std::endl;
    //quit game
    if (f_x == 5)
    {
      in_session = 0;
    }
    if (f_x != 5)
    {
      //after movement check surroundings to see if player is by interaction
      in_bounds_act = check.locationCheck(player_data);
      //check to see if nearby object
      if (in_bounds_act == 2){
        printMap();
        interaction();
      }
      //check to see if nearby door
      if (in_bounds_act == 3){
        printMap();
        interaction();
      }
      //check if in water
      if (in_bounds_act == 4)
      {
        printer.fallOver();
        in_session = 0;
      }
    }

    //end game if steps reached
    if (steps>step_limit)
    {
      printer.gameOver();
      in_session = 0;
    }
  }
}
