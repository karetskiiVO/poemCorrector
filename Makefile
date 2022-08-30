#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall

strlib_ = -I/lib/strlib/strlib.cpp
strAlg_ = -I/lib/strAlg/strAlg.cpp

#sources of input
SOURCES = main.cpp  $(strlib_)  $(strAlg_)

#sources of output
EXECUTABLE = corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm