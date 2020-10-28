#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main(void){
    setlocale(LC_ALL,"portuguese");
    FILE *file;

    //Gravação:
    /*file = fopen("string.txt","w"); // Abre ou Cria Arquivo com o argumento "w"
    fprintf(file, "pao com mortadela\ncoxinha\nhotdog\ninscreva-se no canal"); //Escreve no arquivo
    fclose(file); // Fecha arquivo
    */

   //Editar o arquivo
    file = fopen("string.txt", "a");
    fprintf(file, "\nPrimeira Linha");
    
    char entrada[] = "\nSegunda Linha";
    fputs(entrada, file);

    char caractere = 'a';
    fputc('\n', file);
    fputc(caractere, file);

    //-------------------------------------------
    fclose(file);
    file = fopen("string.txt", "r");
    if(file == NULL){
        printf("O arquivo solicitado para abertura não existe!\n");
        getchar(); //Espera o usuario apertar algum botão
        exit(0);
    }

    char frase[100];

    while(fgets(frase, 100, file) != NULL){
        printf("%s", frase);
    }

    fclose(file);
    return 0;
}