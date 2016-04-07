CC=g++
CPPFLAGS=-Wall -O3 -std=c++11
LDLIBS=
LDFLAGS=-lboost_program_options

all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main *.o
