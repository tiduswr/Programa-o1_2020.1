#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    int hora;
    int minutos;
}hora;

typedef struct{
    int dia;
    int mes;
    int ano;
}date;

typedef struct{
    char nome[50];
    char enderecoEnc[80];
    hora horario;
    date dataEnc;
    char motivoEnc[150];
}Agenda;

void ClearBuffer(){
    setbuf(stdin, NULL);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    
    int acao, cadastrado = 0;
    char verificar[50];
    int qtdEncontros;
    printf("**Antes de começar, Digite quantos encontros serão cadastrados: ");
    scanf("%d", &qtdEncontros);
    Agenda pessoal[qtdEncontros];  

    while(acao != 0){
        if(cadastrado == 1){
            system("cls");
            printf("***Agenda de Cadastro de encontros:\n");
            printf("Digite o numero correspondente a ação desejada:\n");
            printf("\n2 - Busca\n0 - Sair\nR - ");
            scanf("%d", &acao);
            if(acao == 1){
                system("cls");
                printf("\n\nJa foram cadastrados dados, tente novamente com outra opção!\n\n");
                system("pause");
            }
            while(acao == 1){
                system("cls");
                printf("***Agenda de Cadastro de encontros:\n");
                printf("Digite o numero correspondente a ação desejada:\n");
                printf("\n2 - Busca\n0 - Sair\nR - ");
                scanf("%d", &acao);
                if(acao == 1){
                    system("cls");
                    printf("\n\nJa foram cadastrados dados, tente novamente com outra opção!\n\n");
                    system("pause");
                }
            }
        }
        else{
            system("cls");
            printf("***Agenda de Cadastro de encontros:\n");
            printf("Digite o numero correspondente a ação desejada:\n");
            printf("\n1 - Cadastro\n2 - Busca\n0 - Sair\nR - ");
            scanf("%d", &acao);
        }
        if(acao == 1){
            printf("\nDigite os dados do(s) encontros:\n");
            for(int i = 0; i < qtdEncontros; i++){
                printf("Encontro %d", i+1);
                printf("\n    Digite o nome da pessoa: ");
                ClearBuffer();
                gets(pessoal[i].nome);
                printf("    Digite o Endereço do Encontro: ");
                ClearBuffer();
                gets(pessoal[i].enderecoEnc);
                printf("    Digite a data do encontro(dia/mes/ano): ");
                scanf("%d/%d/%d", &pessoal[i].dataEnc.dia, &pessoal[i].dataEnc.mes, &pessoal[i].dataEnc.ano);
                printf("    Digie a hora do encontro(hh:min): ");
                scanf("%d:%d", &pessoal[i].horario.hora, &pessoal[i].horario.minutos);
                printf("    Digite o Motivo do Encontro: ");
                ClearBuffer();
                gets(pessoal[i].motivoEnc);
            }
            system("cls");
            cadastrado = 1;
            printf("\n\nCadastro Concluido!!\n\n");
            system("pause");
        }
        else if(acao == 2){
            system("cls");
            printf("***Busca:\nDigite o nome da pessoa para pesquisa na agenda: ");
            ClearBuffer();
            gets(verificar);

            printf("\n*Registros encontrados: \n");
            for(int i = 0; i < qtdEncontros; i++){
                if(strcmp(pessoal[i].nome, verificar) == 0){
                    printf("\nEncontro %d", i+1);
                    printf("\n    Digite o nome da pessoa: %s", pessoal[i].nome);
                    printf("\n    Digite o Endereço do Encontro: %s", pessoal[i].enderecoEnc);
                    printf("\n    Digite a data do encontro(dia/mes/ano): %d/%d/%d", pessoal[i].dataEnc.dia, pessoal[i].dataEnc.mes, pessoal[i].dataEnc.ano);
                    printf("\n    Digie a hora do encontro(hh:min): %d:%d", pessoal[i].horario.hora, pessoal[i].horario.minutos);
                    printf("\n    Digite o Motivo do Encontro: %s", pessoal[i].motivoEnc);
                }
            }
            printf("\n\n");
            system("pause");
        }
    }

    printf("\n");
    return 0;
}
