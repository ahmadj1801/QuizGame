#include "Player.h"
#include <iostream>
using namespace std;

//Constructors
Player::Player() {
	Player("Player 1");
}

//Parameterised Constructor
Player::Player(string name) {
	pd.name = name;
	pd.multiplier = 1;
	pd.numOfConsecutiveCorrectAns = 0;
	pd.score = 0;
	pd.completionBar = "|||";
}

//Accessors
string Player::getName() {
	return pd.name;
}

double Player::getScore() {
	return pd.score;
}

int Player::getNumConsec() {
	return pd.numOfConsecutiveCorrectAns;
}

double Player::getMultiplier() {
	return pd.multiplier;
}

//Mutators
void Player::updateConsecAns(bool correct) {
	if (correct == false) {
		pd.numOfConsecutiveCorrectAns = 0;
	}
	else {
		pd.numOfConsecutiveCorrectAns++;
	}
	setMultiplier();
}

void Player::updateScore(double correct) {
	pd.score = pd.score + (correct * pd.multiplier);
}


void Player::setMultiplier() {
	if (pd.numOfConsecutiveCorrectAns >= 3) {
		pd.multiplier= pd.multiplier +1;
	}
	else {
		pd.multiplier = 1;
	}
}


void Player::updateCompletionBar() {
	pd.completionBar = pd.completionBar + "|||";
}

//Auxillary
void Player::displayResults() {
	cout << pd.name << endl;
} 

void Player::displayCompletionbar() {
	cout << pd.completionBar;
}

//Destructor
Player::~Player() {
	cout << pd.name << " has left the game!" << endl;
}