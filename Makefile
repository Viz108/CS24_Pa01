all: 
	g++ main.cpp cards.cpp intbst.cpp

game:
	g++ main.cpp cards.cpp intbst.cpp -o game

tests: 
	g++ tests.cpp cards.cpp intbst.cpp -o tests

clear: 
	rm a.out game tests