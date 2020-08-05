#pragma once
#include "Question.h"

using namespace std;

class Lifeline {

private:
	
	bool flagFifty;	//flags to determine 50/50 is used
	bool flagSave;	//Flag to determine if save multiplier has been used

public:

	//constructors
	Lifeline();

	//Return true if the Save Multiplier lifeline is available
	bool getFlagSave();

	//Return true if the 50-50 lifeline is available
	bool getFifyFifty();

	//removes an answer and displays to player, Also changes state of flagFifty
	void fiftyFifty(Question q);

	//saves the persons multiplier if their answer is wrong, Also changes state of flagSave
	void saveMultiplier(bool decision);

	//destructor
	~Lifeline();
	
};
