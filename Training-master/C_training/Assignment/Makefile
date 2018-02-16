all: clean build run 
build:
	gcc ./src/linkListFun.c -c -o ./bin/linkListFun.o -Wall
	ar -cvq ./lib/liblist.a ./bin/linkListFun.o 
##	ar -cvq ./lib/liblinkList.a ./bin/linkListFun.o
	gcc src/linkListApp.c -o ./bin/linkList.out -L ./lib/ -llist
##	gcc ./src/linkListApp.c -o ./bin/linkList.out ./lib/liblinkList.a -Wall
run:
	./bin/./linkList.out
clean:
	rm ./lib/liblinkList.a
	rm ./bin/*.o
	rm ./bin/*.out
