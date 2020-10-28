// HARLLEM ALVES DO NASCIMENTO - PERIODO 2 DE COMPUTAÇÃO - UEPB CAMPUS VII

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void copiaDados(FILE *file1, FILE *file2){
    char leitor[1000];

    setbuf(stdin, NULL);
    while(fgets(leitor, 1000, file1) != NULL){
        fputs(leitor, file2);
    }
}

int main(void){
    setlocale(LC_ALL,"portuguese");

    FILE *file1;
    char valor[100];
    char leitor[100];

    //Verifica se existe e salva alguns dados, caso não
    file1 = fopen("comidas.txt","r");
    if(file1 == NULL){
        file1 = fopen("comidas.txt","w");
        fprintf(file1, "pao com mortadela\ncoxinha\nhotdog\nlasanha\n");    
    }
    
    //Abre em modo gravação
    fclose(file1);
    file1 = fopen("comidas.txt","a");
    
    //Solicita um dado para o usuario e salva no arquivo
    printf("****** TESTE DE CRIAÇÃO DE ARQUIVOS\n\nDigite algo para salvar no arquivo: ");
    setbuf(stdin, NULL);
    fgets(valor, 100, stdin);
    fprintf(file1, valor);

    //Faz a copia do arquivo para um novo
    fclose(file1);
    file1 = fopen("comidas.txt","r");
    FILE *file2 = fopen("comidas_copia.txt", "w");
    copiaDados(file1, file2);

    rewind(file1); //Volta ao inicio do arquivo
    printf("\n\nImprimindo Arquivo 1:\n\n");
    while(fgets(leitor, 100, file1) != NULL){
        printf("%s", leitor);
    }

    printf("\n\nO arquivo foi alterado, fiz um copia e salvei!\n\n");

    fclose(file1);
    fclose(file2);
    return 0;
}