#include "Lifeline.h"

Lifeline::Lifeline() {
	//default
	flagSave = true;
	flagFifty = true;
}

bool Lifeline::getFlagSave() { return flagSave; }
bool Lifeline::getFifyFifty() { return flagFifty; }

void Lifeline::fiftyFifty(Question q) {
	if (flagFifty) {
		flagFifty = false;
		q.removeOne();
	}
}

void Lifeline::saveMultiplier(bool decision) {
	flagSave = !decision;
}

Lifeline::~Lifeline() {}