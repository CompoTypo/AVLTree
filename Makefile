build:
	g++ main.cpp AVLNode.hpp AVLTree.hpp Book.hpp -o avl.o -g

run:
	./avl.o books.txt

debug:
	gdb avl.o