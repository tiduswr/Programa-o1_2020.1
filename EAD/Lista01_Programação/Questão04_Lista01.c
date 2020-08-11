#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define maxValues 100

typedef struct{
    int position;
    int value;
} ArrayDetalhada;


ArrayDetalhada LowerValue(int *arr){
    ArrayDetalhada aux;
    
    for(int i = 0; i < maxValues; i++){
        if(i == 0){
            aux.value = arr[i];
        }
        else{
            if(arr[i] < aux.value){
                aux.position = i;
                aux.value = arr[i];
            }
        }
    }
    return aux;
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    ArrayDetalhada lowVal;
    int values[maxValues];
    
    //Pega valores
    printf("=-=-=-=-=-FILTRA MENOR VALOR=-=-=-=-=-\n");
    printf("\n**Digite os valores solicitados abaixo: \n\n");
    for(int i = 0; i < maxValues; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%i", &values[i]);
    }

    //Verifica menor valor e imprime conforme solicitado na questão
    lowVal = LowerValue(values);

    system("cls");
    printf("=-=-=-=-=-FILTRA MENOR VALOR=-=-=-=-=-\n");
    printf("\n**Resultado:\n\n");
    printf("Menor Valor -> Índice[%d] = %d", lowVal.position+1, lowVal.value);
    //Verifica se é possivel printar algo
    if(lowVal.position > 0){
        printf("\nValor da Posição Anterior -> Índice[%d] = %d", lowVal.position, values[lowVal.position-1]);
    }
    if (lowVal.position + 1 < maxValues){
        printf("\nValor da Posição Posterior -> Índice[%d] = %d", lowVal.position+2, values[lowVal.position+1]);
    }
    printf("\n\n");
    return 0;
}
