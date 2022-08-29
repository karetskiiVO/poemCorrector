#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall

strlib_ = lib/strlib/strlib.cpp
strAlg_ = lib/strAlg/strAlg.cpp

#sources of input
SOURCES = main.cpp  $(strlib_)  $(strAlg_)

#sources of output
EXECUTABLE = calc

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm