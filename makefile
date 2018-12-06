all:
	g++ src/main.cpp -o main -Wall
run:
	./main < input/input.txt > output.txt
vald:
	valgrind ./main < input/input.txt
check:
	valgrind --leak-check=full --show-leak-kinds=all src/main < input/input.txt