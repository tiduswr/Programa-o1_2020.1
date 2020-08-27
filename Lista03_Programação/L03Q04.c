#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define LENTURMA 5

typedef struct{
    char Nome[50];
    int MatNumber;
    float NotaTeste1, NotaTeste2, NotaTeste3;
}Aluno;

typedef struct{
    float value;
    int index;
}arrIndex;

void ClearBuffer(){
    setbuf(stdin, NULL);
}

arrIndex MaxValue(Aluno arr[], int indexProva){
    int i;
    arrIndex max;
    max.value = 0;
    if(indexProva == 1){
        for(i = 0; i < LENTURMA; i++){
            if(arr[i].NotaTeste1 > max.value){
                max.value = arr[i].NotaTeste1;
                max.index = i;
            }
        }
    }
    else if(indexProva == 2){
        for(i = 0; i < LENTURMA; i++){
            if(arr[i].NotaTeste2 > max.value){
                max.value = arr[i].NotaTeste2;
                max.index = i;
            }
        }
    }
    else if(indexProva == 3){
        for(i = 0; i < LENTURMA; i++){
            if(arr[i].NotaTeste3 > max.value){
                max.value = arr[i].NotaTeste2;
                max.index = i;
            }
        }
    }
    return max;
}

float MediaNota(Aluno arr[], int indexAluno){
    return (arr[indexAluno].NotaTeste1 + arr[indexAluno].NotaTeste2 + arr[indexAluno].NotaTeste3) / 3;
}

arrIndex HigherMedia(Aluno arr[]){
int i;
float aux;
arrIndex max;
max.value = 0;
for(i = 0; i < LENTURMA; i++){
    aux = MediaNota(arr, i);
    if(aux > max.value){
        max.value = aux;
        max.index = i;
    }
}
return max;
}

arrIndex LowerMedia(Aluno arr[]){
int i;
float aux;
arrIndex min;
for(i = 0; i < LENTURMA; i++){
    if(i == 0){
        min.value = MediaNota(arr, i);
        min.index = i;
    }
    else{
        aux = MediaNota(arr, i);
        if(aux < min.value){
            min.value = aux;
            min.index = i;
        }
    }
}
return min;
}

bool isAproved(Aluno arr[], int indexAluno){
    return MediaNota(arr, indexAluno) >= 6;
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    Aluno sala[LENTURMA];
    arrIndex high, lower, maxNota;
    int i;

    for(i = 0; i < LENTURMA; i++){
        printf("**Pega dados dos Alunos:\n\n");
        printf("*Aluno nº %d\n", i+1);

        printf("Matricula: ");
        scanf("%d", &sala[i].MatNumber);
        ClearBuffer();
        printf("Nome: ");
        gets(sala[i].Nome);
        ClearBuffer();
        printf("Nota da Primeira Prova: ");
        scanf("%f", &sala[i].NotaTeste1);
        printf("Nota da Segunda Prova: ");
        scanf("%f", &sala[i].NotaTeste2);
        printf("Nota da Terceira Prova: ");
        scanf("%f", &sala[i].NotaTeste3);

        system("cls");
    }

    maxNota = MaxValue(sala, 1);
    high = HigherMedia(sala);
    lower = LowerMedia(sala);

    printf("***Resumo da Turma: \n\n");
    printf("Maior Nota da Primeira Prova -> Nome: %s | Nota: %.2f\n", sala[maxNota.index].Nome, maxNota.value);
    printf("Maior Média da Turma: -> Nome: %s | Nota: %.2f\n", sala[high.index].Nome, high.value);
    printf("Menor Média da Turma: -> Nome: %s | Nota: %.2f\n", sala[lower.index].Nome, lower.value);
    printf("\n\n***Lista de Alunos: \n\n");
    for(i = 0; i < LENTURMA; i++){
        printf("Nome: %s | Matricula: %d\n", sala[i].Nome, sala[i].MatNumber);
        printf("    Nota Prova 01: %.2f | Nota Prova 02: %.2f | Nota Prova 03: %.2f", sala[i].NotaTeste1, sala[i].NotaTeste2, sala[i].NotaTeste3);
        if(isAproved(sala, i)){
            printf("\n    Status: Aprovado!");
        }
        else{
            printf("\n    Status: Reprovado!");
        }
        printf("\n\n");
    }
    printf("\n\n");
    return 0;
}