#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;
typedef struct Lista{
    No *inicio;
    int tam;
}Lista;

void iniciarLista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserirNoInicio(Lista *lista, int num){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoFinal(Lista *lista, int num){
    No *no, *novo = (No*)malloc(sizeof(No));

    novo->valor = num;
    novo->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    } else {
        no = lista->inicio;
        while (no->prox != NULL){
            no = no->prox;
        }
        no->prox = novo;
    }
    lista->tam++;
}

void imprimirLista(Lista *lista){
    No *inicio = lista->inicio;

    if(lista->tam == 0){
        printf("Lista vazia");
    } else {
        while (inicio != NULL){
            printf("%d ", inicio->valor);
            inicio = inicio->prox;
        }
    }
    printf("\n");
    printf("O tamanha da lista é: %d", lista->tam);
    printf("\n\n");
}


int main(){

    int opcao, numero;
    Lista lista;
    iniciarLista(&lista);

    do
    {
        printf("FAÇA UMA ESCOLHA NO MENU\n\n");
        printf("\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inseir no final\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 0:
                exit (0);
                break;
            case 1:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &numero);
                inserirNoInicio(&lista, numero);
                break;
            case 2:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &numero);
                inserirNoFinal(&lista, numero);
                break;
            case 3:
            printf("A lista: ");
                imprimirLista(&lista);
                break;
            default:
                printf("Número não encontrado\n");
                exit (0);
        }
    } while (opcao);
    
    return 0;
}