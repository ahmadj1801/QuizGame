#include "Question.h"
#include <string>
#include <iostream>
#include <vector>

Question::Question() {
	//Default
}

Question::Question(string question,vector<string> answers) {
	this->question = question;
	for (string s : answers) {
		this->allAnswers.push_back(s);
	}
}

string Question::getQuestion() {
		return question;
}

string Question::getCorrectAns() {
	return correctAnswer;
}

bool Question::compareAnswers(char c) {
	//User will input a b or c... a=index 0 in vector, b= index 1 and c=index 2
	int index = -1;
	switch (c) {
	case 'a':
		index = 0;
		break;
	case 'b':
		index = 1;
		break;
	case 'c':
		index = 2;
		break;
	default: 
		cout << "Invalid Option Entered!";
		return false;
	}

	if (allAnswers[index]._Equal(correctAnswer)) {
		return true;
	}
	else {
		return false;
	}	
}

Question::~Question() {

}