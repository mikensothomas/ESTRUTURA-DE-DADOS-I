#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializar_pilha(PILHA *p){
    p->topo = NULL;
}

void empilhar(int elemento, PILHA *p){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de alocação de nó\n");
        return;
    } else {
        ptr->dado = elemento;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

int desempilhar(PILHA *p){
    NO *ptr = p->topo;
    int elemento;
    if(ptr == NULL){
        printf("Pilha vazia");
        return 1;
    } else {
        p->topo = p->topo->prox;
        ptr->prox = NULL;
        elemento = ptr->dado;
        free(ptr);
        return elemento;
    }
}

void imprimir_pilha(PILHA *p){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("A pilha está vazia\n");
        return;
    } else {
        while (ptr != NULL){
            printf("\n%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int main(){

    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    if(p1 == NULL){
        printf("Erro de alocação de pilha");
        exit(0);
    } else {
        inicializar_pilha(p1);

        empilhar(10, p1);
        empilhar(20, p1);
        empilhar(30, p1);

        imprimir_pilha(p1);

        printf("Tentando desempilhar: %d\n", desempilhar(p1));
        imprimir_pilha(p1);
        printf("Tentando desempilhar: %d\n", desempilhar(p1));
        imprimir_pilha(p1);
        printf("Tentando desempilhar: %d\n", desempilhar(p1));
        imprimir_pilha(p1);
        desempilhar(p1);
    }

    return 0;
}