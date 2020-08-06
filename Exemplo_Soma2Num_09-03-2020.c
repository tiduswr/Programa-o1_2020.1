#include <stdio.h>

int main (void)
{

// Declara variaveis
int n1, n2, res, opcao; 

//Solicita valores
printf("Primeiro Numero: ");
scanf("%d", &n1);
printf("Segundo Numero: ");
scanf("%d", &n2);

//Verifica qual operação o usuario deseja realizar
printf("Seleciona uma das operações abaixo:");
printf("1. Soma");
printf("2. Subtração");
printf("3. Multiplicação");
printf("4. Divisão");
printf("");
scanf("%d", &opcao);

//Opção caso seja soma
if (opcao = 1);
{
    res = n1 + n2;
    printf("%d", res);
}

//Opção caso seja subtração
if (opcao = 2);
{
    res = n1 - n2;
    printf("%d", res);
}    

//Opção caso seja multiplicação
if (opcao = 3);
{
    res = n1 * n2;
    printf("%d",res);
}

//Opção caso seja divisão
if (opcao = 4);
{
    res = n1 / n2;
    printf("%d",res);
}    

return 0;

}