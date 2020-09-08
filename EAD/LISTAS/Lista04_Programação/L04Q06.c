#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define LEN 5

typedef struct{
    char titulo[70];
    int ano;
    char autor[50];
}book;

void ClearBuffer(){
    setbuf(stdin, NULL);
}

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    book books[LEN];
    char auxTitulo[50]; 

    printf("***Cadastro de Livros: \n\n");
    printf("**Preencha com os livros:\n\n");
    for(int i = 0; i < LEN; i++){
        printf("\nLivro %d:", i+1);
        printf("\n    Titulo: ");
        gets(books[i].titulo);
        ClearBuffer();
        
        printf("    Ano: ");
        scanf("%d", &books[i].ano);
        ClearBuffer();
        
        printf("    Autor: ");
        gets(books[i].autor);
        ClearBuffer();
    }
    system("cls");
    printf("***Cadastro de Livros: \n\n");
    printf("\n*Qual o TITULO que você deseja procurar? ");
    gets(auxTitulo);

    printf("\n\n*Titulos encontrados: \n");
    for(int i = 0; i < LEN; i++){
        if(strcmp(auxTitulo, books[i].titulo) == 0){
            printf("\nLivros[Pos. %d]:\n  Titulo: %s\n  Autor: %s\n  Ano: %d", i+1, books[i].titulo, books[i].autor, books[i].ano);
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}