# Minimal makefile
# FOR ANY PROJECTS

PROGRAM = prog
FILES.cpp = main.cpp Complex.cpp
FILES.h = 
FILES.o = $(FILES.cpp:.cpp=.o)

CC 		= g++
LDFLAGS	= 
LDLIBS		= 
INCFLAGS	= 
INCLUDE	= 

all: $(PROGRAM)

$(PROGRAM): $(FILES.o)
	$(CC) $(FILES.o) -o $@ $(LDFLAGS) $(LDLIBS)

.cpp.o:
	$(CC) -c $< -o $@ $(INCFLAGS) $(INCLUDE)

clean:
	rm -f $(PROGRAM)
	rm -f $(FILES.o)
