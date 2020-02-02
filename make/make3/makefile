# A makefile using variables to simplify rules
# Tasks:
# - $@ the name of the file to be made
# - $^ the names of all dependents
# - $< the names of the changed dependends


.DEFAULT_GOAL = main
CC = gcc

OBJECTS = main.o hello.o

main: $(OBJECTS)
	@echo "Building main..."
	$(CC) -o main $(OBJECTS)

hello.o: hello.c hello.h
	@echo "Building hello.o..."
	$(CC) -c hello.c

main.o: main.c hello.h
	@echo "Building main.o..."
	$(CC) -c main.c

.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -v main *.o
