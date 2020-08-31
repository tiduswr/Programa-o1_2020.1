#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void){

    char senha[] = "password";
    char tentativa[10];
    int retorno;

    setlocale(LC_ALL,"Portuguese");
    system("cls");
    printf("Digite a entrada: ");
    gets(tentativa);

    retorno = strcmp(senha,tentativa);

    if(retorno == 0){
        printf("Senha Correta!\n\n");
    }
    else{
        printf("Senha Incorreta!\n\n");
    }

    return 0;

}