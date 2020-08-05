#include "Lifeline.h"

//Default constructor
Lifeline::Lifeline() {
	flagSave = true;
	flagFifty = true;
}

//Get the value of flagSave
bool Lifeline::getFlagSave() { return flagSave; }
//Get the value of flagFifty
bool Lifeline::getFifyFifty() { return flagFifty; }

//Use 50/50 lifeline
void Lifeline::fiftyFifty(Question q) {
	if (flagFifty) {
		flagFifty = false;
		q.removeOne();
	}
}

//Use Save multiplier Lifeline
void Lifeline::saveMultiplier(bool decision) {
	flagSave = (!decision);
}

Lifeline::~Lifeline() {}