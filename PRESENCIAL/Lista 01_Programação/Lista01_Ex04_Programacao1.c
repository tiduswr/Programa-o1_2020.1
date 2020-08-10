#include <stdio.h>
#include <locale.h>

int main(void){
	//Declara uma variavel
	float p1, p2, p3, paux, media;
	
	//Ativa acentos no prompt
	setlocale(LC_ALL, "Portuguese");	
	
	//Solicita valores
	printf("*****SAIBA SUA MÉDIA*****\n\n");
	printf("Nota da Primeira Prova: ");
	scanf("%f", &p1);
	printf("Nota da Segunda Prova: ");
	scanf("%f", &p2);
		
	//Verifica a média das duas provas
	media = (p1 + p2)/2;
	
	//Verifica se ele ja passou direto
	if(p1 > 3 && p2 > 3 && media >= 5){
		printf("Você foi aprovado com média %f", media);
		return(0);
	}
	
	//Solicita a nota da terceira prova
	printf("Você fará uma tereira prova!\n\nDigite a nota da terceira prova: ");
	scanf("%f", &p3);
	
	//Verifica qual das duas notas é maior para somar com p3
	if(p1 > p2){
		paux = p1;
	}
	else{
		paux = p2;
	}
	
	//Calcula a nova media
	media = (paux + p3)/2;
	
	//Verifica se passou
	if(media >= 5){
		printf("\nVocê foi aprovado com média %.2f", media);
		return(0);
	}
	
	//Se chegou aqui, ele esta reprovado kkkkkkkkkkkkkkkkkkkk
	printf("\nVocê esta reprovado com média %2.f", media);
	
	return(0);
}
