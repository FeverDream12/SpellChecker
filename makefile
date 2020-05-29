g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/SpellChecker

./bin/SpellChecker: ./build/main.o ./build/textWork.o build/source.o
		$(g) $(CFLAGS) -o ./bin/SpellChecker ./build/main.o ./build/textWork.o build/source.o

./build/main.o: ./src/main.cpp ./src/textWork.h ./src/source.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/textWork.o: ./src/textWork.cpp
		$(g) $(CFLAGS) -o build/textWork.o -c src/textWork.cpp -lm

./build/source.o: ./src/source.cpp ./src/textWork.h
		$(g) $(CFLAGS) -o build/source.o -c src/source.cpp -lm

test: bin/spell-test testRun

bin/spell-test: build/test/main.o build/source.o build/textWork.o
		$(g) -o bin/spell-test build/test/main.o build/source.o build/textWork.o

build/test/main.o: test/main.cpp
		$(g) $(CFLAGS) -o build/test/main.o -c test/main.cpp

testRun:
	./bin/spell-test

clean:
	rm -rf build/*.o build/*.d

run:
	./bin/SpellChecker
