ARBOL = itree
COLA = cola
FLAGS = -Wall -Wextra -Werror -std=c99 -g
SALIDA = main
PROGRAMA = main.c

all: $(ARBOL).o $(COLA).o main

$(ARBOL).o: $(ARBOL).c $(ARBOL).h $(COLA).h 
	gcc $(FLAGS) -c $(ARBOL).c

$(COLA).o: $(COLA).c $(ARBOL).h $(COLA).h
	gcc $(FLAGS) -c $(COLA).c

main: main.c $(ARBOL).o $(COLA).o 
	gcc $(FLAGS) -o $(SALIDA) ./$(PROGRAMA) $(ARBOL).o $(COLA).o

clean: 
	rm *.o $(SALIDA) vgcore*