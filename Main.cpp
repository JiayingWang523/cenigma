#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

int main(int argc, char **argv) {

	if (argc == 1) {
		throw runtime_error("Not enough argument!");
	}

	int numRotor = argc - 2;
	vector<Rotor> rotor;
	for (int j = 1; j < argc - 1; j++) {
		rotor.push_back(Rotor(argv[j]));
	}
	Plugboard* plugboard = new Plugboard(argv[argc - 1]);
	Reflector* reflector = new Reflector();

	char codeElem;
	while (cin >> codeElem) {
		if (codeElem == '\n' || codeElem == EOF) {
			break;
		}

		if ('A' <= codeElem <= 'Z') {
			codeElem = plugboard->plugboardEncryption(codeElem);
			for (int i = 0; i < numRotor; i++) {
				codeElem = rotor[i].rotorEncryption(codeElem);
			}
			codeElem = reflector->reflectorEncryption(codeElem);
			for (int j = numRotor - 1; j >= 0; j--) {
				codeElem = rotor[j].rotorEncryption(codeElem);
			}
			codeElem = plugboard->plugboardEncryption(codeElem);

			if (numRotor != 0) {
				rotor[0].rotate();
			}
			for (int r = 0; r < numRotor; r++) {
				if (rotor[r].getRotation() == 26) {
					if (r != numRotor - 1) {
						rotor[r + 1].rotate();
					}
					rotor[r].setRotationToZero();
				}
			}
		}

		cout << codeElem;
	}
	cout << endl;
	return 0;
}
