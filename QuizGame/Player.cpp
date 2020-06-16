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

//Auxillary
void Player::displayResults() {
	cout << pd.name << endl;
} 

//Destructor
Player::~Player() {
	cout << pd.name << " has left the game!" << endl;
}