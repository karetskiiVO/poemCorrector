#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall 

#sources of input
SOURCES = main.cpp  strAlg.cpp  strlib.cpp  poemMaker.cpp

#sources of output
EXECUTABLE = corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm