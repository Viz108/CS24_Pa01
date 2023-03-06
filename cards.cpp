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
    // list.printInOrder();
    // cout << endl; 
    int currCard = getFirstCard();

    while(currCard != 0)
    {
        if(currCard >= 1 && currCard <= 13) //club
        {
          cout << "c ";
          if(currCard == 11) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 0 << endl; 
          }
        }
        else if(currCard >= 14 && currCard <= 26) //diamond
        {
          cout << "d ";
          if(currCard == 11 + 13) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 13) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 13) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 13) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 13 << endl; 
          }
        }
        else if(currCard >= 27 && currCard <= 39) //spade
        {
          cout << "s ";
          if(currCard == 11 + 26) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 26) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 26) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 26) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 26 << endl; 
          }
        }
        else if(currCard >= 40 && currCard <= 52) //heart
        {
          cout << "h ";
          if(currCard == 11 + 39) //jack
          {
            cout << "j" << endl;
          }
          else if(currCard == 12 + 39) //queen
          {
            cout << "q" << endl;
          }
          else if(currCard == 13 + 39) //king
          {
            cout << "k" << endl;
          }
          else if(currCard == 1 + 39) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << currCard - 39 << endl; 
          }
        }

        currCard = getNextCard(currCard);
    }
}

int cards :: getFirstCard()
{
    for(int i = 0; i <= 52; i++)
    {
        if(list.contains(i))
        {
            return i; 
        }
    }
    return 0;
}

int cards :: getLastCard()
{
    for(int i = 52; i >= 0; i--)
    {
        if(list.contains(i))
        {
            return i;
        }
    }
    return 0;
}

int cards :: getNextCard(int cardValue)
{
    return list.getSuccessor(cardValue);
}

int cards :: getPreviousCard(int cardValue)
{
    return list.getPredecessor(cardValue);
}

bool cards :: containsCard(int cardValue)
{
    return list.contains(cardValue);
}

bool cards :: removeCard(int cardValue)
{
    return list.remove(cardValue);
}



