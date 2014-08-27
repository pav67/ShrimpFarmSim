GCC=gcc
RM=rm
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LDFLAGS=-g
FLAGS=-I. -g
EXEC=main
 
all : $(EXEC)

%.o : %.c
	$(GCC) -c $^ -o $@ $(FLAGS)

$(EXEC) : $(OBJ)
	$(GCC) $^ -o $@ $(LDFLAGS)

.PHONY: clean 

clean : 
	$(RM) *.o
	$(RM) $(EXEC)
