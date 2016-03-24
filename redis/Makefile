CC=g++
CPPFLAGS=-Wall -O3 `pkg-config hiredis --cflags`
LDLIBS=`pkg-config hiredis --libs`

all: main 

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main mainc *.o
