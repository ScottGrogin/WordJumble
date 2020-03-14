#pragma once
#include "Tuple.h"
#include <vector>
#include<string>
#include <fstream>

using std::string;
using std::vector;

class ReadJumblerFiles {
private:
	vector<Tuple<string, string>> wordsAndHints;
	bool testWord(string toTest);
	bool testHint(string toTest);
public:
	ReadJumblerFiles();
	ReadJumblerFiles(string fileName);
	void readFile(string fileName);
	vector<Tuple<string, string>> getWordsAndHints();
};

