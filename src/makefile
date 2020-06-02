ESTRUCTURA1 = itree
ESTRUCTURA2 = cola
FLAGS = -Wall -Wextra -Werror -std=c99 -g

all: $(ESTRUCTURA1).o $(ESTRUCTURA2).o main

$(ESTRUCTURA1).o: $(ESTRUCTURA1).c $(ESTRUCTURA1).h $(ESTRUCTURA2).h 
	gcc $(FLAGS) -c $(ESTRUCTURA1).c

$(ESTRUCTURA2).o: $(ESTRUCTURA2).c $(ESTRUCTURA1).h $(ESTRUCTURA2).h
	gcc $(FLAGS) -c $(ESTRUCTURA2).c

main: main.c $(ESTRUCTURA1).o $(ESTRUCTURA2).o 
	gcc $(FLAGS) -o main ./main.c $(ESTRUCTURA1).o $(ESTRUCTURA2).o

clean: 
	rm *.o main vgcore*