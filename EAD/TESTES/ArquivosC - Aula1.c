#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main(void){
    setlocale(LC_ALL,"portuguese");
    FILE *file;

    //Gravação:
    file = fopen("numeros.txt","r"); // Faz leitura com o argumento"r"
    if(file == NULL){
        //Cuidado ao usar o "w" pois ele apaga os dados se o arquivo ja existir
        file = fopen("numeros.txt","w"); // Cria Arquivo com o argumento "w"
        fprintf(file, "10 20 30"); //Escreve no arquivo
        //Reabrindo como leitura
        fclose(file);
        file = fopen("numeros.txt","r"); // Faz leitura com o argumento"r"
    }

   //Leitura
    int x, y, z;
    if(file == NULL){
        printf("Não existe nenhum arquivo para editar!\n");
    }
    else{
        fscanf(file, "%d %d %d", &x, &y, &z);
        printf("%i %i %i", x, y, z);
    }
    
    fclose(file);
    return 0;
}