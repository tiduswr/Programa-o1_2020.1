#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define lenVetor 100

int BubbleSort(int arr[]){
    int temp;
    for(int i = 0; i < lenVetor; i++){
        for(int j = 0; j < lenVetor; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}

int main(void){
    system("cls");
    setlocale(LC_ALL,"Portuguese");

    int values[lenVetor];

    //Pega valores
    printf("=-=-=-=-=-=-=-ORGANIZA VETOR=-=-=-=-=-=-=-\n");
    printf("\n**Digite os valores(Inteiros) solicitados abaixo: \n\n");
    for(int i = 0; i < lenVetor; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%i", &values[i]);
    }

    BubbleSort(values);

    system("cls");
    printf("=-=-=-=-=-=-=-Printa Valores=-=-=-=-=-=-=-\n");
    printf("\n**Digite os valores solicitados abaixo: \n\n");
    for(int i = 0; i < lenVetor; i++){
        printf("Valor[%d]: %d\n", i+1, values[i]);
    }

    printf("\n\n");
    return 0;
}