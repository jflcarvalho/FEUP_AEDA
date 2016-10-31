#pragma once

#include "Player.h"


void Player::hit(Card newCard) {
	hand.push_back(newCard);
	setHandScore();
}

void Player::takeInsurance() {
	throw "Not yet implemented";
}

void Player::surrender() {
	throw "Not yet implemented";
}

void Player::split() {
	throw "Not yet implemented";
}

void Player::doubleDown() {
	throw "Not yet implemented";
}

void Player::canUseSideRules() {
	throw "Not yet implemented";
}

unsigned int Player::setHandScore() {
	this->handScore = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		this->handScore += hand.at(i).score;
	}
	return this->handScore;
}

unsigned int Player::getHandScore() {
	return handScore;
}

void Player::setCurrentMoney(unsigned int money)
{
	currentMoney = money;
}

unsigned int Player::getCurrentMoney()
{
	return currentMoney;
}

unsigned int Player::bet(unsigned int minValue, unsigned int maxValue)
{
	unsigned int betValue = minValue;
	setCurrentMoney(getCurrentMoney() - betValue);
	return betValue;
}

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
unsigned int Bot0::play()
{
	unsigned int handScore = getHandScore();
	if (handScore < 17) {
		return 0; // 0 means hit
	}
	else if (handScore <= 21) {
		return 1; // means stand
	}
}

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
unsigned int Bot1::play()
{
	unsigned int handScore = getHandScore();
	vector<Card> discarded = getDiscardedDeck();
	int hitCards = 0;
	for(int i=0; i<discarded.size(); i++){
		if(discarded.at(i).score <= 5){
			hitCards++;
		}
	}
	return 0; // 0 means hit
}

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////