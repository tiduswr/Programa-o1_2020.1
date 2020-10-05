#include <stdio.h>
#include <locale.h>

typedef struct{
    float p1;
    float p2;
    float p3;
}Aluno;

float media(Aluno *x){
    return (x->p1 + x->p2 + x->p3)/3;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Aluno aluno;
    Aluno *p = &aluno;

    printf("Verifique a Média do Aluno:");
    printf("\n\nDigite as Notas do aluno:\n\n");
    printf("Nota P1: ");
    scanf("%f", &p->p1);
    printf("Nota P2: ");
    scanf("%f", &p->p2);
    printf("Nota P3: ");
    scanf("%f", &p->p3);

    if(media(p) >= 7){
        printf("\nO aluno foi aprovado!!");
    }
    else{
        printf("\nO aluno foi reprovado!!");
    }

    printf("\n\n");
    return 0;    
}