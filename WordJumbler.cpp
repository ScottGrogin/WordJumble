#include "WordJumbler.h"
#include<iostream>
#include <ctime>
#include<cstdlib>
using std::to_string;
using namespace std;

WordJumbler::WordJumbler() {
	srand(static_cast<unsigned int>(time(0)));
}

std::string WordJumbler::jumble(std::string word) {
	string originalWord = word;
	do {
		for (string::size_type i = 0; i < word.length(); i++) {
			int j = rand() % word.length();
			char temp = word[j];
			word[j] = word[i];
			word[i] = temp;
		}
	} while (originalWord == word); //Makes sure "Jumbled" word is not the same as the one we put in.
	return word;
}
