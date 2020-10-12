#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/* ******************** CRIAÇÃO E STRUCTS ************************* */
typedef struct Agenda{
    char nome[40];
    char telefone[15];
    char email[40];
    struct Agenda *prox;
}Agenda;

Agenda * criaAgenda(){
    return NULL;
}

/* ******************** UTILITARIOS ************************* */

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
    if(pos >= 0 && ref != (Agenda *) NULL){
        while(aux != NULL){
            if(i == pos){
                return aux;
            }
            i++;
            aux = aux->prox;
        }
    }
    return (Agenda *) NULL;
}

int tamLista(Agenda *ref){
    if(ref != (Agenda *) NULL){
        Agenda *aux = ref;
        int i = 0;
        while(aux != NULL){
            aux = aux->prox;
            i++;
        }
        return i;
    }
    else{
        return 0;
    }
    
}

int positivo(int valor){
    if(valor < 0){
        return valor * (-1);
    }
    return valor;
}

/* ******************** FUNÇÕES PRINCIPAIS ************************* */

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
        //Procura em que posição o nome fica menor 
        while(aux != (Agenda *) NULL){
            if(strcmp(maiuscula(nome,40), maiuscula(aux->nome,40)) < 0){
                break;
            }
            i++;
            aux = aux->prox;
        }
        //Verifica se vai ser inserido no final inicio ou meio
        if(i == tamanho){
            //Final
            aux = Pos_Node(ref, i-1);
            nova->prox = criaAgenda();
            aux->prox = nova;
            return ref;
        }
        else if(i == 0){
            //Inicio
            nova->prox = ref;
            return nova;
        }
        else if(i < tamanho && i > 0){
            //Meio
            aux = Pos_Node(ref, i-1);
            nova->prox = Pos_Node(ref, i);
            aux->prox = nova;
            return ref;
        }
    }
    return (Agenda *) NULL;
}

void listarAgenda(Agenda *ref, char title[]){
    Agenda *aux = ref;
    int qtdcont = 0;
    if(ref != (Agenda *) NULL){
        printf("- %s:\n\n",title);
        printf("----------------------------------------+---------------+----------------------------------------+\n");
        printf("                  NOME                  |    TELEFONE   |                 EMAIL                  |\n");
        printf("----------------------------------------+---------------+----------------------------------------+\n");
        while(aux != NULL){
            printf("%s", aux->nome);
            for(int i = 0; i < positivo(strlen(aux->nome)-40);i++){
                printf(" ");
            }
            printf("|");
            printf("%s", aux->telefone);
            for(int i = 0; i < positivo(strlen(aux->telefone)-15);i++){
                printf(" ");
            }
            printf("|");
            printf("%s", aux->email);
            for(int i = 0; i < positivo(strlen(aux->email)-40);i++){
                printf(" ");
            }
            printf("|");
            printf("\n");
            qtdcont++;
            aux = aux->prox;
        }
        printf("----------------------------------------+---------------+----------------------------------------+\n");
        printf("Total de Contatos cadastrados: %d", qtdcont);
    }
    else{
        printf("\n- Nenhum Contato cadastrado!");
    }
    
}

Agenda * BuscarContato(Agenda *ref, char nome[]){
    if(ref != (Agenda *) NULL){
        Agenda *aux = ref;
        while(aux != NULL){
            if(strcmp(maiuscula(nome,40), maiuscula(aux->nome,40)) == 0){
                return aux;
            }
            aux = aux->prox;
        }
    }
    return (Agenda *) NULL;
}

/* ******************** MAIN ************************* */

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Agenda *minhaAgenda = criaAgenda();
    //char loop = 'S';

    minhaAgenda = inserirContato(minhaAgenda, "willian", "81762006", "harllem@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "bastiao", "34213350", "neto@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "ezequiel", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "ulisses", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "jonas", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "zeh", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "jose", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "manoel", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "1", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "ilmar", "81437783", "ezequiel@gmail.com");
    minhaAgenda = inserirContato(minhaAgenda, "abelha", "81762006", "harllem@gmail.com");

    Agenda *aux = BuscarContato(minhaAgenda, "pica");

    printf("\n\nResultado: %s\n\n", aux->nome);

    listarAgenda(minhaAgenda, "CONTATOS CADASTRADOS");

    free(minhaAgenda);
    printf("\n\n");
    return 0;
}