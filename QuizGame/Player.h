#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Question.h"

using namespace std;
//A sctruct to hold all attributes associated to a player
struct PlayerDetails
{
	string name;		//Name of Player
	double score;		//Current score
	double multiplier;	//Multiplier for score
	int numOfConsecutiveCorrectAns; //Correct streak
	string completionBar;// ||| increment each run
};

class Player
{
private:
	//Instance of the struct
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
	void setMultiplier();
	void updateConsecAns(bool correct);
	void updateCompletionBar();

	//operator overloading
	bool operator>(const Player &p1);
	bool operator<(const Player &p);

	//Auxillary
	void displayResults();
	void displayCompletionbar();

	//Destructor
	~Player();

};

