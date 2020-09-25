#include <stdio.h>
#include <locale.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int a, b;

    printf("**Digite dois valores:\n\n*Valor 1: ");
    scanf("%d", &a);
    printf("*Valor 2: ");
    scanf("%d", &b);

    printf("\n\nExecutando Swap...\n");
    swap(&a, &b);

    printf("\n\n**Resultado:\n\n*Valor 1: %d\n*Valor 2: %d", a, b);

    printf("\n");
    return 0;
}