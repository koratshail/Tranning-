all: clean build run
build:
	gcc ./src/ex_4.c -o ./bin/ex_4.out -Wall
	gcc ./src/ex_5.c -o ./bin/ex_5.out -lm -Wall
	gcc ./src/ex_11.c -o ./bin/ex_11.out -Wall
	gcc ./src/ex_12.c -o ./bin/ex_12.out -Wall
run:
	./bin/./ex_4.out
	./bin/./ex_5.out
	./bin/./ex_11.out
	./bin/./ex_12.out
clean:
	rm ./bin/*.out
