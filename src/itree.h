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

typedef void (*FuncionVisitante) (Interval dato);

ITree itree_crear();

void itree_destruir(ITree arbol);

int itree_altura(ITree arbol);

int itree_balance_factor(ITree arbol);

ITree itree_insertar(ITree arbol, Interval intervalo);

ITree itree_eliminar(ITree arbol, Interval intervalo);

Interval itree_intersectar(ITree arbol, Interval intervalo);

void itree_recorrer_dfs(ITree arbol, FuncionVisitante visit);

void itree_recorrer_bfs(ITree arbol, FuncionVisitante visit);

#endif
