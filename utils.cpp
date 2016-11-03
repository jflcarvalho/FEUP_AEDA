#pragma once

#include "utils.h"



vector<Card> createDeck() {
	vector <string> suits = {"Heart" ,"Diamond" ,"Club" ,"Spade"};
	string ranks = "A234567890JQK";
	Card newCard;
	vector <Card> deck;

	for (unsigned int i = 0; i < ranks.length(); i++)
	{
		for (size_t j = 0; j < suits.size(); j++)
		{
			if (i == 0)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = 11;
			}
			else if (i < 9)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = i + 1;
			}
			else if (i == 9)
			{
				newCard.suits = suits.at(j);
				newCard.rank = "10";
				newCard.score = i + 1;
			}
			else if (i >= 1)
			{
				newCard.suits = suits.at(j);
				newCard.rank = ranks.at(i);
				newCard.score = 10;
			}
			deck.push_back(newCard);
		}
	}
	return deck;
}

string getHumanPlay()
{
	string option;
	getline(cin, option);
	while (option != "hit" && option != "stand" && option != "HIT" && option != "STAND" && option != "Hit" && option != "Stand") {
		cout << "Please insert a valid entry: ";
		getline(cin, option);
	}
	if (option == "HIT" || option == "Hit") {
		option = "hit";
	}
	else if (option == "Stand" || option == "STAND") {
		option = "stand";
	}
	return option;
}

unsigned short int readUnsignedIntBetween(unsigned int minValue, unsigned int  maxValue){
	unsigned int short newInt;
	cout << "Insert Your Bet ( " << minValue << "$ - " << maxValue << "$ ) : ";
	while (!(cin >> newInt) || newInt > maxValue || newInt < minValue) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Invalid Bet: Insert a new one: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}


int readIntBetween(int min, int max){
	int newInt;
	cout << "Insira um valor: ";
	while(!(cin >> newInt) || newInt > max || newInt < min) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido. Introduza um novo int: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}

unsigned int readUnsignedInt() {
	unsigned int newUnsignedInt;
	cout << "Insira um valor: ";
	while (!(cin >> newUnsignedInt)) {
		cout << endl;
		cin.clear();
		cin.ignore();

		cout << "Valor invalido, insira um novo valor unsigned int: ";
	}
	cin.ignore();
	cout << endl;
	return newUnsignedInt;
}
int readInt() {
	int newInt;
	cout << "Insira um valor: ";
	while (!(cin >> newInt)) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido, insira um novo valor unsigned int: ";
	}
	cin.ignore();
	cout << endl;
	return newInt;
}
float readFloat() {
	float newFloat;
	cout << "Insira um novo valor: ";
	while (!(cin >> newFloat)) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Valor invalido, insira um novo valor: ";
	}
	cin.ignore();
	cout << endl;
	return newFloat;
}
char readCharYorN() {
	char newChar;
	cout << "Insira o caracter: ";
	while (!(cin >> newChar) || (newChar != 'n' && newChar != 'N' && newChar != 'Y' && newChar != 'y')) {
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Caracter invalido, insira um novo caracter: ";
	}
	cin.ignore();
	cout << endl;
	return newChar;
}


//Paralel function
void Users(vector <int> &usersVEC, int &user) {
	string line;
	ifstream UserFileI("users_temp.txt");
	int find = 0;
	if (UserFileI.is_open())
	{
		usersVEC.clear();
		while (getline(UserFileI, line)) //enquanto houver linhas no ficheiro
		{
			usersVEC.push_back(stoi(line, nullptr, 10));
		}
		UserFileI.close();
		for (unsigned int i = 0; i < usersVEC.size(); i++)
		{
			if (user == usersVEC.at(i))
			{
				find = 1;
			}
		}
		if (find == 0)
		{
			usersVEC.push_back(usersVEC.back() + 1);
			user = usersVEC.back();
		}
	}
	else
	{
		usersVEC.push_back(1);
		user = usersVEC.back();
	}

	ofstream UserFileO("users_temp.txt");
	if (UserFileO.is_open())
	{
		for (unsigned int i = 0; i < usersVEC.size(); i++)
		{
			UserFileO << usersVEC.at(i) << endl;
		}
		UserFileO.close();
	}
}

void FileCopy(string filetxt, string filetxt_temp) {
	ofstream File(filetxt);
	ifstream File_temp(filetxt_temp);
	string line;
	if (File.is_open() && File_temp.is_open())
	{
		while (getline(File_temp, line))
		{
			File << line << endl;
		}
		File.close();
		File_temp.close();
	}
}

bool FileExist(string filetxt_temp) {
	ifstream file(filetxt_temp);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

int BinaryInt(int id, vector <int> VEC) {
	int lowindex = 0;
	int highindex = VEC.size() - 1;
	int i = -1;
	while (lowindex <= highindex)
	{
		i = (highindex + lowindex) / 2;
		if (id == VEC.at(i))
		{
			return i;
		}
		else if (id < VEC.at(i))
		{
			highindex = i - 1;
		}
		else if (id > VEC.at(i))
		{
			lowindex = i + 1;
		}
	}
	return -1;
}