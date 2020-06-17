#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Question {
	private:
		string question;
		string correctAnswer;
		vector<string> allAnswers;

	public:
		//Constructor
		Question(string question,vector<string> answers); //index 0 correct others wrong

		//Accessor
		string getQuestion();
		string getCorrectAns();

		//Mutators
		//Dont think we'll need to modify any attributes?
		
		//Auxillary
		void shuffle();//Need a way to shuffle the allAnswers vector so that when we output its always different
		//Also overload cout<< so we can use cout<<q1; and get a printed results
		bool compareAnswers(char c);

		//Destructor
		~Question();



};
