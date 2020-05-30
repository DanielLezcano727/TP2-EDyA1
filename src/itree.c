#include "itree.h"
#include <stdlib.h>

ITree itree_crear() {
  return NULL;
}

void itree_destruir(ITree arbol) {

}

ITree itree_insertar(ITree arbol, Interval datos) {

}

ITree itree_eliminar(ITree arbol, Interval datos) {

}

INode itree_intersectar(ITree arbol, Interval datos) {

}

void itree_recorrer_dfs(ITree arbol) {

}

void itree_recorrer_bfs(ITree arbol) {

}

int intersectar(Interval i1, Interval i2) {
  return (i1.bgn <= i2.end && i2.bgn <= i1.end);
}
