#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE *file;
    int vetor[5] = {1, 2, 3, 4, 5};
    int contagem;

    file = fopen("binario.txt", "wb");
    if(file == NULL){
        printf("Erro na abertura!\n\n");
        exit(0);
    }
    contagem = fwrite(vetor, sizeof(int), 5, file);
    if(contagem != 5){
        printf("Erro, nao foram gravados todos os valores");
    }
    fclose(file);

    contagem = 0;
    int leitor[5];
    file = fopen("binario.txt", "rb");
    rewind(file);
    contagem = fread(leitor, sizeof(int), 5, file);
    if(contagem != 5){
        printf("Erro, nao foram lidos todos os valores");
    }
    printf("\nImprimindo valores:\n\n");
    for(int i = 0; i < 5; i++){
        printf("%d\n", leitor[i]);
    }
    return 0;
}