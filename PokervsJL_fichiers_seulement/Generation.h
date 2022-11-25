#ifndef POKERVS_GAMEGENERATION_H
#define POKERVS_GAMEGENERATION_H
#include <vector>
#include <iostream>
#include "Card.h"
class Generation
{

public:
    Generation();
    ~Generation();
    int handSize = 5;
    int nbjoueur = 2;
    //DECK 52 CARTES
    std::vector<Card> deck;


    std::vector< std::vector<Card>> main;
        
    //genere une main qui sera incluse dans main
    std::vector<Card> generateHand(int nbPick);
    
    //genere un nouveau deck
    std::vector<Card> generateDeck();
       
        
    protected:
        

    private:
        
       
};

#endif

