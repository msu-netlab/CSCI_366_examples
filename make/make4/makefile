# A makefile using suffix rules (deduce)
# Tasks:
# - combine by prerequisites
# - make -t to prevent recompilation after unsubstantial changes to header files

.DEFAULT_GOAL = main
$(CC) = gcc

OBJECTS = main.o hello.o

main: $(OBJECTS)
	@echo "Building main..."
	$(CC) -o $@ $^

main.o: hello.h

hello.o: hello.h

.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -v main *.o
