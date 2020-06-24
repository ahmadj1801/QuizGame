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
		QuestionBank();
		QuestionBank(int choice1,int choice2); //player 1 and player 2 choices...Read in textfiles
		void readTextFile(int txt);
		template<class Container>
		void splitContent(const string &str, Container &cont,char delim);
		void shuffle(); // shuffle the loading list
		void displayQuestion(); //pop from stack and display to user

		~QuestionBank();//Destructor
};