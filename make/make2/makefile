# A makefile building objects to allow partial recompilation
# Tasks:
# - CC, CFLAGS 
# - .DEFAULT_GOAL
# - .PHONY:

main: main.o hello.o
	@echo "Building main..."
	gcc -o main main.o hello.o

hello.o: hello.c hello.h
	@echo "Building hello.o..."
	gcc -c hello.c

main.o: main.c hello.h
	@echo "Building main.o..."
	gcc -c main.c

clean:
	@echo "Cleaning up..."
	rm -v main *.o
