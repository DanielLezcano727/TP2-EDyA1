ESTRUCTURA = itree
FLAGS = -Wall -Wextra -Werror -std=c99 -g

all: $(ESTRUCTURA).o main

$(ESTRUCTURA).o: $(ESTRUCTURA).c $(ESTRUCTURA).h
	gcc $(FLAGS) -c $(ESTRUCTURA).c

main: main.c $(ESTRUCTURA).o
	gcc $(FLAGS) -o main ./main.c $(ESTRUCTURA).o

clean: 
	rm *.o main vgcore*