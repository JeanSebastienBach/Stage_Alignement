CCG=g++
SOURCE= generation.cpp
FLAGS= -ansi -pedantic -o0 -g -Wall
HEADERS=
PROG= generation
all : $(PROG)

generation.o :generation.cpp
	$(CCG) -c generation.cpp

$(PROG) : $(SOURCE:.cpp=.o)
	$(CCG) $(SOURCE:.cpp=.o) -o $(PROG)

clean :
	rm $(SOURCE:.cpp=.o)
