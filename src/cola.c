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
    return (queue->inicio == NULL);
}

ITree cola_primero(Cola* queue) {
    return queue->inicio->dato;
}

Cola* cola_encolar(Cola* queue, ITree data) {
    SNodo* newNode = malloc(sizeof(SNodo));
    newNode->dato = malloc(sizeof(INode));
    newNode->dato = data;
    
    if(queue->inicio == NULL) {
        newNode->sig = queue->fin;
        queue->fin = newNode;
        queue->inicio = newNode;    
    }else {
        newNode->sig = queue->fin;
        queue->fin = newNode;
    }
    return queue;
}

Cola* cola_desencolar(Cola* queue) {
    if(!cola_es_vacia(queue) && queue->fin != queue->inicio) {
        SNodo* temp = queue->fin;
        while(temp->sig != queue->inicio) {
            temp = temp->sig;
        }
        queue->inicio = temp;
        free(temp->sig);

        return queue;
    }

    return NULL;
}

void cola_destruir(Cola* queue) {
    SNodo* temp = queue->inicio;
    for(;queue->inicio != NULL;) {
        temp = queue->inicio;
        queue->inicio = queue->inicio->sig;
        free(temp);
    }

    free(queue);
}