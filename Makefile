all: 
	g++ main.cpp cards.cpp utility.cpp -o game

game:
	g++ main.cpp cards.cpp utility.cpp  -o game

tests: 
	g++ tests.cpp cards.cpp utility.cpp -o tests
	./tests

clear: 
	rm a.out game tests