#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
	struct PlayerDetails
	{
		string name;
		int score;
		double multiplier;
		int numOfConsecutiveCorrectAns;
	};
	PlayerDetails pd;

public:
	//Constructors
	Player();
	Player(string name);

	//Accessors
	string getName();
	int getScore();
	double getMultiplier();
	int getNumConsec();

	//Mutators
	void updateScore(int value);
	void setMultiplier(double value);
	void updateConsecAns();

	//Auxillary
	void displayResults();

	//Destructor
	~Player();

};

