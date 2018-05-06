PATH=src/

all: step1 step2 test
	
step1 : kmp.o step1.o
	g++ step1.o kmp.o -o step1 	

step2 : kmp.o step2.o
	g++ step2.o kmp.o -o step2 

test : kmp.o tests.o
	g++ tests.o kmp.o -o tests

step1.o: $(PATH)step1.cpp
	g++ -c $(PATH)step1.cpp 

kmp.o: $(PATH)kmp.cpp
	@echo "$(PATH)"
	g++ -c $(PATH)kmp.cpp -std=c++11 


step2.o: $(PATH)step2.cpp
	g++ -c -std=c++11 $(PATH)step2.cpp

test.o: ./test/tests.cpp
	g++ -c -std=c++11 ./test/tests.cpp

clean:
	rm -rf *.o
