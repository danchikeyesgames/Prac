CC=gcc

FILESNAME=src/TransformToTree.c src/main.c src/TreeExpressions.c src/VectorTransformNumberChar.c
OBJECTS=obj/TransformToTree.o obj/main.o obj/TreeExpressions.o obj/VectorTransformNumberChar.o

build: obj $(OBJECTS)
	$(CC) $(OBJECTS) -o build

obj: obj
	mkdir obj

obj/TransformToTree.o: src/TransformToTree.c
	$(CC) -c src/TransformToTree.c -o obj/TransformToTree.o

obj/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o

obj/TreeExpressions.o: src/TreeExpressions.c
	$(CC) -c src/TreeExpressions.c -o obj/TreeExpressions.o

obj/VectorTransformNumberChar.o: src/VectorTransformNumberChar.c
	$(CC) -c src/VectorTransformNumberChar.c -o obj/VectorTransformNumberChar.o

run: build
	./build

clean:
	rm -rf obj build