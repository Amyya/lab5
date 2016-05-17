hugeint: lab5.o main.o
	g++ -o hugeint main.o lab5.o

lab5.o: lab5.cpp lab5.h
	g++ -c lab5.cpp

main.o: main.cpp lab5.h
	g++ -c main.cpp