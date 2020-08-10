#include <stdio.h>
#include <locale.h>

int main(void){
    char op;
    float n1,n2;

    system("cls");
    setlocale(LC_ALL,"Portuguese");
    printf("Digite um Numero, um Operador e um Numero: ");
    scanf("%f %c %f", &n1, &op, &n2);

    switch (op){
    case '+':
        printf("\n= %.2f\n\n", n1 + n2);
        break;
    
    case '-':
        printf("\n= %.2f\n\n", n1 - n2);
        break;
    default:
        printf("\nCarácter Invalido!\n\n");
    }
    return 0;
}