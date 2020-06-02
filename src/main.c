#include <stdio.h>
#include <stdlib.h>
#include "itree.h"

static void imprimir_nodo_intervalos(ITree arbol) {
  printf("[%f %f] Mayor subintervalo: %f\n", arbol->intervalo->bgn, arbol->intervalo->end, arbol->maySub);
}

int main(){
    ITree raiz = itree_crear();
    
    Interval intervalo = malloc(sizeof(IntervalStruct));

    intervalo->bgn = 16;
    intervalo->end = 21;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 8;
    intervalo->end = 9;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 25;
    intervalo->end = 30;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 5;
    intervalo->end = 8;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 15;
    intervalo->end = 23;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 17;
    intervalo->end = 19;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 26;
    intervalo->end = 26;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 0;
    intervalo->end = 3;
    raiz = itree_insertar(raiz, intervalo);
    intervalo->bgn = 6;
    intervalo->end = 10;
    raiz = itree_insertar(raiz, intervalo);
    
    // itree_recorrer_dfs(raiz, imprimir_nodo_intervalos);
    itree_recorrer_bfs(raiz, imprimir_nodo_intervalos);

    free(intervalo);
    itree_destruir(raiz);

    return 0;
}