#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float *notas_baixas(float array[], int tamarr, int *qtdlowG){
    float *lowG = (float *) malloc(sizeof(float)*5);
    for(int i = 0; i < tamarr; i++){
        if(array[i] < 5){
            if(i > 0){
                lowG = (float *) realloc(lowG, (*qtdlowG + 1) * sizeof(lowG[i]));
            }
            lowG[*qtdlowG] = array[i];
            *qtdlowG = *qtdlowG + 1;
        }
    }
    return lowG;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    float notas[] = {6, 6, 7, 8, 9, 3, 4, 2, 1, 4.9};
    int qtdlowG = 0;
    float *notasBaixa; 
    
    notasBaixa = notas_baixas(notas,(int) sizeof(notas)/sizeof(float), &qtdlowG);

    printf("MENORES NOTAS:\n\n");
    for(int i = 0; i < qtdlowG; i++){
        printf("- %.2f\n", notasBaixa[i]);
    }

    free(notasBaixa);
    printf("\n\n");
    return 0;
}