#pragma once
#include "Question.h"

using namespace std;

class Lifeline {

private:
	
	bool flagFifty;//flags to determine if lifeline is used
	bool flagSave;
	Question q;

public:

	//constructors
	Lifeline();

	Lifeline(Question q);

	bool getFlagSave();

	bool getFifyFifty();

	//removes an answer and displays to player
	void fiftyFifty(Question q);

	// saves the persons multiplier if their answer is wrong
	void saveMultiplier(bool decision);

	//displays which lifelines are available 
	void displayLifelines();

	//destructor
	~Lifeline();
	
};
