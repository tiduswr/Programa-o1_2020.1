#include <stdio.h>
#include <locale.h>


int main(void){

    int col, ln, n;

    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um Número: ");
    scanf("%d", &n);

    for(ln = 1; ln <= n; ln++){
        for(col = 1; col <= n; col++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;

}