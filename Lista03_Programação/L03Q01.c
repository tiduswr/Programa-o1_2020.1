#include <stdio.h>
#include <locale.h>

typedef struct{
    int posicao;
    int valor;
}Fibonacci;

int fibonacci(int n){
   if(n==1 || n==2)
       return 1;
   else
       return fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Fibonacci X;

    printf("Digite um numero da Sequ�ncia Fibonacci: ");
    scanf("%d", &X.posicao);
    
    X.valor = fibonacci(X.posicao);
    system("cls");
    printf("O numero correspondente a posi��o informada �: \n\n");
    printf("Posi��o %d: %d", X.posicao, X.valor);
    
    printf("\n");
    return 0;
}