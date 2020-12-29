# $@ the current target file
# $^ all sources listed for the current target
# $< the first (left-most) source for the current 

FLAGS = -Wall -g
CC = gcc
AR = ar

PROGRAM = main
OBJECTS_MAIN = isort
MYOBJECTS = isort.o

run: $(PROGRAM)
	./$<
all: $(PROGRAM)

$(PROGRAM) : $(MYOBJECTS)
	gcc $(FLAGS) -o $@ $^

%.o : %.c
	gcc $(FLAGS) -c $<

PHONY: run, clean, all

clean:
	rm -f *.o *.a *.so $(PROGRAM)

delo:
	rm -f *.o