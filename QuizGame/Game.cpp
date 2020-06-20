#include <iostream>
#include "Player.h"
//#include "Question.h"
#include <string>
#include <fstream>

using namespace std;

inline void introduction();

int main() {
	introduction();
	//TEST CODE ON THE PLAYER CLASS
	Player *p1 = new Player("AJS");
	Player *p2 = new Player("AM");
	p1->displayResults();
	p2->displayResults();
	delete p1; delete p2;

	std::ifstream inFile;

	inFile.open("geography.txt");
	if (inFile.is_open())
	{
		//  Comment out these lines when program is working the way you want.
		cout << "\n File Geography is open" << std::endl;
		
	}
	else
	{
		cout << "\n File Gepgraphy did not open" << std::endl;
		 // <--- Needs header files chrono" and "thread"
	
	}
	inFile.close();
	return 0;
}

void introduction() {
	cout << "Welcome to *Insert Name*\n"
		<< "\nHow to Play:\n"
		<< "===============\n"
		<< "   - The game is played by two players.\n"
		<< "   - Each player will pick a topic from the list provided.\n"
		<< "   - The questions generated for the quiz will be based on\n"
		<< "     the topics choosen by the players.\n"
		<< "   - Each player will be given two *perks?*\n"
		<< "   - Correctly answered question will earn you one point, but\n"
		<< "     string together X correct answers to earn yourself a\n"
		<< "     score streak multiplier.\n"
		<< "\nBelow is an example of a question you might encouter along with\n"
		<< "its correct response:\n"
		<< "Which country hosted the 2010 Fifa World Cup?\n"
		<< "a) Spain\tb) Brazil\tc) South Africa\n"
		<< "Expected response: c\n\n";

}