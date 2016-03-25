CC=g++
CPPFLAGS=-Wall -O3 -std=c++11 `pkg-config libpqxx --cflags`
LDLIBS=`pkg-config libpqxx --libs`

all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main *.o
