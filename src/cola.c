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
    if(queue != NULL) {
        return (queue->inicio == NULL);
    }
    return -1;
}

ITree cola_primero(Cola* queue) {
    if(queue != NULL && queue->inicio != NULL) {
        return queue->inicio->dato;
    }
    return NULL;
}

Cola* cola_encolar(Cola* queue, ITree data) {
    SNodo* newNode = malloc(sizeof(SNodo));
    newNode->dato = malloc(sizeof(INode));
    newNode->dato = data;
    newNode->sig = NULL;
    
    if(queue != NULL && data != NULL) {
        if(!cola_es_vacia(queue)) {
            queue->fin->sig = newNode;
            queue->fin = newNode;
        }else {
            queue->inicio = newNode;
            queue->fin = newNode;
        }
    }

    return queue;
}

void cola_desencolar(Cola* queue) {
    if(queue != NULL) {
        if(!cola_es_vacia(queue)) {
            SNodo* temp = queue->inicio;
            queue->inicio = queue->inicio->sig;
            free(temp);
        }
    }
}

void cola_destruir(Cola* queue) {
    SNodo* temp;
    for(;queue->inicio != NULL;) {
        temp = queue->inicio;
        queue->inicio = queue->inicio->sig;
        free(temp);
    }

    free(queue);
}