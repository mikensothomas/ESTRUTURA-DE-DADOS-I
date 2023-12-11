#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void iniciar_pilha(PILHA *p){
    p->topo = NULL;
}

void inserir_elemento(PILHA *p, int elemento){
    NO *ptr = (NO*) malloc(sizeof(NO));

    if(ptr){
        ptr->dado = elemento;
        ptr->prox = p->topo;
        p->topo = ptr;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

int remover_Elemento(PILHA *p){
    int elemento;
    NO *ptr = p->topo;

    if(ptr){
       p->topo = p->topo->prox;
       ptr->prox = NULL;
       elemento = ptr->dado;
       free(ptr);
       return elemento;
    } else {
        printf("\nPilha vazia.\n");
        return 1;
    }
}

void imprimir(PILHA *p){
    NO *ptr = p->topo;

    if(ptr){
        while (ptr != NULL){
            printf("\n%d", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    } else {
        printf("\nPilha vazia.\n");
    }
}

int main(){

    PILHA *pilha1 = (PILHA*) malloc(sizeof(PILHA));
    iniciar_pilha(pilha1);

    int opcao, numero;

    while (opcao){

        printf("\nEscolha uma opção: ");
        printf("\n\t- 0 Sair \n\t- 1 Inserir \n\t- 2 Imprimir \n\t- 3 Remover\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um número: ");
                scanf("%d", &numero);
                inserir_elemento(pilha1, numero);
                break;
            case 2:
                printf("A pilha tem:\n");
                imprimir(pilha1);
                break;
            case 3:
                remover_Elemento(pilha1);
                break;
            default:
                exit (0);
        }
    }

    return 0;
}