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
			//question->displayQuestion();
		}
	}
	else 
	{
		cout << "File could not be opened";
	}
	questionFile.close();
}

template<class Container>
void QuestionBank::splitContent(const string &str, Container &cont, char delim) 
{
	stringstream ss(str);
	string token;
	while (getline(ss,token,delim))
	{
		cont.push_back(token);
	}
}

template<class T>
void QuestionBank::shuffle(T arr[], int n) {
	srand(time(NULL));
	for (int i = n - 1; i > 0; i--) {
		int random = rand() % (i + 1);
		Question temp = loadingList[random];
		loadingList[random] = loadingList[i];
		loadingList[i] = temp;
	}
}

void QuestionBank::populateStack() {
	for (int i = 0; i < 20; i++) {
		questionBank.push(loadingList[i]);
	}
}

Question QuestionBank::getQuestion() {
	Question q = questionBank.top();
	questionBank.pop();
	q.displayQuestion();
	return q;
}

bool QuestionBank::questionsFinished() {
	if (questionBank.empty()) {
		return true;
	}
	return false;
}



QuestionBank::~QuestionBank() 
{
 //Destructor
}
