#pragma once
#include "Card.h"
#include <string>
#include "Generation.h"


class Comp : public Generation
{

public:
	Comp();
	~Comp();

	std::vector<std::vector<int>> Forcedelamain;


	int Suite(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int Color(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int QuinteFlush(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);

	int Carre(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int Brelan(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	//RETOURNE LA CARTE FORTE
	int Pair(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& Force);
	int Full(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);

	//MEILLEURE CARTE
	int labest(std::vector<std::vector<Card>>& completeHand, int playernum);


	//CONSOLE
	const char *combinationType[10] = { "une carte forte de ", "une paire de ", "une double paire ", "un brelan de ", "une suite de ","une couleur ","un full de ", "un carre de ","une quinte flush ", "une quinte flush royale " };

	int BestPlayer(std::vector< std::vector<int>>& Force);
};

