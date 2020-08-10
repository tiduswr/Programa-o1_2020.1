#include <string.h>
#include <stdio.h>

char upper(char str[], char str2[]){
    for(int i = 0; str[i] != '\0'; i++){
        str2[i] = toupper(str[i]);
    }
}

int main(void){
    system("cls");
    char *aux; //Criei um ponteiro para dinamizar a criação de vetores
    char *c = "delicia";

    aux = malloc(7 * sizeof(char));// malloc() define um tamanho de memória para o ponteiro, recebe valor inteiro referente aos bytes que se deseja criar
    upper(c, aux);
    printf("%s\n", aux);
    free(c);//Free libera a memória para utilizar depois

    c = malloc(4 * sizeof(char));// malloc() define um tamanho de memória para o ponteiro, recebe valor inteiro referente aos bytes que se deseja criar
    strcpy(c, "oba");
    aux = malloc(sizeof(c));// malloc() define um tamanho de memória para o ponteiro, recebe valor inteiro referente aos bytes que se deseja criar
    upper(c, aux);
    printf("%s\n", aux);
    free(aux); //Free libera a memória para utilizar depois
    free(c);    //Free libera a memória para utilizar depois

    printf("\n");
    return 0;    
}