#include <stdio.h>

int main(void){

    /*Saida para o Programa abaixo: 
        Valor: 2752280 
        Valor: 1
        Valor: 3*/

    int vet[6] = {1, 2, 3, 4, 5, 6};
    printf("Valor: %d\n", vet);
    printf("Valor: %d\n", *vet);
    printf("Valor: %d\n", *(vet+2));
    return 0;

}