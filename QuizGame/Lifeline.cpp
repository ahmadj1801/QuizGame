#include "Lifeline.h"

Lifeline::Lifeline() {
//default
	flagSave = true;
	flagFifty = true;
}

Lifeline::Lifeline(Question q) {}

bool Lifeline::getFlagSave() { return flagSave; }
bool Lifeline::getFifyFifty() { return flagFifty; }

void Lifeline::fiftyFifty(Question q) {
	if (flagFifty) {
		flagFifty = false;
		q.removeOne();
	}
}

void Lifeline::saveMultiplier(bool decision) {
	flagSave = decision;
}

void Lifeline::displayLifelines(){}

Lifeline::~Lifeline() {}