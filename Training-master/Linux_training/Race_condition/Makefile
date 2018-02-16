all: clean build run
build:
	gcc ./src/race_condition.c -lpthread -Wall -o ./bin/race_condition.out
	gcc ./src/semaphore.c -lpthread -Wall -o ./bin/semaphore.out
	gcc ./src/mutex.c -lpthread -Wall -o ./bin/mutex.out
run:
	./bin/./race_condition.out
	./bin/./semaphore.out
	./bin/./mutex.out
clean:
	rm ./bin/*.out
