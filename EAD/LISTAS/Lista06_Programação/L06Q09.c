#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    float p1;
    float p2;
    float p3;
    float media;
    int faltas;
} Aluno;

char situacao(float p1, float p2, float p3, int faltas, int totAulas, float *media){
    *media = (p1 + p2 + p3)/(float)(3);
    float porcentagem_faltas = (float)(faltas)/(float)(totAulas);
    
    if(porcentagem_faltas > 0.25){
        return 'F';
    }
    else{
        if(*media >= 6){
            return 'A';
        }
        else{
            return 'R';
        }
    }
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    char resultado;
    Aluno aluno;
    int totAulas;

    printf("**Verificar Situação do Aluno:\n\n*Informe o total de aulas(P1+P2+P3): ");
    scanf("%d", &totAulas);

    printf("\n*Agora digite as notas do aluno:\n    P1: ");
    scanf("%f", &aluno.p1);
    printf("    P2: ");
    scanf("%f", &aluno.p2);
    printf("    P3: ");
    scanf("%f", &aluno.p3);
    printf("\n\n*Total de Faltas do Aluno(P1+P2+P3): ");
    scanf("%d", &aluno.faltas);
    
    resultado = situacao(aluno.p1, aluno.p2, aluno.p3, aluno.faltas, totAulas, &aluno.media);
    printf("\n**Resumo do Aluno:\n");
    switch(resultado){
        case 'A':
            printf("    Situação: Aprovado(Por Média)!\n    Média do Aluno: %.1f", aluno.media);
            break;

        case 'R':
            printf("    Situação: Reprovado(Por Média)!\n    Média do Aluno: %.1f", aluno.media);
            break;

        case 'F':
            printf("    Situação: Reprovado por Falta!!\n    Média do Aluno: %.1f", aluno.media);
            break;

        default:
            break;
    }
    printf("\n\n");
    return 0;
}