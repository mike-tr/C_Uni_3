# $@ the current target file
# $^ all sources listed for the current target
# $< the first (left-most) source for the current 

FLAGS = -Wall -g
CC = gcc
AR = ar

RAND_TARGET = sort_input2.txt
RAND_PROGMA = myrandinput

PROGRAM_1 = isort
MYOBJECTS_1 = isort.o

PROGRAM_2 = txtfind
MYOBJECTS_2 = txtfind.o myInputReader.o

run_s: $(PROGRAM_1) $(RAND_PROGMA)
	./$(RAND_PROGMA) > $(RAND_TARGET)
	./$< < $(RAND_TARGET)

run_f: $(PROGRAM_2)
	./$<

all: $(PROGRAM_1) $(PROGRAM_2)

$(PROGRAM_1) : $(MYOBJECTS_1)
	gcc $(FLAGS) -o $@ $^

$(PROGRAM_2) : $(MYOBJECTS_2)
	gcc $(FLAGS) -o $@ $^

$(RAND_PROGMA) : $(RAND_PROGMA).o
	gcc $(FLAGS) -o $@ $^

$(PROGRAM_1).o : $(PROGRAM_1).c
	gcc $(FLAGS) -c $<

$(PROGRAM_2).o : $(PROGRAM_2).c
	gcc $(FLAGS) -c $<

$(RAND_PROGMA).o : $(RAND_PROGMA).c
	gcc $(FLAGS) -c $<

%.o : %.c myInputReader.h
	gcc $(FLAGS) -c $< > out.txt

PHONY: run_s, run_f, clean, all, rand_input

clean:
	rm -f *.o *.a *.so $(PROGRAM_1) $(PROGRAM_2) *.exe

delo:
	rm -f *.o *.exe