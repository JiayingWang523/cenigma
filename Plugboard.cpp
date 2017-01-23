#include "Plugboard.h"

Plugboard::Plugboard(char* pd) {
	fileName = pd;
	readPlugboard();
}

char Plugboard::plugboardEncryption(char codeElem) {
	int changePosition = findChangePosition(codeElem);
	if (changePosition != -1) {
		codeElem = changePosition + 'A';
	}
	return codeElem;
}

void Plugboard::readPlugboard() {
	ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		int i = 0;
		while (!file.eof()) {
			int temp;
			file >> temp;
			plugboardCommand.push_back(temp);
		}
	} else {
		cout << "Cannot open plugboard file" << endl;
	}
	file.close();
}

int Plugboard::findChangePosition(char codeElem) {
	int position = -1;
	int i = 0;
	while (i < plugboardCommand.size() && plugboardCommand.size() != 1) {
		if (plugboardCommand[i] == codeElem - 'A') {
			if (i % 2 == 0) {
				i++;
			} else {
				i--;
			}
			position = plugboardCommand.at(i);
			break;
		}
		i++;
	}
	return position;
}
