#ifndef __COLA_H__
#define __COLA_H__
#include "itree.h"

typedef struct _SNodo {
  ITree dato;
  struct _SNodo *sig;
} SNodo;

typedef struct _PunterosCola {
  SNodo *inicio;
  SNodo *fin;
}PunterosCola;

typedef PunterosCola *Cola;

Cola cola_crear();

int cola_es_vacia(Cola queue);

ITree cola_primero(Cola queue);

Cola cola_encolar(Cola queue, ITree data);

void cola_desencolar(Cola queue);

void cola_destruir(Cola queue);

#endif /* __COLA_H__ */