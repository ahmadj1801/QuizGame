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
		stack<Question> questionBank;
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
		template<class T>
		void shuffle(T arr[], int n); 

		//Add items from the list to a stack
		void populateStack();

		//Check if our stack is empty
		bool questionsFinished();

		//pop from stack and return
		Question getQuestion();

		//Destructor
		~QuestionBank();
};