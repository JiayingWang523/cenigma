#include "Rotor.h"

Rotor::Rotor(char* rot) {
	fileName = rot;
	readRotor();
	calculateDifference();
	rotation = new int(0);
	forward = new bool(true);
}

char Rotor::rotorEncryption(char codeElem) {
	const int alphabet = 26;
	int difference;
	int tempElem;

	if (*forward) {
		tempElem = codeElem - 'A';
		difference = forwardDifference.at(tempElem);
		codeElem = codeElem + difference - 'A';
		if (codeElem < 0) {
			codeElem = codeElem + alphabet;
		}
		codeElem = codeElem % alphabet + 'A';
	} else {
		int position;
		tempElem = (codeElem - 'A' + *rotation) % alphabet;
		for (int i = 0; i < alphabet; i++) {
			if (rotorCommand[i] == tempElem) {
				position = i;
				break;
			}
		}
		difference = backwardDifference.at(position);
		codeElem = codeElem + difference - 'A';
		if (codeElem < 0) {
			codeElem = codeElem + alphabet;
		}
		codeElem = codeElem % alphabet + 'A';
	}
	*forward = !*forward;
	return codeElem;
}

void Rotor::rotate() {
	int front = forwardDifference.front();
	forwardDifference.erase(forwardDifference.begin());
	forwardDifference.push_back(front);

	*rotation = *rotation + 1;
}

int Rotor::getRotation() {
	return *rotation;
}

void Rotor::setRotationToZero() {
	*rotation = 0;
}

void Rotor::readRotor() {
	ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		int i = 0;
		while (!file.eof()) {
			int temp;
			file >> temp;
			rotorCommand.push_back(temp);
		}
	} else {
		cout << "Cannot open rotor file!" << endl;
	}
	file.close();
}

void Rotor::calculateDifference() {
	const int alphabet = 26;
	for (int i = 0; i < alphabet; i++) {
		forwardDifference.push_back(rotorCommand.at(i) - i);
		backwardDifference.push_back(i - rotorCommand.at(i));
	}
}
