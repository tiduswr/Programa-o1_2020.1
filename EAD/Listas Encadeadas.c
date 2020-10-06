#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*  Fui obrigado a colocar o nome da struct repetida, pois dava um erro que não
    interferia diretamente no codigo, mas era chato de ver que tinha um erro acontecendo,
    vi em um fórum e o que encontrei foi essa postagem com um problema parecido com o meu: 
    https://www.vivaolinux.com.br/topico/C-C++/assignment-from-incompatible-pointer-type-Wincompatible-pointer-types
*/
typedef struct lista{
    int info;
    struct lista *prox;
}lista;

lista * criar(){
    return NULL;
}

lista * inserir_no_inicio(lista *dados, int valor){
    lista *novo;
    novo = (lista *) malloc(sizeof(lista));
    novo->info = valor;

    if(dados == NULL){
        novo->prox = NULL;
        return novo;
    }
    else{
        novo->prox = dados;
        return novo;
    }
}

lista * inserir_no_final(lista *dados, int valor){
    lista *novo;
    novo = (lista *) malloc(sizeof(lista));
    novo->info = valor;
    
    if(dados == NULL){
        novo->prox = criar();
        return novo;
    }
    else{
        lista *PontAux = dados;

        //Procura o primeiro valor, que esta com o ponteiro NULL
        while(PontAux->prox != NULL){
            PontAux = PontAux->prox;
        }
        /*Ao achar o valor, ele troca o NULL desse elemento para um endereço de outro ponteiro,
        que foi configurado como NULL no elemento Prox, assim ele vira o novo primeiro elemento da lista*/
        novo->prox = criar();
        PontAux->prox = novo;
        
        /*Dessa vez é retornado dados, pois o Pont aux, modificou o primeiro elemento da lista original
            o que aconteceu foi uma mudança dos valores de "dados", e ja foi vinculado o novo elemento
            na propria lista dados*/
        return dados;
    }
}

void busca(lista *dados, int valor){
    lista *aux = dados;

    while(aux != NULL){
        if(aux->info == valor){
            printf("\n\nO valor %d esta contido na lista!!\n", valor);
        }
        aux = aux->prox;
    }
}

void imprimir(lista *dados){
    lista *aux = dados;

    printf("\n\nValores contidos na lista:\n");
    while(aux != NULL){

        printf("\n- %d", aux->info);

        aux = aux->prox;
    }
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    lista *inicio = criar();

    printf("Como funciona as listas encadeadas:");
    
    inicio = inserir_no_final(inicio, 100);
    inicio = inserir_no_final(inicio, 400);
    
    busca(inicio, 100);
    imprimir(inicio);

    free(inicio);
    printf("\n\n");
    return 0;
}