#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Question {
	private:
		string question;			//Store the Question
		string correctAnswer;		//Store the Correct answer
		vector<string> allAnswers;	//A vector of all the answers
		string tag;				    //Stores the topic of the Question i.e. History, Geography etc

	public:
//Constructors
		// Default Constructor
		Question();
		//Parameterised Constructor
		Question(string &question,vector<string> &answers, string &tag); 
		
//Accessors
		//Return the question
		string getQuestion();
		//Return the correct answer
		string getCorrectAns();
		//Return the topic
		string getTag();
		//Return the answer choosen by the player
		string getSpecificAnswer(char c);

//Auxillary
		//Shuffle Method for a vector
		void shuffleAnswers();
		
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
