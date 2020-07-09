#include <iostream>
#include "Player.h"
//#include "Question.h"
#include "QuestionBank.h"
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

inline void introduction();
inline void waitForEnter();
inline void questionHeader(int &i);

int main() {

	//Display Game Rules
	introduction();

	//Wait for player to Click Enter before game starts
	waitForEnter();

	//Capture player details
	string p1Name;
	string p2Name;
	cout << "Player 1, Please Enter your Name:" << endl;
	getline(cin, p1Name); 
	cout << "Player 2, Please Enter your Name:" << endl;
	getline(cin, p2Name);

	//Create Player objects
	Player *p1 = new Player(p1Name);
	Player *p2 = new Player(p2Name);

	//Load all neccessary questions for the game
	QuestionBank *questionBank = new QuestionBank(2,4);

	//Play the actual Game
	string answer;
	char response;
	Question q;
	for (int i = 1; i < 11; i++) {
		//Player 1 plays
		questionHeader(i);
		if (!questionBank->questionsFinished()) {
			q = questionBank->getQuestion();
		}
		cout << "Your Response: ";
		getline(cin, answer);
		answer.erase(remove_if(answer.begin(), answer.end(), ::isspace), answer.end());
		response = answer[0]; 
		tolower(response);
		if (q.compareAnswers(response)){
			cout<<"CORRECT"<<endl;
		}
		else {
			cout<<"INCORRECT"<<endl;
		}
		cout << "Your Answer: " << response << " - Add here actual Ans" << endl; //Case: What if the input out of bounds
		q.displayCorrectAnswer();
		
	}

	for (int i = 1; i < 11; i++) {
		//Player 2 plays
		questionHeader(i);
		if (!questionBank->questionsFinished()) {
			questionBank->getQuestion();
		}
	}

	//Nothing special for now
	p1->displayResults();
	p2->displayResults();

	//end of game, player leaves
	delete p1; delete p2;
	return 0;
}

inline void introduction() {
	cout << "Welcome to *Insert Name*\n"
		<< "\nHow to Play:\n"
		<< "===============\n"
		<< "   - The game is played by two players.\n"
		<< "   - Each player will pick a topic from the list provided.\n"
		<< "   - The questions generated for the quiz will be based on\n"
		<< "     the topics choosen by the players.\n"
		<< "   - The quiz will be comprised of 10 questions\n"
		<< "   - Each player will be given two *perks?*\n"
		<< "   - Correctly answered question will earn you one point, but\n"
		<< "     string together 3 correct answers to earn yourself a\n"
		<< "     score streak multiplier.\n"
		<< "\nBelow is an example of a question you might encouter along with\n"
		<< "its correct response:\n"
		<< "Which country hosted the 2010 Fifa World Cup?\n"
		<< "a) Spain\tb) Brazil\tc) South Africa\n"
		<< "Expected response: c\n\n";

}

inline void waitForEnter() {
	cout << "\nPress Enter to Play...\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

inline void questionHeader(int &i) {
	cout << "\nQuestion " << i << ":";
}