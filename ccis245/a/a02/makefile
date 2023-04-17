# This is my first makefile

a02q01.exe: a02q01.o Fraction.o
	g++ a02q01.o Fraction.o -o a02q01.exe

a02q02.exe: a02q02.o Fraction.o
	g++ a02q02.o Fraction.o -o a02q02.exe

a02q01.o: a02q01.cpp
	g++ -c a02q01.cpp

a02q02.o: a02q02.cpp
	g++ -c a02q02.cpp

Fraction.o: Fraction.cpp Fraction.h
	g++ -c Fraction.cpp
clean:
	rm *.o a02q01.exe
