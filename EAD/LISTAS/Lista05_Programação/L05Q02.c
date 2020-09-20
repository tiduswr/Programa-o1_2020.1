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

void CriaRank(int arrIDS[], int arrAcertos[][QTDQUESTOES], int qtdAlunos, int qtdQuestoes){
    int temp, tempArray[qtdAlunos][qtdQuestoes];

    //Preenche array temporaria para o rank de notas
    for(int i = 0; i < qtdAlunos; i++){
        for(int j = 0; j < qtdQuestoes; j++){
            tempArray[i][j] = arrAcertos[i][j];
        }
    }

    //Organiza o rank de alunos
    for(int i = 0; i < qtdAlunos-1; i++){
        for(int j = 0; j < qtdAlunos-1; j++){
            if(contaAcertos(tempArray, j, qtdQuestoes) < contaAcertos(tempArray, j+1, qtdQuestoes)){
                temp = arrIDS[j];
                arrIDS[j] = arrIDS[j+1];
                arrIDS[j+1] = temp;
                for(int k = 0; k < qtdQuestoes; k++){
                    temp = tempArray[j][k];
                    tempArray[j][k] = tempArray[j+1][k];
                    tempArray[j+1][k] = temp;
                }
            }
        }
    }
}

void ClearBuffer(){
    setbuf(stdin, NULL);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    int gabarito[QTDQUESTOES];
    int rankID[LENALUNOS];
    char nomeAluno[LENALUNOS][50];
    int cartaoAluno[LENALUNOS][QTDQUESTOES];
    int acertosAlunos[LENALUNOS][QTDQUESTOES];
    int id, auxInt = 1;
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
        rankID[id] = id;
        for(int j = 0; j < QTDQUESTOES; j ++){
            printf("        Questão nº %d:", j+1);
            ClearBuffer();
            scanf("%s", &aux);
            cartaoAluno[id][j] = OptionToInt(tolower(aux));
        }
    }
    
    SalvaAcertos(gabarito, acertosAlunos, cartaoAluno, LENALUNOS, QTDQUESTOES);

    printf("\n\n**Resultado por Aluno:\n");
    for(id = 0; id < LENALUNOS; id++){
        printf("\nNome: %s --> %d Acertos.", nomeAluno[id], contaAcertos(acertosAlunos, id, QTDQUESTOES));
    }
    
    CriaRank(rankID, acertosAlunos, LENALUNOS, QTDQUESTOES);

    printf("\n\n*Aluno(s) com a Maior nota:\n\n");
    for(int i = 0; i < LENALUNOS; i++){
        if(contaAcertos(acertosAlunos, rankID[0],QTDQUESTOES) == contaAcertos(acertosAlunos, rankID[i],QTDQUESTOES)){
            printf("%dº - %s\n", auxInt, nomeAluno[rankID[i]]);
            auxInt++;
        }
    }
    auxInt = 1;
    printf("\n\n*Aluno(s) com a Menor nota:\n\n");
    for(int i = LENALUNOS-1; i >= 0; i--){
        if(contaAcertos(acertosAlunos, rankID[LENALUNOS-1],QTDQUESTOES) == contaAcertos(acertosAlunos, rankID[i],QTDQUESTOES)){
            printf("%dº - %s\n", auxInt, nomeAluno[rankID[i]]);
            auxInt++;
        }
    }

    printf("\n");
    return 0;
}