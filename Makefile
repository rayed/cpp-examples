CC=g++
CPPFLAGS=-Wall -O3
LDLIBS=

all: main json

main: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

json: json.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)


.PHONY: clean
clean:
	-rm main json *.o
