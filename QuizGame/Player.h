#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Question.h"

using namespace std;

class Player
{
private:
	struct PlayerDetails
	{
		string name; //Name of Player
		double score; //Current score
		double multiplier; //Multiplier for score
		int numOfConsecutiveCorrectAns; //Correct streak
		vector<Question> orderOfQuestions; //Questions asked in order
		map<Question,string> *qAndA; // Map doesnt have order.
	};
	PlayerDetails pd;

public:
	//Constructors
	Player();
	Player(string name);

	//Accessors
	string getName();
	double getScore();
	double getMultiplier();
	int getNumConsec();

	//Mutators
	void updateScore(double value);
	void setMultiplier(double value);
	void updateConsecAns(bool correct);

	bool operator>(const Player &p);

	bool operator<(const Player &p);

	//Auxillary
	void displayResults();

	//Destructor
	~Player();

};

