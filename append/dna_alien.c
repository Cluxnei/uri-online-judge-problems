#include "dna_alien.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};

LinkedNode *dna_alien(LinkedNode *atual) {
    LinkedNode * inicio = atual;
    LinkedNode * anterior = NULL;
    while(atual != NULL) {
        if (anterior != NULL && (atual->data == 'C' || atual->data == 'G')) {
            anterior->next = atual->next;
            free(atual);
            atual = anterior;
            continue;
        }
        if (atual->next != NULL && (atual->next->data == 'C' || atual->next->data == 'G')) {
            LinkedNode *aux = atual->next;
            atual->next = aux->next;
            free(aux);
            aux = NULL;
        }
        anterior = atual;
        atual = atual->next;
    }
    return inicio;
}

void printList(LinkedNode *start) {
    while(start != NULL) {
        printf("%c, ", start->data);
        start = start->next;
    }
    puts("");
}

int main() {
    LinkedNode *firstNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    scanf("%c", &firstNode->data);
    LinkedNode *previous = NULL;
    while(1) {
        LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
        scanf("%c", &node->data);
        if (node->data == '0') {
            node->next = NULL;
            break;
        }
        if (previous != NULL) {
            previous->next = node;
        } else {
            firstNode->next = node;
        }
        previous = node;
    }
    
    puts("original");
    printList(firstNode);
    dna_alien(firstNode);
    puts("new");
    printList(firstNode);
    return 0;
}