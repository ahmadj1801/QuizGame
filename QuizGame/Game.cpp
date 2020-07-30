#include <iostream>
#include "Player.h"
//#include "Question.h"
#include "QuestionBank.h"
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include "Lifeline.h"
//#include <Windows.h>

using namespace std;

inline void introduction();
inline void waitForEnter();
inline void questionHeader(int &i);
inline void gameBreak();
inline void gameWinner(Player &p1, Player &p2);
//inline void setWhite(HANDLE &h);
//inline void setRed(HANDLE &h);
//inline void setGreen(HANDLE &h);
//inline void setBlue(HANDLE &h);
//inline void setYellow(HANDLE &h);
void playARound(Player &p, QuestionBank &questionBank, Lifeline &l, int &i);

//Points earned per correct question
const int CORRECT = 10;

int main() {

	//Display Game Rules
	introduction();

	//Wait for player to Click Enter before game starts
	waitForEnter();

	//Capture player details
	string p1Name;
	string p2Name;
	std::cout << "Player 1, Please Enter your Name:" << endl;
	getline(cin, p1Name); 
	std::cout << "Player 2, Please Enter your Name:" << endl;
	getline(cin, p2Name);

	//Create Player objects
	Player *p1 = new Player(p1Name);
	Player *p2 = new Player(p2Name);

	//Lifelines for Players
	Lifeline *life1 = new Lifeline();
	Lifeline *life2 = new Lifeline();

	//Load all neccessary questions for the game
	int topic1 = 0;
	int topic2 = 0;
	std::cout << "\nPlease select Two Different Game Question Topics: " << endl;
	std::cout << "1)Geography\t2)History\t3)Music\t4)Science\t5)Film"<<endl;
	std::cout << p1->getName() << " pick a topic: " << endl;
	cin>>topic1;
	topic1--;
	std::cout << p2->getName() << " pick a topic: " << endl ;
	cin>>topic2;
	topic2--;
	cout << endl;

	QuestionBank *questionBank = new QuestionBank(topic1, topic2);
	//Play the actual Game...All this code could actually be in a method once done
	cin.ignore();
	//waitForEnter();
	
	std::cout << "Player 1, You will play first.\n" << endl;

	//Player 1 Plays
	for (int i = 1; i < 11; i++) {
		playARound(*p1,*questionBank, *life1,i);
	}

	gameBreak();

	std::cout << "Player 2, It's your turn.\n"<<endl;
	//Player 2 Plays
	for (int i = 1; i < 11; i++) {
		//Player 2 plays
		playARound(*p2, *questionBank, *life2, i);
	}
	
	//Include: Background colour of yellow
	gameWinner(*p1,*p2);

	cout << "\n";

	//end of game, player leaves
	delete p1; delete p2;
	return 0;
}

inline void introduction() {
	std::cout << "Welcome to WIT WARRIORS\n"
		<< "\nHow to Play:\n"
		<< "===============\n"
		<< "   - The game is played between two players.\n"
		<< "   - Each player will pick a topic from the list provided.\n"
		<< "   - The questions generated for the quiz will be based on\n"
		<< "     the topics choosen by the players.\n"
		<< "   - The quiz will be comprised of 10 questions\n"
		<< "   - Each player will be given TWO lifelines\n"
		<< "          * 50-50: This Lifeline will drop one of\n"
		<< "                   the incorrect answers.\n"
		<< "          * Save:  This Lifeline will allow players to save\n"
		<< "                   their score streak multiplier if they\n"
		<< "                   get an answer incorrect.\n"
		<< "   - You get one of each lifeline, so use it wisely.\n"
		<< "   - Correctly answered questions will earn you 10 points, but\n"
		<< "     string together 3 correct answers to earn yourself a\n"
		<< "     score streak multiplier.\n"
		<< "\nBelow is an example of a question you might encouter along with\n"
		<< "its correct response:\n"
		<< "Which country hosted the 2010 Fifa World Cup?\n"
		<< "a) Spain\tb) Brazil\tc) South Africa\n"
		<< "Expected response: c\n\n";

}

inline void waitForEnter() {
	std::cout << "\nPress Enter to Play...\n";
	cin.ignore();
}

inline void questionHeader(int &i) {
	std::cout << "\nQuestion " << i << " of 10:"<<endl;
}

inline void gameBreak() {
	std::cout << "\n==================================================\n";
	std::cout << "\n==================================================\n";
	std::cout << "\n==================================================\n";
}

//Code that will play a single question round
void playARound(Player &p, QuestionBank &questionBank, Lifeline &l, int &i) {
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	string answer;
	char response;
	Question q;
	questionHeader(i);
	p.displayCompletionbar();
	std::cout << "\t" << i * 10 << "% Complete\n";
	std::cout << "Current Score: " << p.getScore() << endl;
	cout << "Perks Availaible:\t";
	if (l.getFifyFifty()) {
		cout << "50/50: 1 (Press d)\t";
	}
	else {
		cout << "50/50: 0\t";
	}
	if (l.getFlagSave()) {
		cout << "Save Multiplier: 1" << endl;
	}
	else {
		cout<<"Save Multiplier: 0"<<endl;
	}
	if (!questionBank.questionsFinished()) {
		q = questionBank.getQuestion();
		q.displayQuestion();
	}
	std::cout << "Your Response: ";
	getline(cin, answer);
	answer.erase(remove_if(answer.begin(), answer.end(), ::isspace), answer.end());
	response = answer[0];
	response = tolower(response);
	if (response=='d') {
		if (l.getFifyFifty()) {
			l.fiftyFifty(q);
			std::cout << "Your Response: ";
			getline(cin, answer);
			answer.erase(remove_if(answer.begin(), answer.end(), ::isspace), answer.end());
			response = answer[0];
			response = tolower(response);
		}
	}
	if (q.compareAnswers(response)) 
	{
		//SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Green
		std::cout << "CORRECT" << endl;
		p.updateScore(CORRECT);
		p.updateConsecAns(true);
	}
	else 
	{
		//SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);//Red
		std::cout << "INCORRECT" << endl;
		char c;
		if (l.getFlagSave() && p.getMultiplier()>1)
		{
			cout << "OOOPS!!! You run the risk of losing your score streak multiplier\n";
			cout << "Would you like to save it (y/n): " << endl;
			cin >> c;
			cin.ignore();
			if (c=='y') {
				l.saveMultiplier(true);
				cout << "Shew!!! That was a close one. Lets hope that doesn't happen again." << endl;
			}
		}
		else {
			p.updateConsecAns(false);
		}
		
	}
	//SetConsoleTextAttribute(handle, 11);//cyan
	std::cout << "Your Answer: " << "(" << response << ") " << q.getSpecificAnswer(response) << endl;
	q.displayCorrectAnswer();
	std::cout << "\n\n";
	//SetConsoleTextAttribute(handle, 15 | FOREGROUND_INTENSITY);//White
	p.updateCompletionBar();
}

void gameWinner(Player &p1,Player &p2) {
	//Display respective scores
	cout << p1.getName() << " has a final score of: " << p1.getScore() << endl;
	cout << p2.getName() << " has a final score of: " << p2.getScore() << endl;
	cout << endl;
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(handle, 14);//yellow
	if (p1 > p2) {
		std::cout <<"CONGRATULATIONS, YOUR'RE A QUIZZARD " << p1.getName()<<endl;
	}
	else if (p2 > p1) {
		std::cout << "CONGRATULATIONS, YOUR'RE A QUIZZARD "<< p2.getName()<<endl;
	}
	else {
		std::cout << "Draw!!!\n";
	}
	cout << endl;
	//SetConsoleTextAttribute(handle, 15 | FOREGROUND_INTENSITY);//White
}

//Overload > and < operators so we can compare player objects
bool Player::operator>(const Player &p) {
	if (getScore() > p.pd.score) { 
		return true;
	}
	else {
		return false;
	}
}

bool Player::operator<(const Player &p) {
	if (getScore() > p.pd.score) {
		return true;
	}
	else {
		return false;
	}
}