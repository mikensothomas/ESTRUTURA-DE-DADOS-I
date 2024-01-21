#include <stdio.h>

void bubleSort(int *v, int tam){
    int aux, troca = 1;

    while (troca){
        troca = 0;
        for(int i = 0; i < tam; i++){
            if(v[i] > v[i + 1]){
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i +1] = aux;
            }
        }
        tam--;
    }
}

void bubleSortRecursivo(int *v, int n){
    if(n < 2) return;

    for (int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }
    bubleSortRecursivo(v, n-1);
}

void imprimir(int *v, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {5,8,9,4,6,10,3,7,1,2};
    int tam = 10;

    imprimir(vet, tam);

    bubleSort(vet, tam);
    imprimir(vet, tam);

    printf("bubleSortRecursivo\n");

    bubleSortRecursivo(vet, tam);
    imprimir(vet, tam);
    return 0;
}