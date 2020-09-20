#include <stdio.h>
#include <stdlib.h>

struct posicao
{
    int linha;
    int coluna;
};

typedef struct posicao POSICAO;

int main()
{
    POSICAO **ponteiroPosicao;

    ponteiroPosicao = malloc(5 * sizeof(POSICAO*));
    ponteiroPosicao[0] = malloc(sizeof(POSICAO));
    ponteiroPosicao[1] = malloc(sizeof(POSICAO));
    ponteiroPosicao[2] = malloc(sizeof(POSICAO));
    ponteiroPosicao[3] = malloc(sizeof(POSICAO));
    ponteiroPosicao[4] = malloc(sizeof(POSICAO));

    ponteiroPosicao[0]->linha = 1;
    ponteiroPosicao[0]->coluna = 1;

    ponteiroPosicao[1]->linha = 2;
    ponteiroPosicao[1]->coluna = 2;

    ponteiroPosicao[2]->linha = 3;
    ponteiroPosicao[2]->coluna = 3;
    ponteiroPosicao[3]->linha = 4;
    ponteiroPosicao[3]->coluna = 4;
    ponteiroPosicao[4]->linha = 5;
    ponteiroPosicao[4]->coluna = 5;

    printf("Primeira posicao: %d %d\n", ponteiroPosicao[0]->linha, ponteiroPosicao[0]->coluna);
    printf("Segunda posicao: %d %d\n", ponteiroPosicao[1]->linha, ponteiroPosicao[1]->coluna);
    printf("Segunda posicao: %d %d\n", ponteiroPosicao[2]->linha, ponteiroPosicao[2]->coluna);
    printf("Segunda posicao: %d %d\n", ponteiroPosicao[3]->linha, ponteiroPosicao[3]->coluna);
    printf("Segunda posicao: %d %d\n", ponteiroPosicao[4]->linha, ponteiroPosicao[4]->coluna);
    free(ponteiroPosicao[0]);
    free(ponteiroPosicao[1]);
    free(ponteiroPosicao);    

    system("pause");
}