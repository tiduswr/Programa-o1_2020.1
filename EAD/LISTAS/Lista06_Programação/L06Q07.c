#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    float x;
    float *px = &x;

    printf("Digite um valor para X: ");
    scanf("%f", px);

    printf("\nValor de X/5: %.2f", *px/5);

    printf("\n");
    return 0;
}