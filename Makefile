GCC=gcc
RM=rm
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
LDFLAGS=-g
FLAGS=-I./header/ -I./data/ -g
EXEC=main
 
all : $(EXEC)

%.o : %.c
	$(GCC) -c $^ -o $@ $(FLAGS)

$(EXEC) : $(OBJ)
	$(GCC) $^ -o $@ $(LDFLAGS)

.PHONY: clean 

clean : 
	$(RM) src/*.o
	$(RM) $(EXEC)
