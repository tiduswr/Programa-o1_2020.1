#include <stdio.h>
#include <locale.h>
#include <time.h> //biblioteca para manipular hora
#include <stdlib.h> //Contem biblioteca da fun��o rand() e srand()

int main(void){
    int i;

    system("cls");
    setlocale(LC_ALL,"Portuguese");
    printf("Gerando 10 valores aleat�rios: \n\n");

    srand(time(NULL));

    for(i=0; i<10; i++){
        printf("%d, ", rand() % 100);
    }
    printf("\n");
    return 0;
}