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

	//removes an answer
	void fiftyFifty();

	//adds +1 to multiplier
	void saveMultiplier();

	//displays which lifelines are available 
	void displayLifelines();

	//destructor
	~Lifeline();
	
};
