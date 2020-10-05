#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int *par = (int *) malloc(sizeof(int)), *impar = (int *) malloc(sizeof(int));
    int aux, contPar = 0, contImpar = 0;

    printf("Organiza 15 inteiros em Arrays dinamicas\n\n");
    for(int i = 0; i < 15; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &aux);

        if(aux % 2 == 0){
            if(contPar > 0){
                par[contPar] = (int) malloc(sizeof(int));
            }
            par[contPar] = aux;
            printf("***added %d to 'par'\n", par[contPar]);
            contPar++;
        }
        else{
            if(contImpar > 0){
                impar[contImpar] = (int) malloc(sizeof(int));
            }
            impar[contImpar] = aux;
            printf("***added %d to 'impar'\n", impar[contImpar]);
            contImpar++;
        }
    }

    system("cls");   
    printf("Organiza 15 inteiros em Arrays dinamicas");
    printf("\n\nValores Pares:\n\n");
    for(int i = 0; i < contPar; i++){
        printf("- %d\n", par[i]);
    }
    printf("\n\nValores Impares:\n\n");
    for(int i = 0; i < contImpar; i++){
        printf("- %d\n", impar[i]);
    }

    free(par);
    free(impar);
    printf("\n\n");
    return 0;
}