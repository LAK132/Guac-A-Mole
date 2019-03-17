BINDIR = bin
OBJDIR = obj

CXX = g++-8 -g -std=c++17 -Wall -Werror -Wfatal-errors
COMPFLAGS = -pthread `sdl2-config --cflags`
INCDIRS = include
LIBDIRS =
LIBS = SDL2 GL dl stdc++fs

guacamole.out: | $(BINDIR) $(OBJDIR)
	$(CXX) -o $(BINDIR)/guacamole.out src/main.cpp $(COMPFLAGS) $(foreach D,$(INCDIRS),-I$D ) $(foreach D,$(LIBDIRS),-L$D ) $(foreach L,$(LIBS),-l$L )

.PHONY: guacamole.out

clean:
	rm -f $(BINDIR)/*
	rm -f $(OBJDIR)/*

$(BINDIR):
	mkdir $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)
