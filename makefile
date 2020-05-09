g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/SpellChecker

./bin/SpellChecker: ./build/main.o ./build/textWork.o
		$(g) $(CFLAGS) -o ./bin/SpellChecker ./build/main.o ./build/textWork.o

./build/main.o: ./src/main.cpp ./src/textWork.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/textWork.o: ./src/textWork.cpp
		$(g) $(CFLAGS) -o build/textWork.o -c src/textWork.cpp -lm

clean:
	rm -rf build/.o build/.d

run:
	./bin/SpellChecker
