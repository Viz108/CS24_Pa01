//cards.cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards.h

#include "cards.h"

cards :: cards()
{

}

void cards :: addCard(int cardValue)
{
    list.insert(cardValue);
}

void cards :: printCards()
{
    list.printInOrder();
    cout << endl; 
}