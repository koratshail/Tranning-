all: clean build run
clean:
	rm ./bin/*.out
build:
	gcc ./src/server2.c -o ./bin/server.out -lpthread -Wall
run:
	echo "TO run the program enter below command"
	echo "./bin/server.out <server_ip> <port_number>"
##	./bin/server.out
