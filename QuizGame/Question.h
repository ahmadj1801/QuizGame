#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Question {
	private:
		string question; //Store the Question
		string correctAnswer; //Store the Correct answer
		vector<string> allAnswers;//A vector of all the answers
		string tag; //Stores the topic of the Question i.e. History, Geography etc

	public:
		//Constructors
		Question();
		Question(string question,vector<string> answers, string tag); //index 0 correct others wrong...initially
		
		//Accessor
		string getQuestion();
		string getCorrectAns();
		string getTag();
		string getSpecificAnswer(char c);
		
		//Shuffle Method for a vector
		void shuffleAnswers();//Need a way to shuffle the allAnswers vector so that when we output its always different
		
		//Compare the players answer with the correct answer
		bool compareAnswers(char c);

		//Display the question
		void displayQuestion();

		//Drop one of the correct Answers
		void removeOne();

		//Display the correct answer
		void displayCorrectAnswer();

		//Destructor
		~Question();



};
