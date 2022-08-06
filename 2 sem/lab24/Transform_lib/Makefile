CC=gcc
NAMEFILES = src/TransformToTree.c src/TreeExpressions.c src/VectorTransformNumberChar.c src/main.c
NAMEOBJECTS = obj/TransformToTree.o obj/TreeExpressions.o obj/VectorTransformNumberChar.o obj/main.o
OFLAG=-o

build: start

start: $(NAMEOBJECTS)
	$(CC) $^ -o start

obj:
	mkdir obj

obj/TransformToTree.o: obj src/TransformToTree.c
	$(CC) -c src/TransformToTree.c -o obj/TransformToTree.o

obj/TreeExpressions.o: obj src/TreeExpressions.c
	$(CC) -c src/TreeExpressions.c -o obj/TreeExpressions.o

obj/VectorTransformNumberChar.o: obj src/VectorTransformNumberChar.c
	$(CC) -c src/VectorTransformNumberChar.c -o obj/VectorTransformNumberChar.o

obj/main.o: obj src/main.c
	$(CC) -c src/main.c -o obj/main.o

run:
	./start

clean:
	rm -rf obj start