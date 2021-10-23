#include "dna_alien.h"
#include <stdlib.h>

LinkedNode *dna_alien(LinkedNode *atual) {
    LinkedNode * inicio = atual;
    LinkedNode * anterior = NULL;
    while(atual != NULL) {
        if (atual->next != NULL && atual->next->data == 'C' || atual->next->data == 'G') {
            LinkedNode *tmp = atual->next;
            atual->next = tmp->next;
            free(tmp);
        }
        anterior = atual;
        atual = atual->next;
    }
    return inicio;
}