#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itree.h"

#define CANT_OPCIONES 6
#define OPCION_INCORRECTA -1
#define FORMATO_INTERVALO_INCORRECTO -2 
#define DATOS_INNECESARIOS -3
#define INICIO_MAYOR_QUE_FIN -4

int verificar_opcion(char opcion[], char *opciones[], int cant_opciones){
  int i;
  for(i=0;i<cant_opciones && strcmp(opciones[i], opcion) != 0;i++);
  return i == cant_opciones ? OPCION_INCORRECTA : i;
}

int get_intervalo(Interval intervalo, int opcion){
  strtok(NULL, "[");
  char *buf = strtok(NULL, ", ");

  double numero = strtod(buf, &buf);
  if(buf == NULL && buf[0] == '\0')
    return FORMATO_INTERVALO_INCORRECTO;
  
  intervalo->bgn = numero;

  buf = strtok(NULL, "]");
  numero = strtod(buf, &buf);
  
  if(buf == NULL && buf[0] == '\0')
    return FORMATO_INTERVALO_INCORRECTO;
  
  intervalo->end = numero;
  return intervalo->bgn <= intervalo->end ? opcion : INICIO_MAYOR_QUE_FIN;
}

void interprete(char *opciones[], int cant_opciones){
  int end = 0;
  char buf[100];
  int opcion;
  char* aux;
  char enter;
  Interval intervalo = malloc(sizeof(IntervalStruct));
  ITree raiz = itree_crear();
  while(!end){
    scanf("%[^\n]%c", buf, &enter);
    aux = strtok(buf, " ");
    opcion = verificar_opcion(aux, opciones, cant_opciones);
    if(0 <= opcion && opcion <= 2)
      opcion = get_intervalo(intervalo, opcion);

    if(opcion != OPCION_INCORRECTA && opcion != FORMATO_INTERVALO_INCORRECTO){
      aux = strtok(NULL, "");
      if(aux[0] != '\0')
        opcion = DATOS_INNECESARIOS;
    }
    printf("OPCION %d\n", opcion);
    switch(opcion){
      case 0:
        raiz = itree_insertar(raiz, intervalo);
        break;
      case 1:
        raiz = itree_eliminar(raiz, intervalo);
        break;
      case 2:
        if (itree_intersectar(raiz, intervalo) != NULL)
          printf("Si\n");
        else
          printf("No\n");
        break;
      case 3:
        itree_recorrer_dfs(raiz);
        break;
      case 4:
        itree_recorrer_bfs(raiz);
        break;
      case 5:
        end = 1;
        break;
      case OPCION_INCORRECTA:
        printf("Por favor, ingrese una opcion correcta. Las opciones son:\n");
        for(int i=0;i<cant_opciones;i++)
          printf("%s\n", opciones[i]);
        break;
      case FORMATO_INTERVALO_INCORRECTO:
        printf("Por favor, ingrese el intervalo en un formato correcto. El formato esperador es:\n"
          "[inicio, fin]\n"
          "siendo cada uno de los extremos un numero con su parte decimal separada por .\n"
          "Ejemplo: [2.34, 6.21]\n");
        break;
      case DATOS_INNECESARIOS:
        printf("Por favor, no ingrese mas datos que los indicados (incluido espacios).\n");
        break;
      case INICIO_MAYOR_QUE_FIN:
        printf("Por favor, ingrese un intervalo donde el inicio sea menor o igual que el fin\n");
        break;
    } 
  }

  itree_destruir(raiz);
}

int main(){
  char *opciones[] = {
    "i",
    "e",
    "?",
    "dfs",
    "bfs",
    "salir"
  };

  interprete(opciones, CANT_OPCIONES);

  for(int i=0;i<CANT_OPCIONES;i++)
    free(opciones[i]);

  return 0;
}