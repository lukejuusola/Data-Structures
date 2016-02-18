SRCDIR = src
OBJDIR = obj
BINDIR = bin
DOCDIR = doc

CC = g++ 
DOCGEN = doxygen

TESTFLAGS = -c --std=c++11 -Wall -g
MODFLAGS = -fPIC -g -c --std=c++11 -Wall
LIBFLAGS = -shared

LOCS = -Lobj

LIB =libdatastructs
LIBNAME = $(OBJDIR)/libdatastructs.so
DOCGENFLAGS =
COMMON_SRCS =
MODULEOBJS = linkedlist.o
MODSNDIR = $(OBJDIR)/linkedlist.o

BYE=$(CC) $(TESTFLAGS) -o $(OBJDIR)/linkedlist_test.o $(SRCDIR)/linkedlist_test.cpp

linkedlist.o :
	$(CC) $(MODFLAGS) -o $(OBJDIR)/linkedlist.o $(SRCDIR)/linkedlist.cpp
linkedlist-test: library
	$(CC) $(LOCS) --std=c++11 -o  $(BINDIR)/linkedlist_test $(SRCDIR)/linkedlist_test.cpp -ldatastructs
library: linkedlist.o
	$(CC) $(LIBFLAGS) -o $(LIBNAME) $(MODSNDIR)
docs: 
	doxygen Doxyfile
clean-docs:
	rm -r doc/
	mkdir doc/
clean:
	rm $(OBJDIR)/*
	rm $(BINDIR)/*
	rm *~
	rm $(SRCDIR)/*~
clean-all: clean-docs clean