#include <stdio.h>
#include <stdlib.h>
#include "itree.h"

int validar_op(char* buff) {
  
}

int main(){
    // ITree raiz = itree_crear();
    // Interval intervalo = malloc(sizeof(IntervalStruct));
    // Interval intervaloFin;
  
    int continuar = 1;
    char casos;
    char buff[10];

    while(continuar) {
      printf("Ingrese una operacion: \n");
      fgets(buff, sizeof(buff), stdin);
      casos = buff[0];

      if(validar_op(buff)) {
        switch(casos) {
          case 'i':
            printf("insertar\n");
            // intervalo->bgn = (double)(buff[] - '0');
            // intervalo->end = 10;
            // raiz = itree_insertar(raiz, intervalo);
            break;
          case 'e':
            printf("eliminar\n");
            // intervalo->bgn = 6;
            // intervalo->end = 10;
            // raiz = itree_eliminar(raiz, intervalo);
            break;
          case '?':
            printf("intersectar\n");
          // intervalo->bgn = 6;
          // intervalo->end = 10;
          // intervaloFin = itree_intersectar(raiz, intervalo);
          // printf("[%f, %f] interseca con [%f, %f]\n", intervalo->bgn, intervalo->end, intervaloFin->bgn, intervaloFin->end);
            break;
          case 'd':
            printf("destruir\n");
            // itree_recorrer_dfs(raiz);
            break;
          case 's':
            printf("salir\n");
            continuar = 0;
            // free(intervalo);
            // itree_destruir(raiz);
            break;
          default:
            printf("Entrada inválida\n");
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