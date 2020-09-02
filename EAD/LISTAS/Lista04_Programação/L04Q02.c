#include <stdio.h>
#include <locale.h>

typedef struct{
    int qtdNum, startNum;
}SomaN;

int main(void){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    SomaN X;
    int aux;
    printf("***Verifique uma sequencia(Par ou Impar) a partir de um numero digitado:\n\n");
    printf("Quantos numeros deseja? ");
    scanf("%d", &X.qtdNum);
    printf("Qual o numero inicial? ");
    scanf("%d,", &X.startNum);
    
    //Verifica qual será o primeiro termo da sequencia, sem tratamento de erros por parte do usuario!
    if(X.qtdNum % 2 == 0){
        if(X.startNum % 2 == 0){
            aux = X.startNum;
        }
        else{
            aux = X.startNum + 1;
        }
    }
    else if(X.qtdNum % 2 != 0){
        if(X.startNum % 2 == 0){
            aux = X.startNum + 1;
        }
        else{
            aux = X.startNum;
        }
    }

    printf("\n\nSequencia de Numeros solicitados:\n\n");
    for(int i = 0; i < X.qtdNum; i++){
        if(i != X.qtdNum - 1){
            printf("%d, ", aux);
        }
        else{
            printf("%d", aux);
        }
        //O proximo termo de uma sequencia de numero par ou impar, será n+2
        aux = aux + 2;
    }

    printf("\n");
    return 0;
}