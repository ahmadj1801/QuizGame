#include "Player.h"
#include <iostream>
using namespace std;

//Constructors
Player::Player() {
	Player("Player 1");
}

Player::Player(string name) {
	pd.name = name;
	pd.multiplier = 1;
	pd.numOfConsecutiveCorrectAns = 0;
	pd.score = 0;
}

//Accessors
string Player::getName() {
	return pd.name;
}

int Player::getScore() {
	return pd.score;
}

int Player::getNumConsec() {
	return pd.numOfConsecutiveCorrectAns;
}

double Player::getMultiplier() {
	return pd.multiplier;
}

//Mutators
void Player::updateConsecAns(int correct) {
	if (correct == 0) {
		pd.numOfConsecutiveCorrectAns = 0;
	}
	else {
		pd.numOfConsecutiveCorrectAns++;
	}
}

//Still need to decide how we will increase the other 2 i.e. score and multiplier

//Overload > and < operators so we can compare player objects

//Auxillary
void Player::displayResults() {
	cout << pd.name << endl;
} 

//Destructor
Player::~Player() {
	cout << pd.name << " has left the game!" << endl;
	//delete qAndA;
}