# $@ the current target file
# $^ all sources listed for the current target
# $< the first (left-most) source for the current 

FLAGS = -Wall -g
CC = gcc
AR = ar

PROGRAM_1 = isort
MYOBJECTS_1 = isort.o

PROGRAM_2 = txtfind
MYOBJECTS_2 = txtfind.o myInputReader.o

run_s: $(PROGRAM_1)
	./$<
run_f: $(PROGRAM_2)
	./$<

all: $(PROGRAM_1) $(PROGRAM_2)

$(PROGRAM_1) : $(MYOBJECTS_1)
	gcc $(FLAGS) -o $@ $^

$(PROGRAM_2) : $(MYOBJECTS_2)
	gcc $(FLAGS) -o $@ $^

$(PROGRAM_1).o : $(PROGRAM_1).c
	gcc $(FLAGS) -c $<

$(PROGRAM_2).o : $(PROGRAM_2).c
	gcc $(FLAGS) -c $<

%.o : %.c myInputReader.h
	gcc $(FLAGS) -c $< > out.txt

PHONY: run_s, run_f, clean, all

clean:
	rm -f *.o *.a *.so $(PROGRAM_1) $(PROGRAM_2)

delo:
	rm -f *.o