#include <stdio.h>
#include <locale.h>

/*  Sobre pegar valores com a fun��o scanf():
    %d - inteiro
    %f - real
    %c - car�cter
    %s - string de caracteres*/

int main(void){

    int a, b, soma;

    setlocale(LC_ALL,"Portuguese");
    system("cls");
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d",&b);

    soma = a + b;

    printf("\nA soma de %d + %d � %d\n\n", b, a, soma);

    return 0;
}