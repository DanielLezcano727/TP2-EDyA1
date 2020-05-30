#ifndef __ITREE_H__
#define __ITREE_H__

typedef struct _Interval {
  double bgn;
  double end;
}IntervalStruct;

typedef IntervalStruct *Interval;

typedef struct _INode {
  Interval intervalo;
  double maySub;
  struct _INode* left;
  struct _INode* right; 
}INode;

typedef INode *ITree;

ITree itree_crear();

void itree_destruir(ITree arbol);

ITree itree_insertar(ITree arbol, Interval intervalo);

ITree itree_eliminar(ITree arbol, Interval intervalo);

Interval itree_intersectar(ITree arbol, Interval intervalo);

void itree_recorrer_dfs(ITree arbol);

void itree_recorrer_bfs(ITree arbol);

#endif
