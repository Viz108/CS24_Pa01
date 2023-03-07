#include <iostream>
#include "cards.h"
//#include "intbst.h"

using namespace std; 

int main()
{
    cards testDeck;
    testDeck.addCard(1);
    testDeck.addCard(2);
    testDeck.addCard(3);
    testDeck.addCard(4);
    testDeck.addCard(5);

    testDeck.printCards();
    cout << "First card: " << testDeck.getFirstCard() << endl; 
    cout << "Last card: " << testDeck.getLastCard() << endl;
    if(testDeck.containsCard(3))
    {
        cout << "contains c 5" << endl; 
    }
    else
    {
        cout << "does not contain c 5" << endl; 
    }
    testDeck.removeCard(3);
    cout << "removed c 5" << endl;
    if(testDeck.containsCard(3))
    {
        cout << "contains c 5" << endl; 
    }
    else
    {
        cout << "does not contain c 5" << endl; 
    }
    cout << "Card before 4: " << testDeck.getPreviousCard(4);
    cout << "Card after 4: " << testDeck.getNextCard(4);
}