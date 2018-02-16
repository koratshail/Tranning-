CC=gcc
CFLAG=-c -Wall
SOURCE=Single_ll.c
OBJECTS=$(SOURCE:.c=.o)
EXECUTABLE=test

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^
%.o : %.c
	$(CC) $(CFLAG) $<
clean:
	rm -f *.o $(EXECUTABLE)
all:
	./$(EXECUTABLE)


