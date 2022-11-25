#include <algorithm>
#include "Comp.h"

using namespace std;
Comp::Comp() {
    //GameGeneration();
	for (int i = 0; i < nbjoueur; i++)
	{
		if (QuinteFlush(main, i, Forcedelamain) == 0) {
			if (Carre(main, i, Forcedelamain) == 0) {
				if (Full(main, i, Forcedelamain) == 0) {
					if (Color(main, i, Forcedelamain) == 0) {
						if (Suite(main, i, Forcedelamain) == 0) {
							if (Brelan(main, i, Forcedelamain) == 0) {
								Pair(main, i, Forcedelamain);
							}
						}
					}
				}
			}
		}
	}
	//PARTIE AFFICHE MEILLEUR JOUEUR
	int bestPlayer = BestPlayer(Forcedelamain);
	vector<int> bestCombination = Forcedelamain[bestPlayer - 1];

	if (bestCombination[1]>1&& bestCombination[1] > bestCombination[2]) {
		cout << "\n" <<  "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[1]   <<" et sa meilleure carte est un " << bestCombination[3] << endl;
	}
	else if (bestCombination[2]!=0) {
		cout << "\n"<<  "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[2]<<   " et sa meilleure carte est un " << bestCombination[3] << endl;

	}
	else {
		cout << "\n"<< "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[3] << " et sa meilleure carte est un " << bestCombination[3] << endl;

	}
	
}

Comp::~Comp() {

}

int Comp::Pair(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector<  std::vector<int>>& Force) {
	int nbPaire = 0;
	int firstCard = 0;
	int secondCard = 0;
	vector<int> tempVector;

	//Meme comparaison pour full
	for (int i = 0; i < this->handSize; i++)
	{
		int valueCard = completeHand[playernum][i].Get_value();
		for (int j = 0; j < this->handSize; j++)
		{
			if (i != j) {
				int valueSecondCard = completeHand[playernum][j].Get_value();
				if (valueCard == valueSecondCard) {
					nbPaire++;
					if (firstCard == 0) {
						firstCard = valueCard;
					}
					else if (secondCard == 0 && firstCard != valueCard) {

						secondCard = valueCard;
					}
				}
			}

		}
	}
	tempVector.push_back( nbPaire / 2);
	tempVector.push_back(firstCard);
	tempVector.push_back( secondCard);
	tempVector.push_back(labest(completeHand, playernum));
	Force.insert(Force.begin() + playernum, tempVector);
	return nbPaire/2;

}
int Comp::Brelan(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int brelan = 0;
    int var = 0;
    //ON CHERCHE BRELAN PUIS PAIRE
    //MEME TECHNIQUE QUE LE CARRE
    for (int i = 0 ; i < 3; i++){
        var = 0;
        for(int j = 1; j < handSize; j++) {
            if(completeHand[playernum][i].Get_value() == completeHand[playernum][j].Get_value() && i != j) {
                var++;
            }
            if (var == 2) {
                brelan = 1;
                vector<int> tempVector;
                tempVector.push_back(3);
                tempVector.push_back(labest(completeHand, playernum));
                forceOfTheHand.push_back(tempVector);
                break;
            }
        }
    }



	
	return brelan;

}
int Comp::Carre(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int carre = 0;
    int var = 0;

    //ON COMPARE LA PREMIERE CARTE AVEC LES AUTRES
    //SI PAS MATCH ON COMPARE AVEC LA DEUXIEME
    for (int i = 0 ; i < 2; i++){
        // ON REINISIALISE CAR IL PEUT GARDER LES VALEURS DE L ANCIENNE BOUCLE SINON
        var = 0;
        for(int j = 1; j < handSize; j++) {
            if(completeHand[playernum][i].Get_value() == completeHand[playernum][j].Get_value() && i != j) {
                // I != J POUR PAS COMPARER UNE CARTE AVEC ELLE MEMES
                var++;
            }
            if (var == 3) {
                vector<int> tempVector;
                tempVector.push_back(7);
                tempVector.push_back(labest(completeHand, playernum));
                forceOfTheHand.push_back(tempVector);
                carre = 1;
                break;
            }
        }
    }
	return carre;
}


int Comp::Full(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int brelan = 0;
	int full = 0;
    int var = 0;
    int nbPaire = 0;
    int var2 = 0;

    //ON CHERCHE BRELAN PUIS PAIRE
    //MEME TECHNIQUE QUE LE CARRE
    for (int i = 0 ; i < 3; i++){
        var = 0;
        for(int j = 1; j < handSize; j++) {
            if(completeHand[playernum][i].Get_value() == completeHand[playernum][j].Get_value() && i != j) {
                var++;
            }
            if (var == 2) {
                brelan = 1;
                break;
            }
        }
    }
    // SI BRELAN ON CHERCHE UNE PAIRE
	if (brelan == 1) {
        for (int i = 0 ; i < 4; i++){
            var2 = 0;
            for(int j = 1; j < handSize; j++) {
                if(completeHand[playernum][i].Get_value() == completeHand[playernum][j].Get_value() && i != j) {
                    var2++;
                }
                if (var2 == 2) {
                    nbPaire = 1;
                    break;
                }
            }
        }
		if (nbPaire > 0) {
			full = 1;
            vector<int> tempVector;
            tempVector.push_back(6);
            tempVector.push_back(labest(completeHand, playernum));
            forceOfTheHand.push_back(tempVector);
		}
	}
	return full;

}
int Comp::Suite(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	int suite = 1;
	int valueBestCard = labest(completeHand, playernum);
	vector<int> tempVector;
	vector<int> vcards;

	for (int i = 0; i < this->handSize ; i++)
	{
		vcards.push_back(completeHand[playernum][i].Get_value());
	}
	for (int i = valueBestCard - 1; i > valueBestCard - this->handSize; i--)
	{
		//COUNT COMPTE PAS IL CHERCHE
		if (count(vcards.begin(), vcards.end(), i)) {
			suite++;
		}
		else {
			suite = 0;
			break;
		}

	}
	if (valueBestCard == 14 && suite == 0) {
		suite = 1;
		for (int i = 2; i < 6; i++)
		{

			if (count(vcards.begin(), vcards.end(), i)) {
				suite++;
			}
			if (suite == 5) {
				valueBestCard = i;
			}
			else {
				suite = 0;
				break;
			}

		}
		
	}
	
	
	if (suite == 5) {
		tempVector.push_back(4);
		tempVector.push_back(valueBestCard);
		tempVector.push_back(0);
		tempVector.push_back(labest(completeHand, playernum));
		forceOfTheHand.push_back(tempVector);
	}
	return suite;
}
int Comp::Color(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	vector<int> tempVector;
	
	int color = 1;
	//ON PREND LA PREMIERE CARTE EN REFERENCE
	int colorFirstCard = completeHand[playernum][0].Get_color();
	for (int i = 1; i < this->handSize; i++) {
		if (colorFirstCard == completeHand[playernum][i].Get_color()) {
			color++;
		}
		else {
			color = 0;
			break;
		}
	}
	if (color == 5) {
		tempVector.push_back(5);
		tempVector.push_back(1);
		tempVector.push_back(0);
		tempVector.push_back(labest(completeHand, playernum));
		forceOfTheHand.push_back(tempVector);
	}
	return color;
}
int Comp::QuinteFlush(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	int quinteFlush = 0;
	vector<int> tempVector;
	int suite = 1;
	int valueBestCard = labest(completeHand, playernum);
	
	vector<int> vcards_1;

    // VCARD CONTIENT TOUT LES VALEURS DES CARTES DE LA MAIN
	for (int i = 0; i < handSize; i++)
	{
        //ON REMPLIT VCARDS PAR LES VALEURS DE LA MAIN DU JOUEUR
		vcards_1.push_back(completeHand[playernum][i].Get_value());
	}

    // TABLEAU POUR COMPARER LES CARTES AVEC LA MEILLEURE -1
	for (int i = valueBestCard - 1; i > valueBestCard - handSize; i--)
	{
    // COUNT = FONCTION PERMETTANT DE CE BALADER DU DEBUT A LA FIN DE LA LISTE (VCARD) EN DONNANT CE QUE L ON VEUT TROUVER
		if (count(vcards_1.begin(), vcards_1.end(), i)) {
			suite++;
		}
		else {
			suite = 0;
			break;
		}

	}
    //SUITE TROUVER DONC CHECK COULEUR
	if (suite == 5) {
		int color = 1;
        //ON PREND LA COULEUR DE LA PREMIERE CARTE GRACE AU GETTER
		int colorFirstCard = completeHand[playernum][0].Get_color();
        //SUITE CHECK DE LA MAIN SI IL SONT TOUTES DE LA MEME COULEUR
		for (int i = 1; i < handSize; i++) {
			if (colorFirstCard == completeHand[playernum][i].Get_color()) {
				color++;
			}
			else {
				color = 0;
				break;
			}
		}
		
		if (color == 5) {
            // ICI IL A TROUVE UN QUINTE FLUSH SIMPLE
			quinteFlush = 8;
            // CHECK SI Y A UN AS SI OUI BAH QUINTE FLUSH ROYALE
			if (labest(completeHand, playernum) == 14) {
					quinteFlush = 9;
			}
			tempVector.push_back(quinteFlush);
			tempVector.push_back(labest(completeHand, playernum));
			forceOfTheHand.push_back(tempVector);
		}
	}
	return quinteFlush;
}
int Comp::labest(std::vector<std::vector<Card>>& completeHand, int playernum) {
	int Bestcard = 0;

	// COMPARAISON CARTE PAR CARTE
	for (int i = 0; i < handSize; i++)
	{
		int valueActualCard = completeHand[playernum][i].Get_value();
		if (valueActualCard > Bestcard) {
			Bestcard = valueActualCard;
		}
	}

	return Bestcard;
}
int Comp::BestPlayer(std::vector< std::vector<int>>& Force) {
	vector<int> bestCombination = Force[0];
	int bestPlayer = 0;
	for (int i = 1; i < Force.size(); i++)
	{
		vector<int> Combinaison = Force[i];
		if (Combinaison[0] == bestCombination[0]) {
			if (Combinaison[1] == bestCombination[1] && Combinaison[1] == bestCombination[2]) {
				if (Combinaison[2] == bestCombination[1] && Combinaison[2] == bestCombination[2]) {
					if (Combinaison[3] == bestCombination[3]) {
						cout << "egalite entre le joueur " << bestPlayer + 1 << " et " << i + 1 << endl;
						bestPlayer = i;
						bestCombination = Combinaison;
					}
					else if (Combinaison[3] > bestCombination[3]) {
						bestPlayer = i;
						bestCombination = Combinaison;
					}
				}
				else if (Combinaison[2] > bestCombination[2] && Combinaison[2] > bestCombination[2]) {
					bestPlayer = i;
					bestCombination = Combinaison;
				}
			}
			else if (Combinaison[1] > bestCombination[1] && Combinaison[1] > bestCombination[2]) {
				bestPlayer = i;
				bestCombination = Combinaison;
			}
		}else if (Combinaison[0] > bestCombination[0]) {
			bestPlayer = i;
			bestCombination = Combinaison;
		}
		
	}
	return bestPlayer+1;
}