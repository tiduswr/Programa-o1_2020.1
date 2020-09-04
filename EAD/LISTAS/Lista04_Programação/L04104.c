#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LEN 2

typedef struct{
    int value;
    int posX;
    int posY;
}matrizInt;

matrizInt maior(int Arr[][LEN], int lenArr){
    matrizInt aux;

    aux.value = Arr[0][0];
    aux.posX = 0;
    aux.posY = 0;

    for(int i = 0; i < lenArr; i++){
        for(int j = 0; j < lenArr; j++){
            if(Arr[i][j] > aux.value){
                aux.value = Arr[i][j];
                aux.posX = i;
                aux.posY = j;
            }
        }
    }
    
    return aux;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    int mat[LEN][LEN];
    matrizInt max;

    printf("**Preencha a Matriz %dX%d para verificar o maior valor:\n\n", LEN, LEN);
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            printf("Matriz[%d][%d] = ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    max = maior(mat, LEN);

    printf("\n\nMaior valor encontrado: %d", max.value);
    printf("\nElementos da Coluna: ");
    for(int i = 0; i < LEN; i++){
        if(i != LEN - 1 && i != LEN - 2){
            printf("%d;", mat[i][max.posY]);
        }
        else{
            if(i != LEN -1){
                printf("%d e ", mat[i][max.posY]);
            }
            else{
                printf("%d", mat[i][max.posY]);
            }
        }
    }
    printf("\nElementos da Linha: ");
    for(int i = 0; i < LEN; i++){
        if(i != LEN - 1 && i != LEN - 2){
            printf("%d;", mat[max.posX][i]);
        }
        else{
            if(i != LEN -1){
                printf("%d e ", mat[max.posX][i]);
            }
            else{
                printf("%d", mat[max.posX][i]);
            }
        }
    }
    printf("\n");
    return 0;
}