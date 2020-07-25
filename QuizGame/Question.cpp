#include "Question.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
		shuffleAnswers();
		i++;
	}
	shuffleAnswers();
	
	
}
void Question::shuffleAnswers() {
	//auto rng =default_random_engine{};
	//shuffle(begin(allAnswers),end(allAnswers),rng);
	random_shuffle(allAnswers.begin(),allAnswers.end());
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

string Question::getSpecificAnswer(char c) {
	switch (c) {
	case 'a':
		return allAnswers[0];
		break;
	case 'b':
		return allAnswers[1];
		break;
	case 'c':
		return allAnswers[2];
		break;
	default:
		return "No Answer for that option";
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
		cout << s << "\t\t";
		i++;
	}
	cout << endl;
}

void Question::displayCorrectAnswer() {
	cout << "Correct Answer: " << correctAnswer << endl;
}

void Question::removeOne() {
	int index = 0;
	for (int i = 0; i < allAnswers.size();i++) {
		if (correctAnswer==allAnswers[i]) {
			index = i;
		}
	}

	if (index>0) {
		cout << "b) " << allAnswers[1] << "\t\tc)" << allAnswers[2]<<endl;
	}
	else {
		cout << "a) " << allAnswers[0] << "\t\tb)" << allAnswers[1]<<endl;
	}
}

Question::~Question() {

}