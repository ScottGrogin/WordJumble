#include "ReadJumblerFiles.h"
#include <iostream>

using std::getline;
using std::cout;
using std::endl;
using std::ifstream;
void ReadJumblerFiles::readFile(string fileName) {
	ifstream inputFile(fileName);
	if (inputFile.is_open()) {
		string line;

		while (getline(inputFile, line)) {
			size_t pos = 0;
			string word = line.substr(0, pos = line.find(":"));
			string hint = line.erase(0, pos + 1);
			//find() returns npos if it didnt find ":"
			if (!(pos == string::npos) && testWord(word) && testHint(hint)) {
				wordsAndHints.emplace_back(word, hint);
			} else {
				cout << "Error reading file, make sure each Word:Hint pair is formated correctly." << endl;
				break;
			}
		}
		inputFile.close();
	} else {
		cout << "Could not open file: " + fileName << endl;
	}
}

bool ReadJumblerFiles::testWord(string toTest) {
	if (toTest.empty())return false;

	for (size_t i = 0; i < toTest.length(); i++) {
		if (toTest[i] == ' ')return false;
	}

	return true;
}
bool ReadJumblerFiles::testHint(string toTest) {
	if (toTest.empty())return false;
	if (toTest[0] == ' ')return false;
	return true;
}
ReadJumblerFiles::ReadJumblerFiles() {
}
ReadJumblerFiles::ReadJumblerFiles(string fileName){
	readFile(fileName);
}

vector<Tuple<string, string>> ReadJumblerFiles::getWordsAndHints() {
	return wordsAndHints;
}
