#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAT_Y 5
#define MAT_X 5

void PrintCabec01(){
    printf("=-=-=-=-=-=-=-IMPRIME MATRIZ FORMATADA=-=-=-=-=-=-=-\n");
    printf("\n**Digite os valores(Inteiros) solicitados abaixo: \n\n");
}

int MaxValue(int arr[MAT_X][MAT_Y]){
    int max;
    
    for(int i = 0; i < MAT_X; i++){
        for(int j = 0; j < MAT_Y; j++){
            if(j == 0 && i == 0){
                max = arr[i][j];
            }
            else{
                if(arr[i][j] > max){
                    max = arr[i][j];
                }
            }
        }
    }
    return max;
}

int lenInt(int value){
    if(value < 10){
        return 1;
    }
    else if(value < 100){
        return 2;
    }
    else if(value < 1000){
        return 3;
    }
    else if(value < 10000){
        return 4;
    }
    else if(value < 100000){
        return 5;
    }
    else if(value < 1000000){
        return 6;
    }
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int values[MAT_X][MAT_Y], max;

    //Pega valores
    PrintCabec01();
    for(int i = 0; i < MAT_X; i++){
        for(int j = 0; j < MAT_Y; j++){
            printf("MATRIZ[%d][%d]: ", i+1, j+1);
            scanf("%d", &values[i][j]);
        }
        system("cls");
        PrintCabec01();
    }

    max = lenInt(MaxValue(values));
    //Imprime Matriz
    printf("=-=-=-=-=-=-=-IMPRIME MATRIZ FORMATADA=-=-=-=-=-=-=-\n");
    printf("\n**Resultado abaixo: \n\n");
    for(int i = 0; i < MAT_X; i++){
        for(int j = 0; j < MAT_Y; j++){
            if(j == 0){
                printf("|%d", values[i][j]);
                if(max > 1){
                    for(int n = 0; n < max - lenInt(values[i][j]); n++){
                        printf(" ");
                    }
                }
                printf("|");
            }
            else{
                printf("%d", values[i][j]);
                if(max > 1){
                    for(int n = 0; n < max - lenInt(values[i][j]); n++){
                        printf(" ");
                    }
                }
                printf("|");
            }
        }
        printf("\n");
    }

    printf("\n\n");
    return 0;
}