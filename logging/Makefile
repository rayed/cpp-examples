CC=g++
CPPFLAGS=-DBOOST_ALL_DYN_LINK -Wall -O3 -std=c++11
LDLIBS=-lboost_log-mt
LDFLAGS=-DBOOST_ALL_DYN_LINK

all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main *.o
