#ifndef __ITREE_H__
#define __ITREE_H__

typedef struct _Intervalo {
  double bgn;
  double end;
} Intervalo;

typedef Intervalo *Interval;

typedef struct _INode {
  Interval intervalo;
  double maySub;
  struct _INode *left;
  struct _INode *right;
} INode;

typedef INode *ITree;

typedef void (*FuncionVisitante)(Interval dato);

/**
 * Crea y devuelve un arbol de intervalos
**/
ITree itree_crear();

/**
 * Destruye todos los elementos del arbol de intervalos
**/
void itree_destruir(ITree arbol);

/**
 * Devuelve la altura del arbol
**/
int itree_altura(ITree arbol);

/**
 * Devuelve el factor por el cual se decidira si el arbol esta balanceado
**/
int itree_balance_factor(ITree arbol);

/**
 * Inserta el intervalo indicado al arbol
**/
ITree itree_insertar(ITree arbol, Interval intervalo);

/**
 * Elimina (de existir) el intervalo indicado del arbol
**/
ITree itree_eliminar(ITree arbol, Interval intervalo);

/**
 * Devuelve (de existir) el intervalo del arbol con el cual el
 * intervalo dado se interseca
**/
Interval itree_intersectar(ITree arbol, Interval intervalo);

/**
 * Recorre el arbol por altura
**/
void itree_recorrer_dfs(ITree arbol, FuncionVisitante visit);

/**
 * Recrorre el arbol a lo ancho
**/
void itree_recorrer_bfs(ITree arbol, FuncionVisitante visit);

#endif
