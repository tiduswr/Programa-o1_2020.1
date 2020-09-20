#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void ClearBuffer(){
    setbuf(stdin, NULL);
}

typedef struct{
    char autor[50];
    char titulo[90];
    int ISBN;
    int status;
}books;

int main(void){
    setlocale(LC_ALL, "Portuguese");
    printf("Esse programa não possui tratamento para erros do usuario, tenha atenção ao selecionar uma opção!!\n\n");
    system("pause");

    books **me;
    int quit = 0;
    int cadastrado = 0;
    int opt = 0;
    int qtdLivros = 0;
    int continuarCad;
    char auxStr[90];

    while(quit == 0){
        system("cls");
        printf("***** MINHA BIBLIOTECA *****");
        printf("\n\nSelecione uma das Opções:\n\n");
        printf("01 - CADASTRAR LIVROS\n02 - BUSCAR LIVRO\n03 - Lista livros não lidos\n04 - Sair\n\nR - ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                continuarCad = 0;
                if(cadastrado == 1){
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\n");
                    printf("Dados anteriores serão perdidos, deseja mesmo continuar?\n\n1 - SIM\n2 - Não\n\nR - ");
                    scanf("%d", &continuarCad);
                    if(continuarCad == 1){
                        //Liberação de memória
                        for(int i = 0; i < qtdLivros; i++){
                            free(me[i]);
                        }
                        free(me);
                    }
                    else{
                        continuarCad = 0;
                    }
                }
                else{
                    continuarCad = 1;
                }

                if(continuarCad == 1){
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\n");
                    printf("Quantos Livros serão Cadastrados?\nR - ");
                    scanf("%d", &qtdLivros);

                    //Alocação dinamica de livros
                    me = malloc(qtdLivros * sizeof(books));
                    for(int i = 0; i < qtdLivros; i++){
                        me[i] = malloc(sizeof(books));
                    }

                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\n");
                    printf("Preencha os dados a seguir para cada Livro:\n\n");

                    for(int i = 0; i < qtdLivros; i++){
                        printf("\nLivro %d:", i+1);
                        printf("\n    Titulo: ");
                        ClearBuffer();
                        fgets(me[i]->titulo, sizeof(me[i]->titulo), stdin);
                        printf("    Autor: ");
                        ClearBuffer();
                        fgets(me[i]->autor, sizeof(me[i]->autor), stdin);
                        printf("    IBSM: ");
                        scanf("%d", &me[i]->ISBN);
                        printf("    Você ja Leu esse livro?\n\n    1 - Sim\n    2 - Não\n\n    R - ");
                        scanf("%d", &me[i]->status);
                    }

                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****");
                    printf("\n\nLIVROS CADASTRADOS!\n\n");
                    system("pause");
                    cadastrado = 1;
                }
                break;
            case 2:
                if(cadastrado == 1){
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\n");
                    printf("Digite um Titulo ou Autor para Pesquisar: ");
                    ClearBuffer();
                    fgets(auxStr, sizeof(auxStr), stdin);

                    printf("\n\nLivros encontrados:\n\n");
                    for(int i = 0; i < qtdLivros; i++){
                        if(strcmp(auxStr, me[i]->titulo) == 0 || strcmp(auxStr, me[i]->autor) == 0){
                            printf("Livro %d:\n    Titulo: %s    Autor: %s    ISBN: %d", i+1, me[i]->titulo, me[i]->autor, me[i]->ISBN);
                            if(me[i]->status == 1){
                                printf("\n    Status: Lido\n");
                            }
                            else{
                                printf("\n    Status: Não Lido\n");
                            }
                        }
                    }
                    printf("\n\n");
                    system("pause");
                }
                else{
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\nNenhum Livro Cadastrado!\n\n");
                    system("pause");
                }
                
                break;
            case 3:
                if(cadastrado == 1){
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\n");
                    printf("Lista de Livros Não Lidos:\n\n");
                    for(int i = 0; i < qtdLivros; i++){
                        if(me[i]->status == 2){
                            printf("Livro %d:\n    Titulo: %s    Autor: %s    ISBN: %d", i+1, me[i]->titulo, me[i]->autor, me[i]->ISBN);
                            if(me[i]->status == 1){
                                printf("\n    Status: Lido\n");
                            }
                            else{
                                printf("\n    Status: Não Lido\n");
                            }
                        }
                    }
                    printf("\n\n");
                    system("pause");
                }
                else{
                    system("cls");
                    printf("***** MINHA BIBLIOTECA *****\n\nNenhum Livro Cadastrado!\n\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                printf("***** MINHA BIBLIOTECA *****\n\n");
                printf("Volte mais vezes!!\n\nby TidusWR(Harllem)");
                quit = 1;
                break;        
            default:
                system("cls");
                printf("***** MINHA BIBLIOTECA *****\n\n");
                printf("Opção Incorreta!");
                printf("\n\n");
                system("pause");
                break;
        }

    }
        
    //Liberação de memória
    for(int i = 0; i < qtdLivros; i++){
        free(me[i]);
    }
    free(me);
    printf("\n");
    return 0;
}