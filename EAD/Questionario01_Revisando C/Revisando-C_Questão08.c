#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main(void){
    system("cls");
    
    int valChk, randN;
    bool try, win;
    char opt;
	const char compVar = 'N';

    try = true;
    win = false;
    srand(time(NULL));
    randN = rand() % 10;
    setlocale(LC_ALL,"Portuguese");

    while(try){
        system("cls");
        printf("=+=+=+=+=+=+=+Descubra o numero!(0 a 10)=+=+=+=+=+=+=+\n\n");
        printf("\nDigite um numero para verificar: ");
        scanf("%d", &valChk);

        if(randN == valChk){
            printf("\nVocê Acertou!");
            win = true;
            try = false;
        }

        if(!win){
            printf("Tentar novamente(N para sair)?");
            scanf("%c", &opt);
            /*toupper() deixa em maiusculo, o melhor seria criar uma função com uma variavel auxiliar para
            retornar o valor completo da string em maiusculo sem alterar a mesma, trabalhe isso com
            um loop armazenando dados nesse array auxiliar para no final retornar a cadeia de caracteres
            completa*/     
            //Compara string com a opção
            if(toupper(opt) == 'N'){
                try = false;
            }
        }
    }
    printf("\n");
    return 0;
}
