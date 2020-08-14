#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define eixoX 10
#define eixoY 3

int MaxValue(int arr[eixoX][eixoY]){
    int max;
    
    for(int i = 0; i < eixoX; i++){
        for(int j = 0; j < eixoY; j++){
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
    int returnValue;

    if(value < 10){
        returnValue = 1;
    }
    else if(value < 100){
        returnValue = 2;
    }
    else if(value < 1000){
        returnValue = 3;
    }
    else if(value < 10000){
        returnValue = 4;
    }
    else if(value < 100000){
        returnValue = 5;
    }
    else if(value < 1000000){
        returnValue = 6;
    }
    return returnValue;
}

bool isEven(int n){
    if(n % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

int lenUsed(int values[eixoX][eixoY], int col){
    int cont = 0;
    
    for(int i = 0; i < eixoX; i++){
        if(values[i][col] > 0){
                cont++;
        }
    }
    return cont;
}

void orgNumber(int saveValue, int values[eixoX][eixoY], int midCol, int col){
        int colmax = lenUsed(values, col);
        int midmax = lenUsed(values, midCol);
        int aux;
        
        if(saveValue >= 0){
            if(colmax <= eixoX - 1){
                values[colmax][col] = saveValue;
            }
            else{
                if(midmax <= eixoX - 1){
                    values[midmax][midCol] = values[0][col];
                    for(int i = 0; i < eixoX; i++){
                        if(i < eixoX - 1){
                            values[i][col] = values[i+1][col];
                        }
                        else{
                            values[i][col] = 0;
                        }
                    }
                    values[colmax-1][col] = saveValue;
                }
                else{
                    aux = values[0][col];
                    for(int i = 0; i < eixoX; i++){
                        if(i < eixoX - 1){
                            values[i][col] = values[i+1][col];
                            values[i][midCol] = values[i+1][midCol];
                        }
                        else{
                            values[i][col] = 0;
                            values[i][midCol] = 0;
                        }
                    }
                    values[colmax-1][col] = saveValue;
                    values[midmax-1][midCol] = aux;
                }    
            } 
        }
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
    //Inicia variaveis
    int values[eixoX][eixoY], aux;
    int col, LenCelulas;
    int *ptrmax;
    int maxCols[3] = {0,0,0}, numDigi = 0;
    for(int i = 0; i < eixoX; i++){
        for(int j = 0; j < eixoY; j++){
            values[i][j] = 0;
        }
    }
    printf("=-=-=-=-=-=-=-=-=-ORGANIZA NUMEROS DIGITADOS=-=-=-=-=-=-=-=-=-");
    printf("\n**Preencha trinta valores, depois disso o programa não salvara ");
    printf("\nmais e ira apagar os mais antigos(Digite -1 para sair):\n\n");
    //Pega dados
    while(aux >= 0){
        printf("Valor nº %d: ", numDigi +1);
        scanf("%d", &aux);  
        numDigi++;
        //Verifica se o numero é par ou impar
        if(isEven(aux)){
            orgNumber(aux, values, 1, 2);
        }   
        else{
            orgNumber(aux, values, 1, 0);
        }
    }
    //Imprime
    LenCelulas = lenInt(MaxValue(values));
    printf("\n\n=-=-=-=-=-=-=-=-=-IMPRESSÃO DA TABELA=-=-=-=-=-=-=-=-=-\n\n");
    for(int i = 0; i < eixoX; i++){
        for(int j = 0; j < eixoY; j++){
            if(j == 0){
                printf("|%d", values[i][j]);
                if(LenCelulas > 1){
                    for(int n = 0; n < LenCelulas - lenInt(values[i][j]); n++){
                        printf(" ");
                    }
                }
                printf("|");
            }
            else{
                printf("%d", values[i][j]);
                if(LenCelulas > 1){
                    for(int n = 0; n < LenCelulas - lenInt(values[i][j]); n++){
                        printf(" ");
                    }
                }
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
