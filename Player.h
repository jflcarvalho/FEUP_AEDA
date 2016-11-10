#pragma once

#include <string>
#include <iomanip>
#include <vector>
#include "utils.h"
#include "Dealer.h"
#include "Table.h"

using namespace std;
extern int bot1RunningCount;
class Dealer;

class NameTooShort {
public:
	void what();
};
class TooYoung {
public:
	void what();
};
class Player {
private:
	
	string name;
	unsigned int initialMoney;
	float currentMoney;
	vector <Card> hand;
	unsigned int handScore;
	unsigned int roundsPlayed;
	float averageProfit;
	int currentCounting;

public:
	static void updateBot1RunningCount(Card &aCard);
	static void resetBot1RunningCount();
	static int getBot1RunningCount();
	void hit(Card newCard);
	virtual bool takeInsurance(Table &table);
	void surrender();
	virtual bool split(vector<Card> * secHand);
	void doubleDown();
	vector<Card> & getHand();
	unsigned int getHandSize();
	unsigned int getRoundsPlayed();
	unsigned int getCurrentMoney();
	unsigned int getAverageProfit();
	unsigned int getHandScore();
	unsigned int getInitialMoney();
	unsigned int getCurrentCounter();
	string getName();
	void setName(string newName);
	unsigned int setHandScore();
	void setCurrentMoney(unsigned int money);
	void setCurrentCounter(int counter);
	void setRoundsPlayed(unsigned int rounds);
	void setInitialMoney(unsigned int money);
	void addMoney(unsigned int value);
	void showStatistics();
	//bots currently bet's always the minValue
	virtual unsigned int bet(Table &currentTable);
	virtual void clearHand();
	virtual string play(Dealer &dealerOfTable) = 0;
	
};

//////////////////////////////////////////////////// BOT 0 ////////////////////////////////////////////////////
class Bot0: public Player {
public:
	Bot0() {};
	Bot0(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &currentTable);
};

//////////////////////////////////////////////////// BOT 1 ////////////////////////////////////////////////////
class Bot1: public Player {
public:
	unsigned int bet(Table &currentTable);
	Bot1(string name, unsigned int initialMoney);
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &currentTable);
	bool split(vector<Card> * secHand);
};

//////////////////////////////////////////////////// BOT 2 ////////////////////////////////////////////////////
class Bot2 : public Player {
public:
	//play method
	string play(Dealer &dealerOfTable);
	bool takeInsurance(Table &table);
	bool split(vector<Card> * secHand);
};

//////////////////////////////////////////////////// HUMAN ////////////////////////////////////////////////////
class Human: public Player {
private:
	unsigned int age;
public:
	Human(string name, unsigned int age);
	unsigned int bet(Table &currentTable);
	string play(Dealer &dealerOfTable);
	unsigned int bet(Table &table);
	string play(Table &table);
	bool takeInsurance(Table &table);
	bool split(vector<Card> * secHand);
};