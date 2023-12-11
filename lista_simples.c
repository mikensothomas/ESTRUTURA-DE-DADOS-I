#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}


void inserirNoInicio(Lista *lista, int num) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoFinal(Lista *lista, int num) {
    No *auxi, *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            auxi = lista->inicio;
            while (auxi->proximo) {
                auxi = auxi->proximo;
            }
            auxi->proximo = novo;
        }
        lista->tam++;

    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoMeio(Lista *lista, int num, int ant) {
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        if (lista->inicio == NULL) {
            novo->proximo = NULL;
            lista->inicio = novo;
        } else {
            aux = lista->inicio;
            while (aux->valor != ant && aux->proximo) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void imprimirLista(Lista Lista) {
    No *no = Lista.inicio;
    printf("\n\tLista tam %d: ", Lista.tam);
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main() {

    int opcao, valor, anterior;
    Lista lista;

    criar_lista(&lista);

    do {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
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
                if (opcao == 0) {
                    exit(0);
                }
            }
        
    } while (opcao != 0);

    return 0;
}