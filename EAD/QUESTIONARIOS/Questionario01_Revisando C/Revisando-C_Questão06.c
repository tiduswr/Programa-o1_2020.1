#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
    double val, soma;
    int cont;

    soma = 0.0;
    cont = 1;

    system("cls");
    setlocale(LC_ALL,"Portuguese");
    while(cont <=5){
        printf("\nDigite o %dº numero: ", cont);
        scanf("%lf", &val);
        soma += val;
        cont++;
    }
    printf("\nO Resultado da soma é: %.2f\n", soma);
    return 0;
}