#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define NAME 40
#define TEL 15
#define EMAIL 40

/* ******************** CRIAÇÃO E STRUCTS ************************* */
typedef struct Agenda{
    char nome[NAME];
    char telefone[TEL];
    char email[EMAIL];
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
        while(aux != (Agenda *) NULL){
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

void ClearBuffer(){
    setbuf(stdin, NULL);
}

void pauseEXE(char message[]){
    printf("\n\n%s... ", message);
    ClearBuffer();
    getchar();
}

void limpaTela(){
    /*Caso o compilador não consiga limpar a tela, simplesmente será 
    pulado algumas linhas e colocado alguns asteriscos separando*/
    printf("\n\n**************************************************************************************************\n\n");
    system("cls");
}

void limpaCampos(Agenda *node){
    if(node != (Agenda *) NULL){
        strcpy(node->nome, "");
        strcpy(node->email, "");
        strcpy(node->telefone, "");
    }
}

void PerguntaNovoContato(){
    printf("----------------------------------------");
    printf("\n           INSERIR CONTATO\n");
    printf("----------------------------------------\n\n");
    printf("Cadastrar outro contato?:\n\n1 - Sim\n0 - Não\n\nResposta: ");
}

void removeBrkLn(char str[NAME]){
    int lenStr = strlen(str);
    for(int i = 0; i < lenStr; i++){
        if( str[i] == '\n' ){
            str[i] = 0;
        }
    }
}
    
/* ******************** FUNÇÕES PRINCIPAIS ************************* */

Agenda * inserirContato(Agenda *ref, char nome[NAME], char telefone[TEL], char email[EMAIL]){
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
            if(strcmp(maiuscula(nome,NAME), maiuscula(aux->nome,NAME)) < 0){
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
            for(int i = 0; i < positivo(strlen(aux->nome)-NAME);i++){
                printf(" ");
            }
            printf("|");
            printf("%s", aux->telefone);
            for(int i = 0; i < positivo(strlen(aux->telefone)-TEL);i++){
                printf(" ");
            }
            printf("|");
            printf("%s", aux->email);
            for(int i = 0; i < positivo(strlen(aux->email)-EMAIL);i++){
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
            if(strcmp(maiuscula(nome,NAME), maiuscula(aux->nome,NAME)) == 0){
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
    Agenda novo;
    Agenda *aux;
    char query[NAME];
    int cond = 0;
    int continuar = 1;

    while(cond != 4){
        limpaTela();
        printf("----------------------------------------");
        printf("\n           AGENDA TELEFONICA\n");
        printf("----------------------------------------\n");
        printf("1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar Contato\n4 - Sair\n\n");
        printf("Digite o numero correspondete a opção\ndesejada: ");
        scanf("%d", &cond);

        switch(cond){
            case 1:
                while(continuar == 1){
                    limpaTela();
                    printf("----------------------------------------");
                    printf("\n           INSERIR CONTATO\n");
                    printf("----------------------------------------\n\n");
                    printf("Preencha o Formulario abaixo:\n\n");
                    printf("Nome: ");
                    ClearBuffer();
                    fgets(novo.nome, NAME, stdin);
                    removeBrkLn(novo.nome);
                    aux = BuscarContato(minhaAgenda, novo.nome);
                    if(aux == (Agenda *) NULL){
                        printf("Email: ");
                        ClearBuffer();
                        fgets(novo.email, NAME, stdin);
                        removeBrkLn(novo.email);
                        printf("Telefone: ");
                        ClearBuffer();
                        fgets(novo.telefone, NAME, stdin);
                        removeBrkLn(novo.telefone);

                        minhaAgenda = inserirContato(minhaAgenda, novo.nome, novo.telefone, novo.email);
                    }
                    else{
                        limpaTela();
                        printf("----------------------------------------");
                        printf("\n           INSERIR CONTATO\n");
                        printf("----------------------------------------\n\n");
                        printf("\n\nEsse Nome ja foi Cadastrado!");
                        pauseEXE("Digite ENTER para continuar");
                    }
                    limpaCampos(&novo);
                    
                    limpaTela();
                    PerguntaNovoContato();
                    ClearBuffer();
                    scanf("%d",&continuar);
                    while(continuar != 1 && continuar != 0){
                        limpaTela();
                        PerguntaNovoContato();
                        ClearBuffer();
                        scanf("%d",&continuar);
                    }
                }
                break;
            case 2:
                limpaTela();
                printf("----------------------------------------");
                printf("\n           AGENDA TELEFONICA\n");
                printf("----------------------------------------\n");
                listarAgenda(minhaAgenda, "Contatos Cadastrados");
                pauseEXE("Pressione ENTER para continuar");
                break;

            case 3:
                limpaTela();
                printf("----------------------------------------");
                printf("\n           AGENDA TELEFONICA\n");
                printf("----------------------------------------\n");
                printf("\nDigite o nome para buscar:\n- ");
                ClearBuffer();
                fgets(query, NAME, stdin);
                removeBrkLn(query);
                aux = BuscarContato(minhaAgenda, query);

                if(aux != (Agenda *) NULL){
                    printf("\nResultado da Busca: \n");
                    printf("\n    Nome: %s", aux->nome);
                    printf("\n    Email: %s", aux->email);
                    printf("\n    Telefone: %s", aux->telefone);
                }
                else{
                    printf("\nResultado da Busca: \n\nNenhuma correspondencia encontrada!");
                }

                pauseEXE("Pressione ENTER para continuar");
                break;

            default:
                break;
        }
    }

    free(minhaAgenda);
    printf("\n\nEncerrando...");
    return 0;
}