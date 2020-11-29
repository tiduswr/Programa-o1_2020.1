#include <stdlib.h>
#include <stdio.h>

int main(void){

    FILE * arquivo = NULL;
    int * inteiros;
    inteiros = (int) malloc(sizeof(int)*10);

    for(int i = 0; i < 10; i++){
        inteiros[i] = i*2 + 3;
    }
    inteiros = (int) realloc(inteiros, sizeof(int)*11);
    inteiros[10] = 0;

    arquivo = fopen("data.dat", "wb");
    
    if(arquivo == NULL){
        printf("Arquivo Não Aberto!");
    }
    else{
        fwrite(inteiros, sizeof(int), 11, arquivo);
    }

    int *teste;
    teste = (int) malloc(sizeof(int)*11);
    
    fclose(arquivo);
    arquivo = NULL;
    arquivo = fopen("data.dat", "rb");
    if(arquivo == NULL){
        printf("Arquivo não Aberto!");
    }
    else{
        fread(teste, sizeof(int), 11, arquivo);
    }

    for(int i = 0; i < 11; i++){
        printf("%d, ", teste[i]);
    }
}