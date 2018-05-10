SRC_PATH = ./src/
TEST_PATH = ./test/

all: kmpAlgorythm checkCyclicShift tests compare

kmpAlgorythm : basicFunc.o kmpAlgorythm.o
	g++ $^ -o $@ -std=c++11 -Wall

checkCyclicShift : basicFunc.o checkCyclicShift.o
	g++ $^ -o $@ -std=c++11 -Wall

tests : basicFunc.o tests.o
	g++ $^ -o $@ -std=c++11 -Wall

compare: basicFunc.o cmpNaive_KMP.o
	g++ $^ -o $@ -std=c++11 -Wall

%.o : $(SRC_PATH)%.cpp
	g++ -c $^ -o $@ -std=c++11 -Wall

%.o : $(TEST_PATH)%.cpp
	g++ -c $< -o $@ -std=c++11 -Wall

clean:
	rm -rf $(wildcard *.o)

cleanAll: clean
	rm -rf kmpAlgorythm checkCyclicShift tests compare
