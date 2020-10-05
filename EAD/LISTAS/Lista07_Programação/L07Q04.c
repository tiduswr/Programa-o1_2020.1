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

typedef struct{
    char nome[60];
    float nota;
}Aluno;

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Aluno *Alunos;
    int qtdlowG = 0, qtdAlunos = 0;
    float *NotasGerais;
    float *notasBaixa; 
    
    printf("*****VERIFIQUE AS NOTAS DA SUA TURMA*****\n\n");
    printf("Digite quantos alunos serão inseridos: ");
    scanf("%d", &qtdAlunos);
    printf("\n\n");

    Alunos = (Aluno *) malloc(sizeof(Alunos)*qtdAlunos);
    NotasGerais = (float *) malloc(sizeof(float)*qtdAlunos);

    for(int i = 0; i < qtdAlunos; i++){
        printf("**Aluno nº %d: \n", i+1);
        printf("    Digite o Nome do Aluno: ");
        setbuf(stdin, NULL);
        fgets(Alunos[i].nome, sizeof(Alunos[i].nome), stdin);
        printf("    Digite a nota do Aluno: ");
        scanf("%f", &Alunos[i].nota);
        NotasGerais[i] = Alunos[i].nota;
        printf("\n");
    }

    notasBaixa = notas_baixas(NotasGerais, qtdAlunos, &qtdlowG);

    printf("\n\nMENORES NOTAS DA TURMA:\n\n");
    for(int i = 0; i < qtdlowG; i++){
        printf("- %.2f\n", notasBaixa[i]);
    }

    free(notasBaixa);
    free(NotasGerais);
    free(Alunos);
    printf("\n\n");
    return 0;
}