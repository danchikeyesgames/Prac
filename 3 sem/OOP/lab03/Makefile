CC=g++
FLAGS=-std=c++11 -c

FILESNAME=main.cpp point.cpp hexagon.cpp triangle.cpp octagon.cpp
OBJECTS=main.o point.o hexagon.o triangle.o octagon.o

build: $(OBJECTS)
	$(CC) main.o point.o hexagon.o triangle.o octagon.o -o a.out

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

point.o: point.cpp
	$(CC) $(FLAGS) point.cpp

hexagon.o: hexagon.cpp
	$(CC) $(FLAGS) hexagon.cpp

triangle.o: triangle.cpp
	$(CC) $(FLAGS) triangle.cpp

octagon.o: octagon.cpp
	$(CC) $(FLAGS) octagon.cpp

clear: $(OBJECTS) a.out
	rm -rf $(OBJECTS) a.out