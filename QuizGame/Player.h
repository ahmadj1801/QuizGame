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
		string completionBar;// Form something like this "|||||||||" increment by ||| each question
		//vector<Question> orderOfQuestions; //Questions asked in order
		//map<Question,string> *qAndA; // Map doesnt have order.
	};
	PlayerDetails pd;

public:
	//Constructors
	Player();
	Player(string name);
	//comment
	//Accessors
	string getName();
	double getScore();
	double getMultiplier();
	int getNumConsec();

	//Mutators
	void updateScore(double value);
	void setMultiplier();
	void updateConsecAns(bool correct);
	void updateCompletionBar();

	bool operator>(const Player &p);

	bool operator<(const Player &p);

	//Auxillary
	void displayResults();
	void displayCompletionbar();
	//Destructor
	~Player();

};

