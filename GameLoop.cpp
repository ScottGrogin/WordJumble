#include "GameLoop.h"
#include "WordJumbler.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void GameLoop::run() {


	cout << "Welcome to word scramble!" << endl;
	string defaultChoice;
	string defaultFile = "WordFiles/defaultText.txt";
	do {
		cout << endl;
		cout << "Use default word file? (y/n)" << endl;
		getline(cin, defaultChoice);
		if (defaultChoice != "y" && defaultChoice != "n") {
			cout << "input not recognized." << endl;
		}
	} while (defaultChoice != "y" && defaultChoice != "n");
	ReadJumblerFiles rjf;
	if (defaultChoice == "y") {
		rjf.readFile(defaultFile);
	} else {
		string fileName;
		cout << "Enter the file name" << endl;
		getline(cin, fileName);
		rjf.readFile(fileName);
		if (rjf.getWordsAndHints().empty()) {
			cout << "Error... now using default list" << endl;
			rjf.readFile(defaultFile);
		}

	}

	vector<Tuple<string, string>> wordsAndHints(rjf.getWordsAndHints());
	WordJumbler jumblr;

	string playAgain;
	do {

		for (size_t i = 0; i < wordsAndHints.size(); i++) {
			Tuple<string, string> wordHint = wordsAndHints[i];
			string response;
			do {
				cout << endl;
				cout << jumblr.jumble(wordHint.x) + " Hint:" + wordHint.y << endl;
				cout << "Type in your guess, then hit enter to submit." << endl;
				getline(cin, response);
				if (response == wordHint.x) {
					cout << "Correct!" << endl;
				} else {
					cout << "Incorrect, try again" << endl;
				}

			} while (response != wordHint.x);
		}
		do {
			cout << endl;
			cout << "Congratulations! You won! Play again? (y/n)" << endl;
			getline(cin, playAgain);
			if (playAgain != "y" && playAgain != "n") {
				cout << "input not recognized." << endl;
			}
		} while (playAgain != "y" && playAgain != "n");
	} while (playAgain == "y");
}
