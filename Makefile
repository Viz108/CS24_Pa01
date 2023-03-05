all: 
	g++ main.cpp cards.cpp intbst.cpp

cardTest:
	g++ cardTest.cpp cards.cpp 

tester:
	g++ tester.cpp cards.cpp intbst.cpp