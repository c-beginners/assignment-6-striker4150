CPP = g++
CPPFLAGS = -g -std=c++11
PROGS = gullible.exe

# Cross-OS clean
ifdef OS
	RM = del /Q
else
	RM = rm -f
endif

.PHONY: all clean

all: $(PROGS)

gullible.exe: gullible.cpp
	$(CPP) $(CPPFLAGS) -o gullible.exe gullible.cpp

clean:
	$(RM) $(PROGS) *.o