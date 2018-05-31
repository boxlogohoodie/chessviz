lags = -g3 -O0 -Wall -Werror

./bin/board :bin ./build/main.o ./build/board.o
	gcc $(flags) -o ./bin/board ./build/main.o ./build/board.o -lm

./build/main.o : build ./src/main.c ./src/board.h
	gcc $(flags) -o ./build/main.o -c ./src/main.c

./build/board.o : build ./src/board.c ./src/board.h
	gcc $(flags) -o ./build/board.o -c ./src/board.c


bin:
	mkdir bin

build:
	mkdir build

.PHONY: clean open gdb

clean:
	rm -rf ./build/ ./bin/
open:
	./bin/board
gdb:
	./bin/board