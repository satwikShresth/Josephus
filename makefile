CC=gcc
OBJ=obj
BIN=bin

all: bin/queueTests bin/josephus

obj/queue.o: src/queue.c src/queue.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/queue.o src/queue.c
bin/queueTests: obj/queue.o src/queueTests.c
	[ -d $(BIN) ] || mkdir -p $(BIN) 
	${CC} -o bin/queueTests obj/queue.o src/queueTests.c
bin/josephus: obj/queue.o src/josephus.c
	[ -d $(BIN) ] || mkdir -p $(BIN)
	${CC} -o bin/josephus obj/queue.o src/josephus.c

testNewQueue: bin/queueTests
  bin/queueTests 1
testEnqueue: bin/queueTests
	bin/queueTests 2
testFront: bin/queueTests
	bin/queueTests 3
testIsEmpty: bin/queueTests
	bin/queueTests 4
testDequeue: bin/queueTests
	bin/queueTests 5
testRandom: bin/queueTests
	bin/queueTests 6
testQueue: bin/queueTests
	bin/queueTests 0

joeTest01: bin/josephus
	bin/josephus 2 2
joeTest02: bin/josephus
	bin/josephus 5 2
joeTest03: bin/josephus
	bin/josephus 5 3
joeTest04: bin/josephus
	bin/josephus 7 2
joeTest05: bin/josephus
	bin/josephus 7 3
joeTest06: bin/josephus
	bin/josephus 10 2
joeTest07: bin/josephus
	bin/josephus 10 3
joeTest08: bin/josephus
	bin/josephus 10 5
joeTest09: bin/josephus
	bin/josephus 100 2
joeTest10: bin/josephus
	bin/josephus 100 10

joeTest: joeTest01 joeTest02 joeTest03 joeTest04 joeTest05 joeTest06 joeTest07 joeTest08 joeTest09 joeTest10 

clean:
	rm -f bin/queueTests
	rm -f obj/queue.o
	rm -f bin/josephus
	rm -f -d bin
	rm -f -d obj

