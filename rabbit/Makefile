CC=g++
CPPFLAGS=-Wall -O3 `pkg-config libSimpleAmqpClient --cflags`
LDLIBS=`pkg-config libSimpleAmqpClient --libs`

all: main

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main mainc *.o
