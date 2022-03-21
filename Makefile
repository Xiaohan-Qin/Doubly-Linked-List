sort: main.c sort.c linkedlist.c
	gcc main.c sort.c linkedlist.c -o sort

test: test.c linkedlist.c
	gcc test.c linkedlist.c -o tests

run_sort:
	./sort

run_test:
	./tests
