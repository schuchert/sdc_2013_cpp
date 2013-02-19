RPNLIBSRC = $(shell find . -name \*.cpp)

OBJ = $(RPNLIBSRC:.cpp=.o)
RPNLIB = librpn.a
CFLAGS = -Wall -g -std=c++11

LIBS = -L./ -L../cpputest/lib -lm
LDFLAGS = -g
CC=g++

.SUFFIXES: .cpp

default: $(RPNLIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(RPNLIB): $(OBJ)
	ar rcs $(RPNLIB) $(OBJ)

clean:
	rm -f $(OBJ) $(OUT) Makefile.bak 