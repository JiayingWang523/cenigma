# edit this makefile so that running make compiles your enigma program

enigma: Main.o Rotor.o Plugboard.o Reflector.o
	g++ -o enigma Main.o Rotor.o Plugboard.o Reflector.o

Main.o: Main.cpp
	g++ -c Main.cpp

Rotor.o: Rotor.cpp
	g++ -c Rotor.cpp

Plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp

Reflector.o: Reflector.cpp
	g++ -c Reflector.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
