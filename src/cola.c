#include "cola.h"
#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

Cola* cola_crear() {
  Cola* queue = malloc(sizeof(Cola));
  queue->inicio = NULL;
  queue->fin = NULL;

  return queue;
}

int cola_es_vacia(Cola* queue) {
  return queue == NULL || queue->inicio == NULL;
}

ITree cola_primero(Cola* queue) {
  return cola_es_vacia(queue) ? NULL : queue->inicio->dato;
}

Cola* cola_encolar(Cola* queue, ITree data) {
  if(data == NULL || queue == NULL)
    return NULL;
  SNodo* newNode = malloc(sizeof(SNodo));
  newNode->dato = data;
  newNode->sig = NULL;
  if(cola_es_vacia(queue))
    queue->inicio = newNode;
  else
    queue->fin->sig = newNode;
    
  queue->fin = newNode;

    return queue;
}

void cola_desencolar(Cola* queue) {
  if(!cola_es_vacia(queue)) {
    SNodo* temp = queue->inicio;
    queue->inicio = queue->inicio->sig;
    if(queue->inicio == NULL)
      queue->fin = NULL;
    free(temp);
  }
}

void cola_destruir(Cola* queue) {
  SNodo* temp;
  while(queue->inicio != NULL) {
    temp = queue->inicio;
    queue->inicio = queue->inicio->sig;
    free(temp);
  }

  free(queue);
}