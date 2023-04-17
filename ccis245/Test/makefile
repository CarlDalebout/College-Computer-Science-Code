# This is my first makefile

a02q01.exe: a02q01.o Fraction.o
	g++ a02q01.o Fraction.o -0 a02q01

a02q01.o: a02q01.cpp
	g++ -c a02q01.cpp

Fraction.o: Fraction.cpp Fraction.h
	g++ -c Fraction.cpp
clean:
	rm *.o hw.exe
