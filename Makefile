all: bstDemo.c bst.c
	gcc -o bstDemo bstDemo.c bst.c -I.

demo: all
	./bstDemo
