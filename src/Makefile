.DEFAULT_GOAL := main

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = g++
endif
ifeq ($(UNAME_S),Darwin)
	CC = clang++
endif

CCFLAGS = -std=c++11

main.o: main.cpp
	${CC} ${CCFLAGS} -c main.cpp

./comm/comm.o: ./comm/comm.cpp
	${CC} ${CCFLAGS} -c ./comm/comm.cpp -o ./comm/comm.o

main: main.o ./comm/comm.o
	${CC} ${CCFLAGS} -o main main.o ./comm/comm.o

clean:
	rm main.o
	rm ./comm/comm.o
	
