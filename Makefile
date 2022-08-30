#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall

#sources of input
SOURCES = main.cpp  ./lib/strAlg/strAlg.cpp  ./lib/strlib/strlib.cpp

#sources of output
EXECUTABLE = corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm