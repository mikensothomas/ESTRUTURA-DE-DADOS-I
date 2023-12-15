#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 31

typedef struct no
{
    int chave;
    struct no *proximo;
}No;

typedef struct
{
    No *inicio;
    int tam;
}Lista;

void iniciarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserirNaLista(Lista *l, int valor){
    No *novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
    } else {
       printf("\n\tErro ao alocar memória.\n"); 
    }
}

int buscaNaLista(Lista *l, int valor){
    No *aux = l->inicio;
    while (aux && aux->chave != valor)
    {
        aux = aux->proximo;
    }
    if (aux)
    {
        return aux->chave;
    }
    return 0;
}

void imprirLista(Lista *l){
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);
    while (aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        iniciarLista(&t[i]);
    }
    
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserirNaTAbela(Lista t[], int valor)
{
    int id = funcaoHash(valor);
    inserirNaLista(&t[id], valor);
}

int buscarNaLista(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice gerada gerada: %d\n", id);
    return buscaNaLista(&t[id], chave);
}

void imprimirTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d = ", i);
        imprimirTabela(&t[i]);
        printf("\n");
    }
    
}

int main()
{

    int opcao, valor, retorno, tabela[TAM];
    Lista tabela[TAM];
    
    inicializarTabela(tabela);
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            exit (0);
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNaTAbela(tabela, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            retorno = buscarNaLista(tabela, valor);
            if(retorno != 0)
            {
                printf("\tValor encontrado: %d\n", retorno);
            }
            else
            {
                printf("\tO valor não encontrado.\n");
            }
            
            break;
        case 3:
            imprimirTabela(tabela);
            break;
        
        default:
            printf("Valor não encntrado");
            break;
        }
    } while (opcao != 0);
    
    return 0;
}