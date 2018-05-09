SRC_PATH = ./src/
TEST_PATH = ./test/

all: kmpAlgorythm checkCyclicShift tests

kmpAlgorythm : basicFunc.o kmpAlgorythm.o
	g++ kmpAlgorythm.o basicFunc.o -o kmpAlgorythm -std=c++11 -Wall

checkCyclicShift : basicFunc.o checkCyclicShift.o
	g++ checkCyclicShift.o basicFunc.o -o checkCyclicShift -std=c++11 -Wall

tests : basicFunc.o tests.o
	g++ tests.o basicFunc.o -o tests -std=c++11 -Wall

compare: basicFunc.o cmpNaive_KMP.o
	g++ basicFunc.o cmpNaive_KMP.o -o compare -std=c++11 -Wall

cmpNaive_KMP.o : $(TEST_PATH)cmpNaive_KMP.cpp
	g++ -c $(TEST_PATH)cmpNaive_KMP.cpp -std=c++11 -Wall

kmpAlgorythm.o: $(SRC_PATH)kmpAlgorythm.cpp
	g++ -c $(SRC_PATH)kmpAlgorythm.cpp -std=c++11 -Wall

basicFunc.o: $(SRC_PATH)basicFunc.cpp 
	g++ -c $(SRC_PATH)basicFunc.cpp -std=c++11 -Wall


checkCyclicShift.o: $(SRC_PATH)checkCyclicShift.cpp
	g++ -c $(SRC_PATH)checkCyclicShift.cpp -std=c++11 -Wall

tests.o: $(TEST_PATH)tests.cpp
	g++ -c $(TEST_PATH)tests.cpp -std=c++11 -Wall

clean:
	rm -rf $(wildcard *.o)

cleanAll: clean
	rm -rf kmpAlgorythm checkCyclicShift tests compare
