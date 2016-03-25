CC=g++
CPPFLAGS=-Wall -O3 -std=c++11
LDLIBS=#-lpthreads

all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main *.o
