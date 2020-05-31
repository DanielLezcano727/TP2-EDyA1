#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

ITree itree_crear() {
  return NULL;
}

void itree_destruir(ITree arbol) {
  if(arbol != NULL){
    itree_destruir(arbol->left);
    itree_destruir(arbol->right);
    free(arbol->intervalo);
    free(arbol);
  }
}

int itree_altura_aux(ITree raiz){
  if(raiz == NULL)
    return 0;
  int size_izq = itree_altura_aux(raiz->left);
  int size_der = itree_altura_aux(raiz->right);
  return size_izq > size_der ? size_izq + 1 : size_der + 1;
}

int itree_altura(ITree raiz){
  return raiz == NULL ? -1 : itree_altura_aux(raiz) - 1;
}

int itree_balance_factor(ITree N){
  return itree_altura(N->right) - itree_altura(N->left);
}

double itree_max_sub(ITree nodo){
  if(nodo->left == NULL && nodo->right == NULL)
    return nodo->maySub;
  else if(nodo->left == NULL)
    return nodo->right->maySub;
  else if(nodo->right == NULL)
    return nodo->left->maySub;
  return nodo->left->maySub > nodo->right->maySub ? nodo->left->maySub : nodo->right->maySub;
}

ITree itree_rotacion_simple_der(ITree raiz){
  ITree aux = raiz->left;
  raiz->left = aux->right;
  aux->right = raiz;
  if(aux->left != NULL)
    aux->left->maySub = itree_max_sub(aux->left);
  aux->right->maySub = itree_max_sub(aux->right);
  aux->maySub = itree_max_sub(aux);
  return aux;
}

ITree itree_rotacion_simple_izq(ITree raiz){
  ITree aux = raiz->right;
  raiz->right = aux->left;
  aux->left = raiz;
  if(aux->right != NULL)
    aux->right->maySub = itree_max_sub(aux->right);
  aux->left->maySub = itree_max_sub(aux->left);
  aux->maySub = itree_max_sub(aux);
  return aux;
}

ITree itree_balancear_izq(ITree raiz){
  if(itree_balance_factor(raiz->left) < 0){
    raiz = itree_rotacion_simple_der(raiz);
  }else{
    raiz->left = itree_rotacion_simple_izq(raiz->left);
    raiz = itree_rotacion_simple_der(raiz);
  }
  return raiz;
}

ITree itree_balancear_der(ITree raiz){
  if(itree_balance_factor(raiz->right) > 0){
    raiz = itree_rotacion_simple_izq(raiz);
  }else{
    raiz->right = itree_rotacion_simple_der(raiz->right);
    raiz = itree_rotacion_simple_izq(raiz);
  }
  return raiz;
}

ITree itree_insertar(ITree raiz, Interval intervalo) {
  double auxDouble;

  if(raiz == NULL){
    raiz = malloc(sizeof(INode));
    raiz->intervalo = malloc(sizeof(IntervalStruct));
    raiz->intervalo->bgn = intervalo->bgn;
    raiz->intervalo->end = intervalo->end;
    raiz->maySub = intervalo->end;
    raiz->left = NULL;
    raiz->right = NULL;
  }else if(intervalo->bgn < raiz->intervalo->bgn){
    raiz->left = itree_insertar(raiz->left, intervalo);
    
    auxDouble = itree_max_sub(raiz);
    raiz->maySub = raiz->maySub > auxDouble ? raiz->maySub : auxDouble;
    
    if(itree_balance_factor(raiz) < -1){
      raiz = itree_balancear_izq(raiz);
    }
  }else{
    raiz->right = itree_insertar(raiz->right, intervalo);
    
    auxDouble = itree_max_sub(raiz);
    raiz->maySub = raiz->maySub > auxDouble ? raiz->maySub : auxDouble;
    
    if(itree_balance_factor(raiz) > 1){
      raiz = itree_balancear_der(raiz);
    }
  }
  return raiz;
}

// ITree itree_eliminar(ITree arbol, Interval intervalo) {

// }

int intersectar(Interval i1, Interval i2) {
  return (i1->bgn <= i2->bgn && i2->bgn <= i1->end) || (i1->bgn <= i2->end && i2->end <= i1->end);
  // return (i1->bgn <= i2->end && i2->bgn <= i1->end) || (i2->bgn <= i1->end && i1->bgn <= i2->end);
}

// return (i2->bgn >= i1->bgn && i2->bgn <= i1->end) || (i2->end >= i1->bgn && i2->end <= i1->end)

Interval itree_intersectar(ITree arbol, Interval intervalo) {
  if(arbol != NULL) {
    if(intersectar(arbol->intervalo, intervalo))
      return arbol->intervalo;
    if(arbol->left != NULL && arbol->left->maySub >= intervalo->end)
      return itree_intersectar(arbol->left, intervalo);
    return itree_intersectar(arbol->right, intervalo);
  }
  return NULL;
}

// Interval itree_intersectar(ITree arbol, Interval intervalo) {
//   if(arbol != NULL) {
//     if(intersectar(arbol->intervalo, intervalo))
//       return arbol->intervalo;
//     if(arbol->left != NULL && arbol->left->maySub > )
//       return itree_intersectar(arbol->left, intervalo);
//     return itree_intersectar(arbol->right, intervalo);
//   }
//   return NULL;
// }

void itree_recorrer_dfs(ITree arbol) {
  if(arbol != NULL){
    printf("[%f %f] Mayor subintervalo: %f\n", arbol->intervalo->bgn, arbol->intervalo->end, arbol->maySub);
    itree_recorrer_dfs(arbol->left);
    itree_recorrer_dfs(arbol->right);
  }
}

// void itree_recorrer_bfs(ITree arbol) {

// }
