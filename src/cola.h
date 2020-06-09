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
} PunterosCola;

typedef PunterosCola *Cola;

/**
 * Crea un nodo inicial para una cola y lo retorna
**/
Cola cola_crear();

/**
 * Retorna True o False si la cola no tiene elementos
**/
int cola_es_vacia(Cola queue);

/**
 * Devuelve el primer elemento de la cola
**/
ITree cola_primero(Cola queue);

/**
 * Agrega un elemento al final de la cola
**/
Cola cola_encolar(Cola queue, ITree data);

/**
 * Elimina el primer elemento de la cola
**/
void cola_desencolar(Cola queue);

/**
 * Libera toda la memoria usada por la cola hasta el momento
**/
void cola_destruir(Cola queue);

#endif                          /* __COLA_H__ */
