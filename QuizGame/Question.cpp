#include "Question.h"
#include <string>
#include <iostream>
#include <vector>

Question::Question() {
	//Default
}

Question::Question(string question,vector<string> answers, string tag) {
	this->question = question;
	this->tag = tag;
	int i = 0;
	for (string s : answers) {
		this->allAnswers.push_back(s);
		if (i == 0) {
			correctAnswer = s;
		}
		i++;
	}
	
}

string Question::getQuestion() {
		return question;
}

string Question::getCorrectAns() {
	return correctAnswer;
}

string Question::getTag() {
	return tag;
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
		cout << "Invalid Option Entered!\n";
		return false;
	}

	if (allAnswers[index].compare(correctAnswer)==0) {
		return true;
	}
	else {
		return false;
	}	
}

void Question::displayQuestion() {
	cout << "\n" << this->getTag() << endl;
	cout << this->question<<endl;
	int i = 0;
	for (string s : this->allAnswers) {
		if (i==0) {
			cout << "a) ";
		}
		else if (i == 1) {
			cout << "b) ";
		}
		else {
			cout << "c) ";
		}
		cout << s << "\t";
		i++;
	}
	cout << endl;
}

void Question::displayCorrectAnswer() {
	cout << "Correct Answer: " << correctAnswer << endl;
}

Question::~Question() {

}