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

int itree_altura_aux(ITree arbol){
  if(arbol == NULL)
    return 0;
  int size_izq = itree_altura_aux(arbol->left);
  int size_der = itree_altura_aux(arbol->right);
  return size_izq > size_der ? size_izq + 1 : size_der + 1;
}

int itree_altura(ITree arbol){
  return arbol == NULL ? -1 : itree_altura_aux(arbol) - 1;
}

int itree_balance_factor(ITree arbol){
  return itree_altura(arbol->right) - itree_altura(arbol->left);
}

double itree_max_aux(ITree nodo1, ITree nodo2){
  if(nodo2 == NULL)
    return nodo1->maySub;
  return nodo1->maySub > nodo2->maySub ? nodo1->maySub : nodo2->maySub;
}

double itree_max_sub(ITree nodo){
  return itree_max_aux(itree_max_aux(nodo, nodo->left), nodo->right);
}

ITree itree_rotacion_simple_der(ITree arbol){
  ITree aux = arbol->left;
  arbol->left = aux->right;
  aux->right = arbol;
  if(aux->left != NULL)
    aux->left->maySub = itree_max_sub(aux->left);
  aux->right->maySub = itree_max_sub(aux->right);
  aux->maySub = itree_max_sub(aux);
  return aux;
}

ITree itree_rotacion_simple_izq(ITree arbol){
  ITree aux = arbol->right;
  arbol->right = aux->left;
  aux->left = arbol;
  if(aux->right != NULL)
    aux->right->maySub = itree_max_sub(aux->right);
  aux->left->maySub = itree_max_sub(aux->left);
  aux->maySub = itree_max_sub(aux);
  return aux;
}

ITree itree_balancear_izq(ITree arbol){
  if(itree_balance_factor(arbol->left) < 0)
    arbol = itree_rotacion_simple_der(arbol);
  else {
    arbol->left = itree_rotacion_simple_izq(arbol->left);
    arbol = itree_rotacion_simple_der(arbol);
  }
  return arbol;
}

ITree itree_balancear_der(ITree arbol){
  if(itree_balance_factor(arbol->right) > 0)
    arbol = itree_rotacion_simple_izq(arbol);
  else {
    arbol->right = itree_rotacion_simple_der(arbol->right);
    arbol = itree_rotacion_simple_izq(arbol);
  }
  return arbol;
}

ITree itree_insertar(ITree arbol, Interval intervalo) {
  double auxDouble;

  if(arbol == NULL){
    arbol = malloc(sizeof(INode));
    arbol->intervalo = malloc(sizeof(IntervalStruct));
    arbol->intervalo->bgn = intervalo->bgn;
    arbol->intervalo->end = intervalo->end;
    arbol->maySub = intervalo->end;
    arbol->left = NULL;
    arbol->right = NULL;
  }else if(intervalo->bgn < arbol->intervalo->bgn){
    arbol->left = itree_insertar(arbol->left, intervalo);
    
    arbol->maySub = itree_max_sub(arbol);
    if(itree_balance_factor(arbol) < -1)
      arbol = itree_balancear_izq(arbol);
  }else{
    arbol->right = itree_insertar(arbol->right, intervalo);
    
    arbol->maySub = itree_max_sub(arbol);
    if(itree_balance_factor(arbol) > 1)
      arbol = itree_balancear_der(arbol);
  }
  return arbol;
}

int intersectar(Interval i1, Interval i2) {
  return (i1->bgn <= i2->bgn && i2->bgn <= i1->end) || (i1->bgn <= i2->end && i2->end <= i1->end);
}

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

void itree_recorrer_dfs(ITree arbol) {
  if(arbol != NULL){
    printf("[%f %f] Mayor subintervalo: %f\n", arbol->intervalo->bgn, arbol->intervalo->end, arbol->maySub);
    itree_recorrer_dfs(arbol->left);
    itree_recorrer_dfs(arbol->right);
  }
}
