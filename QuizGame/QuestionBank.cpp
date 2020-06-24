#include "QuestionBank.h"
#include "Question.h"
#include <string>
#include<sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

QuestionBank::QuestionBank() {
	//Default
}

QuestionBank::QuestionBank(int choice1, int choice2) 
{
	//Read text files
	readTextFile(choice1);
	readTextFile(choice2);
}

void QuestionBank::readTextFile(int txt) 
{
	ifstream questionFile;
	if (txt == GEOG) 
	{
		questionFile.open("geography.txt");
	}
	else if (txt == HIST) 
	{
		questionFile.open("history.txt");
	}
	else if (txt == MUSC) 
	{
		questionFile.open("Music.txt");
	}
	else if (txt == SCIN) 
	{
		questionFile.open("Science.txt");
	}
	else if (txt == FILM) 
	{
		questionFile.open("Film.txt");
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
			Question *question = new Question(userQuestion, *answers);
			question->displayQuestion();

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


QuestionBank::~QuestionBank() 
{
	//Destructor
}
