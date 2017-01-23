#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Plugboard {
public:
	Plugboard(char* pd);
	char plugboardEncryption(char codeElem);

private:
	char* fileName;
	vector<int> plugboardCommand;
	void readPlugboard();
	int findChangePosition(char codeElem);
};

#endif
