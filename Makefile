all: sfml
	./sfml

sfml: main.o
	g++ main.o -o sfml -lsfml-graphics -lsfml-window -lsfml-system


main.o: clear
	g++ -c main.cpp

clear:
	clear