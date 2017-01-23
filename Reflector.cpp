#include "Reflector.h"

Reflector::Reflector() {
}

char Reflector::reflectorEncryption(char codeElem) {
	codeElem = (codeElem - 'A' + 13) % 26 + 'A';
	return codeElem;
}
