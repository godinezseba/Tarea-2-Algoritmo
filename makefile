all:
	g++ src/main.cpp -o main -Wall
run:
	./main < input.txt
vald:
	valgrind ./main < input.txt