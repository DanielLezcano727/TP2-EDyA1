#include <stdio.h>
#include <stdlib.h>
#include "itree.h"

int main(){
    ITree raiz = itree_crear();
    
    Interval intervalo = malloc(sizeof(IntervalStruct));

    
    itree_recorrer_dfs(raiz);

    int continuar = 0;
    char casos;
    char buff[10];
    Interval intervaloFin;

    while(continuar) {
      scanf("%s", &buff);
      casos = buff[0];
      switch(casos) {
        case 'i':
          intervalo->bgn = (double)(buff[] - '0');
          intervalo->end = 10;
          raiz = itree_insertar(raiz, intervalo);
          break;
        case 'e':
          intervalo->bgn = 6;
          intervalo->end = 10;
          raiz = itree_eliminar(raiz, intervalo);
          break;
        case '?':
        intervalo->bgn = 6;
        intervalo->end = 10;
        intervaloFin = itree_intersectar(raiz, intervalo);
        printf("[%f, %f] interseca con [%f, %f]\n", intervalo->bgn, intervalo->end, intervaloFin->bgn, intervaloFin->end);
          break;
        case 'd':
          itree_recorrer_dfs(raiz);
          break;
        case 's':
          continuar++;
          free(intervalo);
          itree_destruir(raiz);
          break;
        default:
          printf("Entrada inválida");
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