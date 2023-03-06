#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
//#include "intbst.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  cards deckA; 
  cards deckB; 


  while (getline (cardFile1, line) && (line.length() > 0)){
    int cardValue = 0;
    
    char suit = line.at(0);
    switch(suit) 
    {
      case 'c': //Clubs - 1-13
        cardValue += 1;
        break;
      case 'd': //Diamonds - 14-26
        cardValue += 14;
        break;
      case 's': //Spades - 27-39
        cardValue += 27;
        break;
      case 'h': //Hearts - 40-52
        cardValue += 40;
        break;
      default:
        cout << "ERROR: No suit, check input" << endl;
        break;
    }

    string cardNum; 
    for(int i = 2; i < line.length(); i++)
    {
      cardNum += line.at(i);
    }
    
    //Face cards
    if(cardNum.find('j') != -1) //jack
    {
      cardValue += 10;
    }
    else if(cardNum.find('q') != -1) //queen
    {
      cardValue += 11;
    }
    else if(cardNum.find('k') != -1) //king
    {
      cardValue += 12;
    }
    else if(cardNum.find('a') != -1) //ace
    {
      cardValue += 0;
    }
    else
    {
      cardValue += stoi(cardNum) - 1; 
    }

    deckA.addCard(cardValue);
    
    //Value printing for testing
    // cout << line.length() << endl;
    // for(auto character : line)
    // {
    //   cout << character << " ";
    // }
    // cout << endl;

    // cout << cardValue << endl; 
  }
  cardFile1.close();

  //deckA.printCards(); 


  while (getline (cardFile2, line) && (line.length() > 0)){
    int cardValue = 0;
    
    char suit = line.at(0);
    switch(suit) 
    {
      case 'c': //Clubs - 1-13
        cardValue += 1;
        break;
      case 'd': //Diamonds - 14-26
        cardValue += 14;
        break;
      case 's': //Spades - 27-39
        cardValue += 27;
        break;
      case 'h': //Hearts - 40-52
        cardValue += 40;
        break;
      default:
        cout << "ERROR: No suit, check input" << endl;
        break;
    }

    string cardNum; 
    for(int i = 2; i < line.length(); i++)
    {
      cardNum += line.at(i);
    }
    
    //Face cards
    if(cardNum.find('j') != -1) //jack
    {
      cardValue += 10;
    }
    else if(cardNum.find('q') != -1) //queen
    {
      cardValue += 11;
    }
    else if(cardNum.find('k') != -1) //king
    {
      cardValue += 12;
    }
    else if(cardNum.find('a') != -1) //ace
    {
      cardValue += 0;
    }
    else
    {
      cardValue += stoi(cardNum) - 1; 
    }

    deckB.addCard(cardValue);
    
    //Value printing for testing
    // cout << line.length() << endl;
    // for(auto character : line)
    // {
    //   cout << character << " ";
    // }
    // cout << endl;

    // cout << cardValue << endl; 
  }
  cardFile2.close();

  //deckB.printCards(); 


  //Game
  bool noMatchFlag = false;

  while(!noMatchFlag)
  {
    noMatchFlag = true; 
    int deckCurrValue = deckA.getFirstCard();
    while(deckCurrValue != 0)
    {
      if(deckB.containsCard(deckCurrValue))
      {
        cout << "Alice picked matching card ";
        if(deckCurrValue >= 1 && deckCurrValue <= 13) //club
        {
          cout << "c ";
          if(deckCurrValue == 11) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 0 << endl; 
          }
        }
        if(deckCurrValue >= 14 && deckCurrValue <= 26) //diamond
        {
          cout << "d ";
          if(deckCurrValue == 11 + 13) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 13) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 13) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 13) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 13 << endl; 
          }
        }
        if(deckCurrValue >= 27 && deckCurrValue <= 39) //spade
        {
          cout << "s ";
          if(deckCurrValue == 11 + 26) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 26) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 26) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 26) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 26 << endl; 
          }
        }
        if(deckCurrValue >= 40 && deckCurrValue <= 52) //heart
        {
          cout << "h ";
          if(deckCurrValue == 11 + 39) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 39) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 39) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 39) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 39 << endl; 
          }
        }

        noMatchFlag = false; 
        deckA.removeCard(deckCurrValue);
        deckB.removeCard(deckCurrValue);
        break;
      }
      else
      {
        deckCurrValue = deckA.getNextCard(deckCurrValue);
      }
    }

    deckCurrValue = deckB.getLastCard();
    while(deckCurrValue != 0)
    {
      if(deckA.containsCard(deckCurrValue))
      {
        cout << "Bob picked matching card ";
        if(deckCurrValue >= 1 && deckCurrValue <= 13) //club
        {
          cout << "c ";
          if(deckCurrValue == 11) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 0 << endl; 
          }
        }
        if(deckCurrValue >= 14 && deckCurrValue <= 26) //diamond
        {
          cout << "d ";
          if(deckCurrValue == 11 + 13) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 13) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 13) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 13) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 13 << endl; 
          }
        }
        if(deckCurrValue >= 27 && deckCurrValue <= 39) //spade
        {
          cout << "s ";
          if(deckCurrValue == 11 + 26) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 26) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 26) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 26) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 26 << endl; 
          }
        }
        if(deckCurrValue >= 40 && deckCurrValue <= 52) //heart
        {
          cout << "h ";
          if(deckCurrValue == 11 + 39) //jack
          {
            cout << "j" << endl;
          }
          else if(deckCurrValue == 12 + 39) //queen
          {
            cout << "q" << endl;
          }
          else if(deckCurrValue == 13 + 39) //king
          {
            cout << "k" << endl;
          }
          else if(deckCurrValue == 1 + 39) //ace
          {
            cout << "a" << endl; 
          }
          else
          {
            cout << deckCurrValue - 39 << endl; 
          }
        }

        noMatchFlag = false; 
        deckA.removeCard(deckCurrValue);
        deckB.removeCard(deckCurrValue);
        break;
      }
      else
      {
        deckCurrValue = deckB.getPreviousCard(deckCurrValue);
      }
    }
  }
  
  cout << endl; 

  cout << "Alice's cards:" << endl; 
  deckA.printCards();
  cout << endl; 
  cout << "Bob's cards:" << endl; 
  deckB.printCards();
  
  return 0;
}
