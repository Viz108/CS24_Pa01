all: 
	g++ main.cpp cards.cpp 

game:
	g++ main.cpp cards.cpp  -o game

tests: 
	g++ tests.cpp cards.cpp  -o tests

clear: 
	rm a.out game tests