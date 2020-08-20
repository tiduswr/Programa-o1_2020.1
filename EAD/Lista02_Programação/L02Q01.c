#include <stdio.h>
#include <locale.h>
#define maxLen 30

void saveValue(int value, int array[], int len){
    for(int i = 0; i < len; i++){
        if(array[i] == NULL){
            array[i] = value;
            break;
        }
    }
}

int findValue(int value, int array[], int len){
    for(int i = 0; i < len; i++){
        if(array[i] == value){
            return 1;
        }
    }
    return 0;
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    //Define variaveis
    int aux, values[maxLen];

    //Inicializa array
    for(int i = 0; i < maxLen; i++){
        values[i] = NULL;
    }
    
    //Pega valores
    printf("**Digite até 30 valores(Digite 0 para Parar)\n\n");
    for(int i = 0; i < maxLen; i++){
        printf("Valor nº %d: ", i + 1);
        scanf("%d", &aux);
        saveValue(aux, values, maxLen);
        if(aux == 0){break;}
    }

    //Solicita um valor para buscar no array
    system("cls");
    printf("**Procure um numero no Array informado anteriormente: \n\n");
    printf("Digite o valor para procurar: ");
    scanf("%d", &aux);
    if(aux == 0){
        while(aux == 0){
            printf("\nDigite um valor maior que 0: ");
            scanf("%d", &aux);
        }
    }
    if(findValue(aux, values, maxLen) == 1){
        printf("\nValor encontrado!");
    }
    else{
        printf("\nValor não encontrado!");
    }

    //Imprime valores
    printf("\n\nDigite 1 para imprimir o Array! ");
    scanf("%d", &aux);
    if(aux == 1){
        system("cls");
        printf("Imprimindo Array...\n\n");
        for(int i = 0; i < maxLen; i++){
            if(values[i] != NULL){
                printf("\nValor nº %d: %d", i+1, values[i]);
            }
        }
    }
    printf("\n\n");
    return 0;
}