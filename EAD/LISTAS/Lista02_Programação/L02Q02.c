#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define lenMat 3

int isMatIdentity(int mat[][lenMat], int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){   
            if(i == j && mat[i][j] != 1){
                return 0;
            }
            else if(i != j && mat[i][j] != 0){
                return 0;
            }
        }
    }  
    return 1;
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int result, values[lenMat][lenMat];

    printf("**Digite os valores para preencher a matriz:\n\n");
    for(int i = 0; i < lenMat; i++){
        for(int j = 0; j < lenMat; j++){
            printf("Matriz[%d][%d]: ", i+1, j+1);
            scanf("%d", &values[i][j]);
        }
    }

    result = isMatIdentity(values, lenMat);
    if(result == 1){
        printf("\nA Matriz digitada, é uma matriz identidade!");
    }
    else{
        printf("\nA Matriz digitada, não é uma matriz identidade!");
    }

    printf("\n");
    return 0;
}
