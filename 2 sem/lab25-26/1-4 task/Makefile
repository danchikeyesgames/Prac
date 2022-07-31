CC = gcc
.PHONY: build clean run
build: start

start: obj obj/main.o obj/stack.o
	$(CC) obj/main.o obj/stack.o -o start

obj: 
	mkdir obj

obj/main.o: main.c
	$(CC) -c main.c -o obj/main.o

obj/stack.o: stack.c
	$(CC) -c stack.c -o obj/stack.o

clean:
	rm -rf obj start

run: start
	./start