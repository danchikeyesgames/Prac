CC=g++
FLAGS=-std=c++11 -c

FILESNAME=main.cpp point.cpp hexagon.cpp
OBJECTS=main.o point.o hexagon.o

build: $(OBJECTS)
	$(CC) main.o point.o hexagon.o triangle.o octagon.o -o a.out

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

point.o: point.cpp
	$(CC) $(FLAGS) point.cpp

hexagon.o: hexagon.cpp
	$(CC) $(FLAGS) hexagon.cpp

clear: $(OBJECTS) a.out
	rm -rf $(OBJECTS) a.out