#the compiler
CC := g++
 
#flags:
CFLAGS := -g -Wall -Wextra -fsanitize=address

#sources of input
SOURCES := main.cpp  textLib.cpp  algorithmics.cpp

#sources of output
EXECUTABLE := corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm