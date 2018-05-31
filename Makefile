OBJ =
flags  = -Wall -Werror -std=c99

.PHONY: clean open

default: bin/board

test: ./bin/board-test
	./bin/board-test

./bin/board: ./build/main.o ./build/board.o ./build/move_fig.o bin test
	gcc  $(flags) -o ./bin/board ./build/main.o ./build/board.o ./build/move_fig.o -lm

./build/main.o: ./src/main.c ./src/board.h build
	gcc  $(flags) -o build/main.o -c src/main.c -lm

./build/board.o: ./src/board.c ./src/board.h build
	gcc $(flags) -o ./build/board.o -c ./src/board.c -lm

./build/move_fig.o: ./src/move_fig.c ./src/move_fig.h build
	gcc $(flags) -o ./build/move_fig.o -c ./src/move_fig.c -lm

bin/board-test: ./build/main_test.o ./build/board.o ./build/move_fig.o bin
	gcc  $(flags) ./build/main_test.o ./build/board.o ./build/move_fig.o -o bin/board-test -lm

./build/main_test.o: ./test/test.c ./thirdparty/ctest.h ./src/board.h ./src/move_fig.h build
	gcc $(flags) -I thirdparty -I src -c ./test/test.c -o ./build/main_test.o -lm



build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

open:
	./bin/board