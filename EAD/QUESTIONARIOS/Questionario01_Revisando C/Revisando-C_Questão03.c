#include <stdio.h>
#include <locale.h>

int main(void){

    int p1, p2;
    float media;

    system("cls");
    setlocale(LC_ALL,"Portuguese");
    printf("Prova de Frec1 = ");
    scanf("%d", &p1);
    printf("Prova de Frec2 = ");
    scanf("%d", &p2);

    media = (p1 + p2) / 2;

    if(media >= 14){
        printf("\nAprovado!\n\n");
    }
    else if(media < 7){
        printf("\nReprovado!\n\n");
    }
    else{
        printf("Prova Final!\n\n");
    }
    return 0;
}