.DEFAULT_GOAL := main

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = g++
	LDFLAGS = -pthread -lpthread
endif
ifeq ($(UNAME_S),Darwin)
	CC = clang++
	IFLAGS = -I /opt/homebrew/Cellar/boost/1.80.0/include
endif

CCFLAGS = -std=c++11

main.o: main.cpp
	${CC} ${CCFLAGS} ${LDFLAGS} ${IFLAGS} -c main.cpp

./comm/comm.o: ./comm/comm.cpp
	${CC} ${CCFLAGS} ${LDFLAGS} ${IFLAGS} -c ./comm/comm.cpp -o ./comm/comm.o

./utils/network/networkUtils.o: ./utils/network/networkUtils.cpp
	${CC} ${CCFLAGS} ${LDFLAGS} ${IFLAGS} -c ./utils/network/networkUtils.cpp -o ./utils/network/networkUtils.o

main: main.o ./comm/comm.o ./utils/network/networkUtils.o
	${CC} ${CCFLAGS} ${LDFLAGS} ${IFLAGS} -o main main.o ./comm/comm.o ./utils/network/networkUtils.o

clean:
	rm main.o
	rm ./comm/comm.o
	rm ./utils/network/networkUtils.o
	
