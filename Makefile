all: bin/Sorting-the-input-data

bin/Sorting-the-input-data: build/src/main.o build/src/sorts.o
	gcc -Wall -Werror build/src/main.o build/src/sorts.o -o bin/Sorting-the-input-data

build/src/main.o: src/main.c src/sorts.h
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/sorts.o: src/sorts.c src/sorts.h
	gcc -Wall -Werror -c src/sorts.c -o build/src/sorts.o

test: build/test build/test/main_test.o build/test/sort_test.o
	gcc -Wall -Werror build/test/*.o build/src/sorts.o -o bin/test

build/test:
	mkdir -p build/test

build/test/main_test.o: test/main_test.c
	gcc -Wall -Werror -c test/main_test.c -o build/test/main_test.o

build/test/sort_test.o: test/sort_test.c
	gcc -Wall -Werror -c test/sort_test.c -o build/test/sort_test.o

clean:

	rm -rf build/src/*.o bin/Sorting-the-input-data bin/test

.PHONY: clean all

run:
	./bin/Sorting-the-input-data

run_test:
	./bin/test
