#pragma once
#include <string>
#include <iostream>
#include <vector>

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
		//vector<Question> orderOfQuestions;
		//Map<Question,string> *qAndA;
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
	void updateConsecAns(int correct);

	//Auxillary
	void displayResults();

	//Destructor
	~Player();

};

