#ifndef __ITREE_H__
#define __ITREE_H__

typedef struct _Interval {
  int bgn;
  int end;
  int maySub;
}Interval;

typedef struct _INode {
  Interval datos;
  struct _INode* left;
  struct _INode* right; 
}INode;

typedef INode *ITree;

ITree itree_crear();

void itree_destruir(ITree arbol);

ITree itree_insertar(ITree arbol, Interval datos);

ITree itree_eliminar(ITree arbol, Interval datos);

INode itree_intersectar(ITree arbol, Interval datos);

void itree_recorrer_dfs(ITree arbol);

void itree_recorrer_bfs(ITree arbol);

int intersectar(Interval i1, Interval i2);

#endif
