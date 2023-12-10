#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no{
    int valor;
    struct no *proximo;   
}No;

void inserirNoInicio(No **lista, int num){
    No *novo = (No*)malloc(sizeof(No));
        
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoFinal(No **lista, int num){
    No * auxi, *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL){
            *lista = novo;
        } else {
            auxi = *lista;
            while (auxi->proximo){
                auxi = auxi->proximo;
                auxi->proximo = novo;
            }
            
        }
        
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoMeio(No **lista, int num, int ant){
    No * aux, *novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != ant && aux->proximo){
                aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
} 

void imprimirLista(No *no){
    printf("\n\tLista:");
    while (no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n"); 
}

int main(){

    int opcao, valor, anterior;
    No *lista = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
        scanf("%d ", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
                break;
            case 3:
                printf("Digite o valor e o valor de referencia: ");
                scanf("%d%d", &valor, &anterior);
                inserirNoMeio(&lista, valor, anterior);
                break;
            case 4:
                imprimirLista(lista);
                break;
            
            default:
                if(opcao == 0){
                    exit (0);
                }
        }
    }while (opcao != 0);
    
    return 0;
}