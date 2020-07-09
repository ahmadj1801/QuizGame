#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "Question.h"

using namespace std;

class QuestionBank {
	private:
		const int GEOG = 0;
		const int HIST = 1;
		const int MUSC = 2;
		const int SCIN = 3;
		const int FILM = 4;
		stack<Question> *questionBank;
		Question loadingList[20];

	public:
		//Default Constructor
		QuestionBank();

		//player 1 and player 2 choices...Read in text files
		QuestionBank(int choice1,int choice2); 

		//Method for processing text files
		void readTextFile(int txt, int round);

		//Method to split contents read from text file
		template<class Container>
		void splitContent(const string &str, Container &cont,char delim);

		// shuffle the loading list 
		void shuffle(); 

		//pop from stack and display to user
		void displayNextQuestion(); 

		//Destructor
		~QuestionBank();
};