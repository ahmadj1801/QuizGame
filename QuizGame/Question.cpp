#include "Question.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

Question::Question() {
	//Default
}

Question::Question(string &question,vector<string> &answers, string &tag) {
	//Store The Question
	this->question = question;
	//Store the Tags
	this->tag = tag;
	//Rule Used During Development: 
	//     - Index 0 represents the correct answer before the shuffle
	int i = 0;
	for (string s : answers) {
		//Add the answer to the vector
		this->allAnswers.push_back(s);
		//Check if i=0
		if (i == 0) {
			//Yes? Then assign it as the correct answer
			correctAnswer = s;
		}
		//Shuffle all the current elements
		shuffleAnswers();
		//increase i
		i++;
	}
	//All answers loaded. Shuffle the vector.
	shuffleAnswers();
}

//Code to shuffle the vector
void Question::shuffleAnswers() {
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
	//Return if the players answer is correct
	if (allAnswers[index].compare(correctAnswer)==0) {
		return true;
	}
	else {
		return false;
	}	
}

//Return the string value of the players answer
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

//Question display
void Question::displayQuestion() {
	cout << "\nTopic: " << this->getTag() << endl;
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

//Print the correct answer
void Question::displayCorrectAnswer() {
	cout << "Correct Answer: " << correctAnswer << endl;
}

//Drops on of the incorrect answers
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

//Destructor
Question::~Question() {

}