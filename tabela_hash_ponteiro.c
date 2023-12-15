#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 31

void inicializarTabela(int t[])
{
    for (int i = 0; i < TAM; i++)
    {
        t[i] = 0;
    }
    
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserirNaTAbela(int t[], int valor)
{
    int id = funcaoHash(valor);
    while (t[id] != 0)
    {
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int buscarNaLista(int t[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice gerada gerada: %d\n", id);
    while (t[id] != 0)
    {
        if(t[id] == chave)
            return t[id]; 
        else
            id = funcaoHash(id + 1);
    }
    return 0;  
}
/*Mikenson Thomas*/
void imprimirTabela(int t[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, t[i]);
    }
    
}

int main()
{

    int opcao, valor, retorno, tabela[TAM];
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