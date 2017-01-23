#ifndef ROTOR_H_
#define ROTOR_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Rotor {
public:
	Rotor(char* rot);
	char rotorEncryption(char codeElem);
	void rotate();
	int getRotation();
	void setRotationToZero();

private:
	char* fileName;
	void readRotor();
	void calculateDifference();
	vector<int> rotorCommand;
	vector<int> forwardDifference;
	vector<int> backwardDifference;
	int* rotation;
	bool* forward;
};

#endif
