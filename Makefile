all: step1.o kmp.o step2.o test.o
	g++ step1.o -o step1 kmp.o
	g++ step2.o -o step2 kmp.o
	g++ tests.o -o tests kmp.o
step1.o: ./src/step1.cpp
	g++ -c -std=c++11 ./src/step1.cpp
kmp.o: ./src/kmp.cpp
	g++ -c -std=c++11 ./src/kmp.cpp
step2.o: ./src/step2.cpp
	g++ -c -std=c++11 ./src/step2.cpp
test.o: ./test/tests.cpp
	g++ -c -std=c++11 ./test/tests.cpp

clean:
	rm -rf *.o