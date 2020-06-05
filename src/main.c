#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "itree.h"

#define CANT_OPCIONES 6
#define OPCION_INCORRECTA -1
#define FORMATO_INTERVALO_INCORRECTO -2
#define DATOS_INNECESARIOS -3
#define INICIO_MAYOR_QUE_FIN -4
#define FALTA_OPCION -5
#define FALTA_INTERVALO -6

// static void imprimir_nodo_intervalos(ITree arbol) {
//   printf("[%f %f] Mayor subintervalo: %f\n", arbol->intervalo->bgn, arbol->intervalo->end, arbol->maySub);
// }

static void imprimir_intervalo(Interval intervalo) {
  printf("[%g, %g] ", intervalo->bgn, intervalo->end);
}

int verificar_opcion(char opcion[], char *opciones[], int cant_opciones){
  if(opcion == NULL)
    return FALTA_OPCION;
  int i;
  for(i=0;i<cant_opciones && strcmp(opciones[i], opcion) != 0;i++);
  return i == cant_opciones ? OPCION_INCORRECTA : i;
}

int get_intervalo(Interval intervalo, int opcion){
  char* buf = strtok(NULL, "");
  if(buf == NULL)
    return FALTA_INTERVALO;

  if(buf[0] != '[' || !(isdigit(buf[1]) || buf[1] == '-'))
    return FORMATO_INTERVALO_INCORRECTO;

  intervalo->bgn = strtod(buf+1, &buf);
  
  if(buf[0] != ',' || buf[1] != ' ' || !(isdigit(buf[2]) || buf[2] == '-'))
    return FORMATO_INTERVALO_INCORRECTO;

  intervalo->end = strtod(buf+2, &buf);

  if(buf[0] != ']')
    return FORMATO_INTERVALO_INCORRECTO;

  if(buf[1] != '\0')
    return DATOS_INNECESARIOS;

  return intervalo->bgn <= intervalo->end ? opcion : INICIO_MAYOR_QUE_FIN;
}


void interprete(char *opciones[], int cant_opciones){
  int end = 0, opcion;
  char buf[100];
  char* ptr;

  Interval intervalo = malloc(sizeof(Intervalo)), res;
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
        res = itree_intersectar(raiz, intervalo);
        if (res != NULL){
          printf("Si, ");
          imprimir_intervalo(res);
        }else
          printf("No");
        puts("");
        break;
      case 3:
        itree_recorrer_dfs(raiz, imprimir_intervalo);
        puts("");
        break;
      case 4:
        itree_recorrer_bfs(raiz, imprimir_intervalo);
        puts("");
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
      case FALTA_INTERVALO:
        printf("Por favor, ingrese un intervalo junto con el comando.\n"
          "Ejemplo: 'i [a, b]' siendo a y b números válidos\n");
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