#include <stdio.h>
#include <locale.h>

void swapVal(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    //Define variaveis
    int x, y;

    //Solicita valores
    printf("Insira os valores para realizar a troca:\n\n");
    printf("Digite o Valor 01: ");
    scanf("%d", &x);
    printf("Digite o Valor 02: ");
    scanf("%d", &y);

    //Faz a troca e mostra o resultado
    swapVal(&x, &y);
    printf("\n\n**Verifique a troca dos valores:\n\nValor 01: %d\nValor 02: %d", x, y);

    printf("\n\n");
    return 0;
}