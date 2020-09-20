#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define LENALUNOS 5
#define QTDQUESTOES 10

char OptionToStr(int value){
    switch (value){
        case 1:
            return 'a';
            break;
        case 2:
            return 'b';
            break;
        case 3:
            return 'c';
            break;
        case 4:
            return 'd';
            break;
        case 5:
            return 'e';
            break;
        default:
            return '!';
            break;
    }
};

int OptionToInt(char value){
    switch (value){
        case 'a':
            return 1;
            break;
        case 'b':
            return 2;
            break;
        case 'c':
            return 3;
            break;
        case 'd':
            return 4;
            break;
        case 'e':
            return 5;
            break;

        default:
            return 0;
            break;
    }
};

void SalvaAcertos(int gabarito[], int acertosAlunos[][QTDQUESTOES], int cartaoAluno[][QTDQUESTOES], int qtdAlunos, int qtdQuestoes){
    for(int id = 0; id < qtdAlunos; id++){
        for(int Q = 0; Q < qtdQuestoes; Q++){
            if(gabarito[Q] == cartaoAluno[id][Q]){
                acertosAlunos[id][Q] = 1;
            }
            else{
                acertosAlunos[id][Q] = 0;
            }
        }
    }
};

int contaAcertos(int acertosAlunos[][QTDQUESTOES], int idAluno, int qtdQuestoes){
    int aux = 0;
    for(int Q = 0; Q < qtdQuestoes; Q++){
        if(acertosAlunos[idAluno][Q] == 1){
            aux++;
        }
    }
    return aux;
}

void ClearBuffer(){
    setbuf(stdin, NULL);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int gabarito[QTDQUESTOES];
    char nomeAluno[LENALUNOS][50];
    int cartaoAluno[LENALUNOS][QTDQUESTOES];
    int acertosAlunos[LENALUNOS][QTDQUESTOES];
    int id;
    char aux;
    printf("**CORRETOR DE PROVAS - MULTIPLA ESCOLHA(a-e):\n\n");
    printf("*Preencha as Questões do Gabarito:\n\n");
    for(int i = 0; i < QTDQUESTOES; i++){
        printf("Questão nº %d: ", i+1);
        ClearBuffer();
        scanf("%c", &aux);
        gabarito[i] = OptionToInt(tolower(aux));
    }
    printf("\n*Preencha o Cartão resposta de cada Aluno:\n");
    for(id = 0; id < LENALUNOS; id++){
        printf("\nAluno nº %d:", id+1);
        printf("\n    Nome: ");
        ClearBuffer();
        fgets(nomeAluno[id], sizeof(nomeAluno), stdin);
        nomeAluno[id][strcspn(nomeAluno[id], "\n")] = '\0';
        printf("    Prova:\n");
        for(int j = 0; j < QTDQUESTOES; j ++){
            printf("        Questão nº %d:", j+1);
            ClearBuffer();
            scanf("%s", &aux);
            cartaoAluno[id][j] = OptionToInt(tolower(aux));
        }
    }
    
    SalvaAcertos(gabarito, acertosAlunos, cartaoAluno, LENALUNOS, QTDQUESTOES);

    printf("\n\n**Resultado por Aluno:\n\n");
    for(id = 0; id < LENALUNOS; id++){
        printf("\nNome: %s --> %d Acertos.", nomeAluno[id], contaAcertos(acertosAlunos, id, QTDQUESTOES));
    }

    printf("\n");
    return 0;
}