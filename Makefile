SRCDIR = src
OBJDIR = obj
BINDIR = bin
DOCDIR = doc

CC = g++ 
DOCGEN = doxygen
CPPFLAGS = -c -std=c++11 -Wall -g
DOCGENFLAGS =
COMMON_SRCS =
 
linkedlist :
	$(CC) $(CPPFLAGS) -o $(OBJDIR)/linkedlist.o $(SRCDIR)/linkedlist.cpp

clean:
	rm $(OBJDIR)/*
	rm $(BINDIR)/*
