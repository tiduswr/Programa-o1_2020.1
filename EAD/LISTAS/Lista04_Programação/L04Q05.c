#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float soma(float Arr[], int lenArr){
    if(lenArr > 0){
        return Arr[lenArr - 1] + soma(Arr, lenArr - 1);
    }
    else{
        return 0;
    }
} 

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int lenVet;
    printf("**Some até 10 Valores!\n\n");
    printf("*Digite o tamanho do vetor: ");
    scanf("%d", &lenVet);
    
    float array[lenVet];
    //Teste
    for(int i = 0; i < lenVet; i++){
        array[i] = (i*i) + (2*i) + 7.5;
        printf("%.2f ", array[i]);
    }
    printf("\n\n*A soma dos valores dos vetores é igual a %.2f", soma(array, lenVet));

    printf("\n");
    return 0;
}