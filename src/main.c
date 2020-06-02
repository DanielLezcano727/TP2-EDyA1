#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itree.h"

int validar_op(char* buff) {
  int cond;
  switch(buff[0]) {
    case 's':
      if(strcmp(buff, "salida") == 0)
        cond = 6;
      break;
    case 'b':
      if(strcmp(buff, "bfs") == 0)
        cond = 5;
      break;
    case 'd':
      if(strcmp(buff, "dfs") == 0)
        cond = 4;
      break;
    case '?':
      if(strcmp(buff, "? [a,b]") == 0)
        cond = 3;
      break;
    case 'e':
      if(strcmp(buff, "e [a,b]") == 0)
        cond = 2;
      break;
    case 'i':
      if(strcmp(buff, "i [a,b]") == 0)
        cond = 1;
      break;
    
    default:
      cond = 0;
  }

  return cond;
}

int main(){
    // ITree raiz = itree_crear();
    // Interval intervalo = malloc(sizeof(IntervalStruct));
    // Interval intervaloFin;
  
    int continuar = 1;
    int caso;
    char buff[256];

    while(continuar) {
      printf("Ingrese una operacion: \n");
      scanf(" %[^\n]s",buff); //buscar opcion mas elegante
      caso = validar_op(buff);

      if(caso) {
        switch(caso) {
          case 1:
            printf("insertar\n");
            // intervalo->bgn = (double)(buff[] - '0');
            // intervalo->end = 10;
            // raiz = itree_insertar(raiz, intervalo);
            break;
          case 2:
            printf("eliminar\n");
            // intervalo->bgn = 6;
            // intervalo->end = 10;
            // raiz = itree_eliminar(raiz, intervalo);
            break;
          case 3:
            printf("intersectar\n");
          // intervalo->bgn = 6;
          // intervalo->end = 10;
          // intervaloFin = itree_intersectar(raiz, intervalo);
          // printf("[%f, %f] interseca con [%f, %f]\n", intervalo->bgn, intervalo->end, intervaloFin->bgn, intervaloFin->end);
            break;
          case 4:
            printf("dfs\n");
            // itree_recorrer_dfs(raiz);
            break;
          case 5:
            printf("bfs\n");
            // itree_recorrer_dfs(raiz);
            break;
          case 6:
            printf("salir\n");
            continuar = 0;
            // free(intervalo);
            // itree_destruir(raiz);
            break;
          default:
            printf("Entrada inválida\n");
        }
      }
    }

    return 0;
}





    // intervalo->bgn = 16;
    // intervalo->end = 21;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 8;
    // intervalo->end = 9;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 25;
    // intervalo->end = 30;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 5;
    // intervalo->end = 8;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 15;
    // intervalo->end = 23;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 17;
    // intervalo->end = 19;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 26;
    // intervalo->end = 26;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 0;
    // intervalo->end = 3;
    // raiz = itree_insertar(raiz, intervalo);
    // intervalo->bgn = 6;
    // intervalo->end = 10;
    // raiz = itree_insertar(raiz, intervalo);
    
    // itree_recorrer_dfs(raiz);