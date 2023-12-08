#include <stdio.h>
#include <stdio.h>
#include <locale.h>

#define N 3

typedef struct T_FILA
{
    int dados[N];
    int fim;
}T_FILA;

void inicializar_fila(T_FILA *f)
{
    for(int i = 0; i < N; i++){
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void infileira(int dado, T_FILA *f)
{
    if(f->fim == N){
        printf("Fila cheia.\n");
        return;
    } else {
        f->dados[f->fim] = dado;
        f->fim++;
    }
}

int desenfileira(T_FILA *f)
{
    int dado;
    if(f->fim == 0){
        printf("Fila está vazia.\n");
        return 1;
    } else {
        dado = f->dados[0];
        for(int i = 0; i < f->fim; i++){
            f->dados[i] = f->dados[i+1];
        }
        f->fim--;
        return dado;
    }
}

void imprimir(T_FILA *f)
{
    printf("---------------\n");
    for(int i = 0; i < f->fim; i++){
        printf("%d \n", f->dados[i]);
    }
}


int main ()
{

    T_FILA f1;

    inicializar_fila(&f1);

    
    infileira(11, &f1);
    infileira(12, &f1);
    infileira(13, &f1);
    imprimir(&f1);

    desenfileira(&f1);
    desenfileira(&f1);
    desenfileira(&f1);
    imprimir(&f1);

    desenfileira(&f1);
    desenfileira(&f1);
    imprimir(&f1);


    return 0;
}