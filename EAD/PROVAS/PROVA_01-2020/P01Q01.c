#include <stdio.h>
#include <locale.h>
#define LEN 10

void ZeraArray(int arr[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        arr[i] = 0;
    }
}

int Par(int value){
    if(value % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void deletaAntigo(int arr[], int tamanho){
    for(int i = 0; i < tamanho-1; i++){
        arr[i] = arr[i + 1];
    }
    arr[tamanho-1] = 0;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int impar[LEN], par[LEN];
    int contPar = 0, contImpar = 0, aux;

    ZeraArray(par, LEN);
    ZeraArray(impar, LEN);

    printf("***Organizar numeros inteiros em vetores:\n");
    printf("**Digite 15 valores:\n\n");
    for(int i = 0; i < 15; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &aux);
        if(aux % 2 == 0){
            if(contPar <= 9){
                par[contPar] = aux;
                contPar++;
            }
            else{
                deletaAntigo(par, LEN);
                par[contPar-1] = aux;
            }
        }else{
            if(contImpar <=9){
                impar[contImpar]= aux;
                contImpar++;
            }
            else{
                deletaAntigo(impar, LEN);
                impar[contImpar-1]= aux;
            }
        }
    }

    //Imprime valores
    printf("\n\n*Imprime Vetores:\n");
    for(int i = 0; i < LEN; i++){
        printf("%d ", par[i]);
    }
    printf("\n");
        for(int i = 0; i < LEN; i++){
        printf("%d ", impar[i]);
    }
    
    printf("\n");
    return 0;
}