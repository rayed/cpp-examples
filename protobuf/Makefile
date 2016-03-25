CC=g++
CPPFLAGS=-Wall -O3 -std=c++11  `pkg-config --cflags protobuf`
LDLIBS=`pkg-config --libs protobuf`

all: main

addressbook.pb.o : addressbook.proto
	protoc --cpp_out=. $^
	$(CC) $(CPPFLAGS) -c -o $@ addressbook.pb.cc

main: main.o addressbook.pb.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm main *.o addressbook.pb.*
