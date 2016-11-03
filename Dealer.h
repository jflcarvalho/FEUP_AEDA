#pragma once

#include <vector>
#include "utils.h"
#include "Player.h"

using namespace std;

class Dealer {
private:
	static unsigned int nextID;
	unsigned int ID;
	vector<Card> hand;
	unsigned int handScore;
	unsigned int nextPlayer;
	vector<Card> deck;
	vector<Card> deckDiscarded;

public:
	//Default constructor - creates a default deck of 52 cards
	Dealer();
	//Instanciates a new Dealer
	Dealer(vector<Card> newDeck);
	//shuffles Dealer's Deck
	void shuffleDeck();
	//Removes a Card from the end of the deck and returns it. Additionaly pushes the Card to the deckDiscarded vector
	Card discard();
	//Places a Card in the Dealer hand and updates the handscore
	Card& hit();
	/*Increases nextPlayer by 1;
	void stand();*/
	//Updates handScore
	unsigned int setHandScore();
	//get deck size to see if reshuffle is needed
	vector<Card>& getDeck();
	vector<Card>& getHand();
	void addCardsToDeck(vector<Card> &cards);
	vector<Card>& getDiscardedDeck();
	unsigned int getHandScore();
	void clearDiscardedDeck();
	void clearHand();
	string play();
};

