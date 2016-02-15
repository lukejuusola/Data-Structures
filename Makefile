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
linkedlist-test:
	$(CC) $(CPPFLAGS) -o $(OBJDIR)/linkedlist_test.o $(SRCDIR)/linkedlist_test.cpp
	$(CC) $(CPPFLAGS) -o $(BINDIR)/linkedlist_test $(OBJDIR)/linkedlist_test.o
docs: 
	doxygen Doxyfile
clean-docs:
	rm -r doc/
	mkdir doc/
clean:
	rm $(OBJDIR)/*
	rm $(BINDIR)/*
clean-all:
	rm -r doc/
	mkdir doc/
	rm $(OBJDIR)/*
	rm $(BINDIR)/*
	rm *~
	rm $(SRCDIR)/*~