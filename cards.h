//cards.h
//Authors: Your name and your partner's name
//All class declarations go here
#include "intbst.h"

#ifndef CARDS_H
#define CARDS_H

class cards
{
    public:

        cards();

        void addCard(int cardValue);
        void printCards();
        int getFirstCard();
        int getLastCard(); 
        int getNextCard(int cardValue);
        int getPreviousCard(int cardValue);
        bool containsCard(int cardValue); 
        bool removeCard(int cardValue);

    private:
        IntBST list;
};

#endif