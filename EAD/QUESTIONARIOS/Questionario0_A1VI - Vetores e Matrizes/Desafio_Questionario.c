#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define MAX_TURMA 2
#define turmas 2
#define periodos 2

int main(void){
    char nome[turmas][MAX_TURMA][50];
    float nota[turmas][MAX_TURMA][periodos];
    setlocale(LC_ALL, "Portuguese");

    //Pega o nome dos alunos das duas turmas
    for(int i = 0; i < turmas; i++){
        system("cls");
        printf("-=-=-=CADASTRE OS DADOS DE 10 ALUNOS REFERENTE A 2 TURMAS-=-=-=\n");
        printf("-=-=-=-=-=-=-=-=--=-=-=ALUNOS DA TURMA %d=-=-=-=-=-=-=-=-==-=-=\n", i+1);
        printf("Digite os dados dos alunos: \n");
        for(int j = 0; j< MAX_TURMA; j++){
            printf("**Aluno Nº %d\n",j+1);
            printf("Nome: ");
            scanf("%s", &nome[i][j]);
            for(int n = 0; n < periodos; n++){
                printf("Nota P%d: ", n+1);
                scanf("%f", &nota[i][j][n]);
            }
            printf("\n");
        }
    }
    //Imprime dados da Matriz
    for(int i = 0; i < turmas; i++){
        printf("\n\n***Turma 0%d\n", i+1);
        for(int j = 0; j < MAX_TURMA; j++){
            printf("\nAluno: %s - Notas: ", nome[i][j]);
            for(int n = 0; n < periodos; n++){
                if(n == 0){
                    printf("P%d -> %.2f", n+1, nota[i][j][n]); 
                }
                else{
                    printf("    P%d -> %.2f", n+1, nota[i][j][n]); 
                }
            }
        }
    }
    printf("\n\n");
    return 0;
}