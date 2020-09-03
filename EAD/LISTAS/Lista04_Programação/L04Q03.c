#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 3

int maior(int Arr[], int lenArr){
    int aux;

    for(int i = 0; i < lenArr; i++){
        if(i == 0){
            aux = Arr[i];
        }
        else{
            if(Arr[i] > aux){
                aux = Arr[i];
            }
        }
    }

    return aux;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    int array[N];

    printf("**Verifique o maior valor: \n\n*Digite %d Numeros para verificar:\n\n", N);
    for(int i = 0; i < N; i++){
        printf("Numero[%d]: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\n\n**O maior numero é o: %d", maior(array, N));

    printf("\n");
    return 0;
}