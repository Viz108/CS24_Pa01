#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "intbst.h"

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
      case 'c': //Clubs - 0-12
        break;
      case 'd': //Diamonds - 13-25
        cardValue += 13;
        break;
      case 's': //Spades - 26-38
        cardValue += 26;
        break;
      case 'h': //Hearts - 39-51
        cardValue += 39;
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

  deckA.printCards(); 


  while (getline (cardFile2, line) && (line.length() > 0)){
    int cardValue = 0;
    
    char suit = line.at(0);
    switch(suit) 
    {
      case 'c': //Clubs - 0-12
        break;
      case 'd': //Diamonds - 13-25
        cardValue += 13;
        break;
      case 's': //Spades - 26-38
        cardValue += 26;
        break;
      case 'h': //Hearts - 39-51
        cardValue += 39;
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

  deckB.printCards(); 
  
  
  return 0;
}
