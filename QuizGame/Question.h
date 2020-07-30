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
		string tag;

	public:
		//Constructor
		Question();
		Question(string question,vector<string> answers, string tag); //index 0 correct others wrong...initially
		
		//Accessor
		string getQuestion();
		string getCorrectAns();
		string getTag();
		string getSpecificAnswer(char c);

		//Mutators
		//Dont think we'll need to modify any attributes?
		
		//Auxillary
		void shuffleAnswers();//Need a way to shuffle the allAnswers vector so that when we output its always different
		
		//Also overload cout<< so we can use cout<<q1; and get a printed results
		bool compareAnswers(char c);

		//Using below method for debugging purposes for know
		void displayQuestion();

		void removeOne();

		void displayCorrectAnswer();

		//Destructor
		~Question();



};
