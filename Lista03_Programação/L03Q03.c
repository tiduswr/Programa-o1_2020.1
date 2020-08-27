#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define LENTURMA 2

typedef struct{
    char Nome[50];
    int MatNumber;
    char Curso[25];
}Aluno;

void ClearBuffer(){
    setbuf(stdin, NULL);
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    Aluno sala[LENTURMA];
    int i;

    for(i = 0; i < LENTURMA; i++){
        printf("Recebe dados: \n\n");
        printf("Digite a Matricula: ");
        scanf("%d", &sala[i].MatNumber);
        printf("Digite o Nome do Aluno: ");
        ClearBuffer();
        gets(sala[i].Nome);
        printf("Digite o Curso do Aluno: ");
        ClearBuffer();
        gets(sala[i].Curso);
        system("cls");
    }

    printf("Imprime dados: \n\n");
    for(i = 0; i < LENTURMA; i++){
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\nMatricula: %d\nCurso: %s\n\n", sala[i].Nome, sala[i].MatNumber, sala[i].Curso);
    }
    printf("\n\n");
    return 0;
}