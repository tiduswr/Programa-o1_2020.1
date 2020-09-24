#include <stdio.h>

int * metade_final(int *vet, int n){
    return &vet[(int)(n/2)];
}

int main(void){

    //Saida para o Programa abaixo: 4

    int vet[6] = {1, 2, 3, 4, 5, 6};
    int *v = metade_final(vet, 6);
    printf("Valor: %d\n", v[0]);
    return 0;

}