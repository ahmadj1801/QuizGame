#include "QuestionBank.h"
#include "Question.h"
#include <string>
#include<sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
#include <ctime>

using namespace std;

QuestionBank::QuestionBank() {
	//Default
}

QuestionBank::QuestionBank(int choice1, int choice2) 
{
	//Read text files
	readTextFile(choice1,0);
	readTextFile(choice2,10);
	//Shuffle the array
	shuffle(loadingList, 20);
	//Add to stack
	populateStack();
}

//Read data from text file
void QuestionBank::readTextFile(int txt, int round) 
{
	int index = round;
	ifstream questionFile;
	string tag="";
	if (txt == GEOG) 
	{
		questionFile.open("geography.txt");
		tag = "Geography";
	}
	else if (txt == HIST) 
	{
		questionFile.open("history.txt");
		tag = "History";
	}
	else if (txt == MUSC) 
	{
		questionFile.open("Music.txt");
		tag = "Music";
	}
	else if (txt == SCIN) 
	{
		questionFile.open("Science.txt");
		tag = "Science";
	}
	else if (txt == FILM) 
	{
		questionFile.open("Film.txt");
		tag = "Film";
	}
	else 
	{
		cout << "Cannot Locate Relevant File(s).";
	}

	if (questionFile.is_open()) 
	{
		while (!questionFile.eof()) 
		{
			string line;
			getline(questionFile, line);
			//Manipulate and create Question object
			vector<string> components;//index 0-Q index 1-CA index 2,3-ICA
			splitContent(line, components,'#');	
			string userQuestion = components.at(0);
			vector<string> *answers = new vector<string>();
			answers->push_back(components.at(1));
			answers->push_back(components.at(2));
			answers->push_back(components.at(3));
			Question *question = new Question(userQuestion, *answers,tag);
			loadingList[index] = *question;
			index++;
		}
	}
	else 
	{
		cout << "File could not be opened";
	}
	//shuffle(loadingList,19);
	questionFile.close();
}

//Template Function 1: A Code for Splitting a String based on a delimeter(#)
template<class Container>
void QuestionBank::splitContent(const string &str, Container &cont, char delim) 
{//Takes in a	1. string	2. Container(we use a vector)	3. Delimeter(we used a #)
	stringstream ss(str);
	string token;
	//While theres more (Read until # )
	while (getline(ss,token,delim))
	{
		//Add it to the Container(vector)
		cont.push_back(token);
	}
}

//Template Function : Shuffling of an Array of size n
template<class T>
void QuestionBank::shuffle(T arr[], int n) {
	//Initialize the random number generator
	srand(time(NULL));
	for (int i = n - 1; i > 0; i--) {
		//Random number => Ensure within range as well
		int random = rand() % (i + 1);
		//Code for a swap
		//T &temp;
		T temp = arr[random];
		arr[random] = arr[i];
		arr[i] = temp;
	}

}

void QuestionBank::populateStack() {
	//Loop 20 times for the 20 questions
	for (int i = 0; i < 20; i++) {
		//Push into the stack
		questionBank.push(loadingList[i]);
	}
}

Question QuestionBank::getQuestion() {
	//Get the Question from the top of the stack
	Question q = questionBank.top();
	//Remove it from the stack
	questionBank.pop();
	//Return the Question
	return q;
}

bool QuestionBank::questionsFinished() {
	if (questionBank.empty()) {
		return true;
	}
	return false;
}

//Destructor
QuestionBank::~QuestionBank() 
{
	
}
