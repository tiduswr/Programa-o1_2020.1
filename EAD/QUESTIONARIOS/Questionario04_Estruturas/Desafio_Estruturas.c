#include <stdio.h>

struct dataN{
	int d,m,a;
};
struct Endereco{;
    char log[30];
    char bairro[30];
    int numero;
};
struct Aluno{
	int matricula;
	char nome[50];
	struct dataN d;
    struct Endereco endereco;
};

void ler(struct Aluno lista[], int lenVet){
	
    int i;

    for (i=0;i<lenVet;i++){
        printf("Insira a matricula do aluno %d: ",i+1);
        scanf("%d",&lista[i].matricula);
        printf("Insira o nome do aluno %d: ",i+1);
        fflush(stdin);
        gets(lista[i].nome);
        printf("Insira a data de nascimento aluno %d: ",i+1);
        scanf("%d/%d/%d",&lista[i].d.d,&lista[i].d.m,&lista[i].d.a);
        printf("Insira a Rua do aluno %d: ",i+1);
        fflush(stdin);
        gets(lista[i].endereco.log);
        printf("Insira o Bairro do aluno %d: ",i+1);
        fflush(stdin);
        gets(lista[i].endereco.bairro);
        printf("Insira o Numero aluno %d: ",i+1);
        scanf("%d",&lista[i].endereco.numero);
    }

    printf("\nImprime dados:");
    for (i=0;i<lenVet;i++){
        printf("\n\n\nA matricula do aluno %s eh %d\n", lista[i].nome, lista[i].matricula);
        printf("Data de nascimento: %d/%d/%d\n", lista[i].d.d, lista[i].d.m, lista[i].d.a);
        printf("Endereco: Rua %s, Bairro %s, Numero %d", lista[i].endereco.log, lista[i].endereco.bairro, lista[i].endereco.numero);
    }
	
}


int main(void){
printf("Estruturas (Registros)\n");
struct Aluno lista[2];

ler(lista, 3);

return(0);
}