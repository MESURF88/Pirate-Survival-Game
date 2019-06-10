/******************************************************************************
** Program name: FinalProject
** Author: Kevin Hill
** Date:  05/31/2019
** Description: Implementation file for PrintText.
*******************************************************************************/

#include "PrintText.hpp"
#include <iostream>
#include <string>


//Default Constructor.
PrintText::PrintText()
{
}

/************************************************
*             acceptInfo                        *
*This function requests the user to press any   *
*button to continue.                            *
************************************************/
void PrintText::acceptInfo()
{
  resumegame = " ";
  std::cout<<"\n"<<"Press the Enter key to continue";
  getline(std::cin, resumegame);
}


/************************************************
*             introduction                      *
*This function gives the user information on    *
*the scenario and goal of the game.             *
************************************************/
void PrintText::introduction()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<'\t'<<"Introduction:"<<std::endl;
  std::cout<<"You wake up to the sound of rain, ocean spray and thunder. There is a"<<"\n"<<std::endl;
  std::cout<<"feeling of dampness. Standing up you see you are on a wooden ship "<<"\n"<<std::endl;
  std::cout<<"with no signs of any other human life. The winds whips through a window"<<"\n"<<std::endl;
  std::cout<<"by you. It is immediately evident that a storm is steering the ship towards"<<"\n"<<std::endl;
  std::cout<<"towering rocks. Tall enough to surely sink it and you don't know how to swim."<<"\n"<<std::endl;
  std::cout<<"You must avoid this fate at all costs and stop or turn the ship away."<<"\n"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"As the sole person on the ship you are represented by, \'P\'"<<"\n"<<std::endl;
  std::cout<<"The edges of the ship are represented by, \'|\' and \'-\'"<<"\n"<<std::endl;
  std::cout<<"The inventory is displayed to the right of the map, can hold up to two items."<<"\n"<<std::endl;
  std::cout<<"Make the right decisions to complete the goal and survive."<<"\n"<<std::endl;
  std::cout<<"Map is displayed below:"<<"\n"<<std::endl;
}

/************************************************
*             gameOver                          *
*This function gives the user information       *
*about the game ending because they ran out of  *
*steps through movement and action.             *
************************************************/
void PrintText::gameOver()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<'\t'<<"Game Over!"<<std::endl;
  std::cout<<"You hear an ominous noise. A roaring wave pushes the vessel into the rocks"<<"\n"<<std::endl;
  std::cout<<"struggling to keep balance, you hear the boards of the bowsprit snap under"<<std::endl;
  std::cout<<"the force."<<"\n"<<std::endl;
  std::cout<<"It is only a matter of time until the ship sinks, better hope the water isn't."<<std::endl;
  std::cout<<"too cold."<<"\n"<<std::endl;
}

/************************************************
*             fallOver                          *
*This function gives the user information       *
*about the game ending because they ran out of  *
*steps through movement and action.             *
************************************************/
void PrintText::fallOver()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<'\t'<<"Game Over!"<<std::endl;
  std::cout<<"You have fallen over board. The water is frigid and drains your body."<<"\n"<<std::endl;
  std::cout<<"Here is to hoping you find floating debris before you run out of energy."<<"\n"<<std::endl;
}

/************************************************
*             success                           *
*This function gives the user information       *
*about the winning the game and the epilogue.   *
************************************************/
void PrintText::success()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<'\t'<<"Success!"<<std::endl;
  std::cout<<"You successfully turn the wheel of the ship to the right, with the mast's rope"<<"\n"<<std::endl;
  std::cout<<"holding. The vessel moves around the rocks and you breathe a sigh of relief."<<"\n"<<std::endl;
  std::cout<<"Looking out at the horizon, you see the edge of a beach with clouds parting to reveal a sunrise."<<"\n"<<std::endl;
}


/************************************************
*             keyExamine                        *
*This function gives the user information on    *
*the key item.                                  *
************************************************/
void PrintText::keyExamine()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<"You inspect a tall pedestal in the corner of the room with a key on it."<<"\n"<<std::endl;
  std::cout<<"Examining the key you observe the various scratches and wear around it."<<"\n"<<std::endl;
  std::cout<<"Upon further inspection, you see the letters spelling out master along the face."<<"\n"<<std::endl;
  std::cout<<"It is clear this key can be useful."<<"\n"<<std::endl;
  acceptInfo();
}

/************************************************
*             doorExamine                       *
*This function gives the user information on    *
*the doors in the ship.                         *
************************************************/
void PrintText::doorExamine()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<"You inspect a heavy oak door, with a rusted iron frame."<<"\n"<<std::endl;
  std::cout<<"A keyhole is located by the doorknob."<<"\n"<<std::endl;
}

/************************************************
*             portholeExamine                   *
*This function gives the user information on    *
*the outside of the ship. How close to crashing.*
************************************************/
void PrintText::portholeExamine()
{
  std::cout<<"\n"<<std::endl;
  std::cout<<"Starboard View"<<"\n"<<std::endl;
  std::cout<<"The raging ocean and rising swells are visible from the porthole."<<"\n"<<std::endl;
  std::cout<<"in the distance you see the towering rocks about, ";
}

/************************************************
*             wheelFail                         *
*This function gives the user information on    *
*the the wheel and clues to continue.           *
************************************************/
void PrintText::wheelFail()
{
  std::cout<<"\n"<<"You see a wheel and brace yourself to steer. To possibly avoid the rocks."<<"\n"<<std::endl;
  std::cout<<"You strain but it is impossible to spin, The wind buffets head on."<<"\n"<<std::endl;
  std::cout<<"You observe your surroundings and see the sail luffing on the mast."<<"\n"<<std::endl;
  acceptInfo();
}

/************************************************
*             mastExamine                       *
*This function gives the user information on    *
*the mast and the issues with the rope on it.   *
************************************************/
void PrintText::mastExamine()
{
  std::cout<<"\n"<<"You see the mast. Covered in ropes and nets. Its sail luffing in the storm."<<"\n"<<std::endl;
  std::cout<<"Examining closer, the rope is loose on the bottom hook. The line fraying off."<<"\n"<<std::endl;
  acceptInfo();
}

/************************************************
*             ropeExamine                       *
*This function gives the user information on    *
*the rope by the end of the ship.               *
************************************************/
void PrintText::ropeExamine()
{
  std::cout<<"\n"<<"Upon inspection you see a rack with a braided rope wrapped around."<<"\n"<<std::endl;
  std::cout<<"You lift it and pull it to test its strength. The rope does not fray."<<"\n"<<std::endl;
  acceptInfo();
}

/************************************************
*             overlookExamine                   *
*This function gives the user information on    *
*the overlook to the open deck                  *
************************************************/
void PrintText::overlookExamine()
{
  std::cout<<"\n"<<"You see a perilous overlook out into the ocean."<<"\n"<<std::endl;
  std::cout<<"Listening closely you hear the clattering of heavy chains"<<"\n"<<std::endl;
  std::cout<<"as the boat ebbs and flows."<<"\n"<<std::endl;
}

/************************************************
*             fixExamine                        *
*This function gives the user information on    *
*how the player fixes the frayed rope.          *
************************************************/
void PrintText::fixExamine()
{
  std::cout<<"\n"<<"Using all you might you ascend the mast, carrying the braided"<<"\n"<<std::endl;
  std::cout<<"rope with you. The rope is heavy but you manage to continue."<<"\n"<<std::endl;
  std::cout<<"The wind gusts without respite and your footing begins to slip."<<"\n"<<std::endl;
  std::cout<<"The ship ebbs forward and gravity takes you into the net of the topsail."<<"\n"<<std::endl;
  std::cout<<"You are disoriented but persevere and crawl up to the top hook, still"<<"\n"<<std::endl;
  std::cout<<"holding the braided rope. You undo the top hook with numb hands and"<<"\n"<<std::endl;
  std::cout<<"fix on the new braided rope. You make your way down as the rain beats on"<<"\n"<<std::endl;
  std::cout<<"without remorse. You complete the journey to the deck and tie the second hook."<<"\n"<<std::endl;
  std::cout<<"Standing on weak legs, you are exhausted but you get a second wind and"<<"\n"<<std::endl;
  std::cout<<"move forward. The rope is fixed."<<"\n"<<std::endl;
  acceptInfo();
}


/************************************************
*             pullExamine                       *
*This function gives the user information on    *
*how the player releases the anchor.            *
************************************************/
void PrintText::pullExamine()
{
  std::cout<<"\n"<<"You grab ahold of the lever and use you body weight to force the lever."<<"\n"<<std::endl;
  std::cout<<"At first it doesn't budge. The rusty chain grinds against the iron tumbler."<<"\n"<<std::endl;
  std::cout<<"You observe that there are threads of twine stuck in the gears of the tumbler."<<"\n"<<std::endl;
  std::cout<<"You decide to use brute force and yank the lever with all your strength."<<"\n"<<std::endl;
  std::cout<<"At the same time the ship rocks back and a substantial wave crashes into the"<<"\n"<<std::endl;
  std::cout<<"anchor, making the gears of the tumbler spin. This releases the anchor."<<"\n"<<std::endl;
  std::cout<<"It drops into the ocean and jolts the ship to a halt."<<"\n"<<std::endl;
  std::cout<<"Then the lever lodges in place. This knocks you back to your feet,"<<"\n"<<std::endl;
  std::cout<<"and as you stand up you realize the chain has only dropped halfway"<<"\n"<<std::endl;
  std::cout<<"the ship lethargically begins to pick up speed resuming its course."<<"\n"<<std::endl;
  std::cout<<"You have increased the time to impact by 15 ticks."<<"\n"<<std::endl;
  acceptInfo();
}

/************************************************
*             leverExamine                      *
*This function gives the user information on    *
*how the player inspects the lever.             *
************************************************/
void PrintText::leverExamine()
{
  std::cout<<"\n"<<"You see a rusty lever connected to a tumbler and chain."<<"\n"<<std::endl;
  std::cout<<"Leading to sizeable anchor hanging down from the port side of the ship."<<"\n"<<std::endl;
}

/************************************************
*             deckExamine                       *
*This function gives the user information on    *
*how the inspects the deck.                     *
************************************************/
void PrintText::deckExamine()
{
  std::cout<<"\n"<<"You see a the deck of the ship over the wooden rail."<<"\n"<<std::endl;
}

/************************************************
*             windGusts                         *
*This function gives the user information on    *
*how the ship is affected by the wind.          *
************************************************/
void PrintText::windGusts()
{
  std::cout<<"\n"<<"A fierce wind gust hits the port side of the ship,"<<"\n"<<std::endl;
  std::cout<<"\n"<<"It momentarily fills the sails and thrusts the ship at an"<<"\n"<<std::endl;
  std::cout<<"\n"<<"accelerated speed. The time to impact has decreased by 5."<<"\n"<<std::endl;
  acceptInfo();
}
