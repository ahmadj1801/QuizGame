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
	pd.completionBar = "";
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
}

void Player::updateScore(double correct) {
	pd.score = pd.score + correct * pd.multiplier;
}

//Still need to decide how we will increase the other 2 i.e. score and multiplier
void Player::setMultiplier() {
	if (pd.numOfConsecutiveCorrectAns >= 3) {
		pd.multiplier = 1 +(pd.numOfConsecutiveCorrectAns / 10);
	}
	else {
		pd.multiplier == 1;
	}
}
//Overload > and < operators so we can compare player objects
bool Player::operator>(const Player &p) {
	if (pd.score > p.pd.score) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::operator<(const Player &p) {
	if (pd.score < p.pd.score) {
		return true;
	}
	else {
		return false;
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
	cout <<"\n"<< pd.name << " has left the game!" << endl;
	//delete qAndA;
}