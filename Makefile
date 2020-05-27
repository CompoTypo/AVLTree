build:
	g++ src/* -o dist/avl.o -g

run:
	./dist/avl.o ./data/books.txt

debug:
	gdb dist/avl.o