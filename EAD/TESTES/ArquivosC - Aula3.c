#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void copiaDados(FILE *file1, FILE *file2){
    char leitor[1000];

    while(fgets(leitor, 1000, file1) != NULL){
        fputs(leitor, file2);
    }
}

int main(void){
    setlocale(LC_ALL,"portuguese");
    FILE *file1 = fopen("string.txt", "r");
    FILE *file2 = fopen("string_copia.txt", "w");

    if(file1 == NULL){
        printf("O arquivo 1 não existe, verifique o diretorio novamente!\n");
        getchar();
        exit(0);
    }

    copiaDados(file1, file2);

    fclose(file1);
    fclose(file2);
    return 0;
}