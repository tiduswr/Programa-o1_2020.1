#include <stdio.h>
#include <stdlib.h>

int makearray(int xarr[], int len){
    // exemplo para criar uma matriz em funções
    for(int i = 0; i < len; i++){
        xarr[i] = i;
    }
    return 0;
}

int main(void){
    system("cls");

    int *arr;
    int arrLen;

    arrLen = 3; // crie um controle para dinamizar as matrizes
    arr = malloc(arrLen * sizeof(int)); //Aloque memoria com malloc

    makearray(arr, arrLen);

    for(int i = 0; i < arrLen; i++){
        printf("%d ", arr[i]);
    }   
    free(arr);
}