
#include "Generation.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;
Generation::Generation() {



    // 1er ETAPE GENERATION DU DECK EN ALEATOIRE
    deck = generateDeck();
    std::cout << "taille du deck " << deck.size() << ", nombre de joueur " << nbjoueur << ", nombre de carte par joueur " << handSize << std::endl;

    // ON PEUT PAS JOUER AVEC 0 JOUEUR DONC I = 1
    for (int i = 1; i < nbjoueur + 1; i++)
    {
        // 2E ETAPE GENERATION DE LA MAIN DU JOUEUER
        vector<Card> newhand =  generateHand(i);


        //print console
        cout<< "\n" << "Main du joueur " << i << endl;
        for (int j = 0; j < newhand.size(); j++)
        {
            cout << newhand[j].Get_str() << "|";
        }
        cout<< endl;
        //on ajoute la main dans les mains
        main.push_back(newhand);
    }
    
    //A INVERSER pour pouvoir forcer les combinaisons
    
    //high card
    /*
    std::vector<Card> hand0;
    hand0.push_back(Card('C', 8));
    hand0.push_back(Card('K', AS));
    hand0.push_back(Card('T', 12));
    hand0.push_back(Card('T', 7));
    hand0.push_back(Card('P', 2));

    //pair
    std::vector<Card> hand1;
    hand1.push_back(Card('C', AS));
    hand1.push_back(Card('T', 3));
    hand1.push_back(Card('T', 7));
    hand1.push_back(Card('P', 7));
    hand1.push_back(Card('K', VALET));

    //two pairs
    std::vector<Card> hand2;
    hand2.push_back(Card('T', 4));
    hand2.push_back(Card('K', 11));
    hand2.push_back(Card('C', 11));
    hand2.push_back(Card('C', 2));
    hand2.push_back(Card('C', 4));

    //three of a kind
    std::vector<Card> hand3;
    hand3.push_back(Card('C', 6));
    hand3.push_back(Card('T', 6));
    hand3.push_back(Card('K', 6));
    hand3.push_back(Card('P', 10));
    hand3.push_back(Card('T', 3));

    //straight
    std::vector<Card> hand4;
    hand4.push_back(Card('P', 5));
    hand4.push_back(Card('T', 4));
    hand4.push_back(Card('T', 6));
    hand4.push_back(Card('K', 7));
    hand4.push_back(Card('C', 3));

    //flush
    std::vector<Card> hand5;
    hand5.push_back(Card('P', 6));
    hand5.push_back(Card('P', ROI));
    hand5.push_back(Card('P', VALET));
    hand5.push_back(Card('P', 4));
    hand5.push_back(Card('P', 7));

    //full
    std::vector<Card> hand6;
        hand6.push_back(Card('C', 12));
        hand6.push_back(Card('K', 10));
        hand6.push_back(Card('P', 14));
        hand6.push_back(Card('P', 10));
        hand6.push_back(Card('T', 12));


    four of a kind*/
    /*std::vector<Card> hand7;
    hand7.push_back(Card('T', 8));
    hand7.push_back(Card('P', 8));
    hand7.push_back(Card('C', 8));
    hand7.push_back(Card('K', 8));
    hand7.push_back(Card('K', AS));*/

    //straight flush
    /*std::vector<Card> hand8;
    hand8.push_back(Card('C', 11));
    hand8.push_back(Card('C', 13));
    hand8.push_back(Card('C', 10));
    hand8.push_back(Card('C', 14));
    hand8.push_back(Card('C', 12));

    //straight with ace
    std::vector<Card> hand9;
    hand9.push_back(Card('C', AS));
    hand9.push_back(Card('K', 2));
    hand9.push_back(Card('P', 3));
    hand9.push_back(Card('T', 4));
    hand9.push_back(Card('C', 5));

    //All main vectors into one vector (everyHand vector)
    main.push_back(hand8);
    main.push_back(hand1);
    main.push_back(hand2);
    main.push_back(hand3);
    main.push_back(hand4);
    main.push_back(hand5);
    main.push_back(hand6);
    main.push_back(hand0);
    main.push_back(hand9);*/
    //r_deck = deck;
    //r_hands = main;
    
}


Generation::~Generation() {
    //dtor
}



std::vector<Card> Generation::generateDeck() {
    std::vector<Card> deck;

    for (int c = 0; c < 4; c++) {
        int coulour;
        if (c == 0) coulour = 67;
        if (c == 1) coulour = 75;
        if (c == 2) coulour = 80;                               //GENERATION DU DECK COULEUR PAR COULEUR
        if (c == 3) coulour = 84;

        for (int n = 2; n < 15; n++)
        {
            deck.push_back(Card(coulour, n));

        }
    }
    // LE SHUFFLE PERMET DE MELANGER LE DECK
    std::shuffle(deck.begin(), deck.end(), std::mt19937 (std::random_device()()));
    return deck;
}
std::vector<Card> Generation::generateHand(int nbpick) {
    std::vector<Card> hand;

    for (int i = (nbpick-1) * handSize; i < handSize * nbpick; i++) {
        //DEJA MELANGE DONC ON PIOCHE JUSTE
        hand.push_back(deck[i]);
       
    }

    return hand;
}