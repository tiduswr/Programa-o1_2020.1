#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nome[25];
    int idade;
    char endereco[50];
}pessoa;

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    pessoa X;

    printf("Soliciação de Dados:\n\n");
    printf("Digite seu nome: ");
    gets(X.nome);
    printf("Digite sua idade: ");
    scanf("%d", &X.idade);
    printf("Digite seu endereco: ");
    setbuf(stdin, NULL);
    gets(X.endereco);

    printf("\n\nMostrando seus dados: \n\n");
    printf("Nome %s\nIdade: %d\nEndereco: %s", X.nome, X.idade, X.endereco);

    printf("\n\n");
    return 0;
}