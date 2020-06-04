#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itree.h"

#define CANT_OPCIONES 6
#define OPCION_INCORRECTA -1
#define FORMATO_INTERVALO_INCORRECTO -2 
#define DATOS_INNECESARIOS -3
#define INICIO_MAYOR_QUE_FIN -4
#define FALTA_OPCION -5

int verificar_opcion(char opcion[], char *opciones[], int cant_opciones){
  if(opcion == NULL)
    return FALTA_OPCION;
  int i;
  for(i=0;i<cant_opciones && strcmp(opciones[i], opcion) != 0;i++);
  return i == cant_opciones ? OPCION_INCORRECTA : i;
}

int get_intervalo(Interval intervalo, int opcion){
  char *buf = strtok(NULL, ", ");
  
  if(buf[0] != '[')
    return FORMATO_INTERVALO_INCORRECTO;

  double numero = strtod(buf+1, &buf);
  if(buf[0] != '\0')
    return FORMATO_INTERVALO_INCORRECTO;
  
  intervalo->bgn = numero;

  buf = strtok(NULL, "");
  numero = strtod(buf, &buf);
  
  if(buf[0] != ']')
    return FORMATO_INTERVALO_INCORRECTO;
  
  if(buf[1] != '\0')
    return DATOS_INNECESARIOS;

  intervalo->end = numero;
  return intervalo->bgn <= intervalo->end ? opcion : INICIO_MAYOR_QUE_FIN;
}

void interprete(char *opciones[], int cant_opciones){
  int end = 0, opcion;
  char buf[100];
  char* ptr;

  Interval intervalo = malloc(sizeof(IntervalStruct));
  ITree raiz = itree_crear();

  while(!end){
    scanf("%[^\n]", buf);
    getchar();

    ptr = strtok(buf, " ");
    
    opcion = verificar_opcion(ptr, opciones, cant_opciones);

    if(0 <= opcion && opcion <= 2)
      opcion = get_intervalo(intervalo, opcion);

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
        printf("Por favor, ingrese el intervalo en un formato correcto. El formato esperado es:\n"
          "[inicio, fin]\n"
          "siendo cada uno de los extremos un numero con su parte decimal separada por .\n"
          "Ejemplo: [2.34, 6.21]\n");
        break;
      case DATOS_INNECESARIOS:
        printf("Por favor, no ingrese mas datos que los indicados (incluyendo espacios).\n");
        break;
      case INICIO_MAYOR_QUE_FIN:
        printf("Por favor, ingrese un intervalo donde el inicio sea menor o igual que el fin\n");
        break;
      case FALTA_OPCION:
        printf("Por favor, ingrese un comando\n");
        break;
    } 
  }
  
  free(intervalo);
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
  return 0;
}