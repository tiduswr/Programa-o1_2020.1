#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct Agenda{
    char nome[40];
    char telefone[15];
    char email[40];
    struct Agenda *prox;
}Agenda;

Agenda * criaAgenda(){
    return NULL;
}

char * maiuscula(char str[], int tamStr){
        int i = 0;
        char *aux;
        aux = malloc(sizeof(char)*tamStr);
        while(str[i] != '\0'){
            aux[i] = toupper(str[i]);
            if(str[i+1] == '\0'){
                aux[i+1] = '\0';
            }
            i++;
        }
        return aux;
}

Agenda * Pos_Node(Agenda *ref, int pos){
    Agenda *aux = ref;
    int i = 0;

    while(aux != NULL){
        if(i == pos){
            return aux;
        }
        i++;
        aux = aux->prox;
    }

    return (Agenda *) NULL;
}

int tamLista(Agenda *ref){
    Agenda *aux = ref;
    int i = 0;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

Agenda * inserirContato(Agenda *ref, char nome[40], char telefone[15], char email[40]){
    Agenda *nova;
    nova = (Agenda *) malloc(sizeof(Agenda));
    strcpy(nova->nome, nome);
    strcpy(nova->telefone, telefone);
    strcpy(nova->email, email);

    if(ref == NULL){
        nova->prox = criaAgenda();
        return nova;
    }
    else{

        Agenda *aux = ref;
        int tamanho = tamLista(aux);
        int i = 0;

        while(strcmp(nome,aux->nome) > 0 && i <= tamanho){
            aux = aux->prox;
            i++;    
        }
        printf("%d",i);
        if(i == tamanho){
            aux = Pos_Node(ref, i-1);
            nova->prox = criaAgenda();
            aux->prox = nova;
            return ref;
        }
        if(i == 0){
            nova->prox = ref;
            return nova;
        }
        if(i < tamanho && i > 0){
            aux = Pos_Node(ref, i-2);
            nova->prox = Pos_Node(ref, i);
            aux->prox = nova;
            return ref;
        }
    }
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Agenda *minhaAgenda = criaAgenda();
    //char loop = 'S';

    minhaAgenda = inserirContato(minhaAgenda, "abelha", "81762006", "harllem@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "zz", "34213350", "neto@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "ezequiel", "81437783", "ezequiel@gmail.com");
    
    Agenda *aux = minhaAgenda;
    while(aux != NULL){
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        printf("Telefone: %s\n", aux->telefone);
        printf("\n");
        aux = aux->prox;
    }

    printf("%d", tamLista(minhaAgenda));

    free(aux);
    free(minhaAgenda);
    printf("\n\n");
    return 0;
}