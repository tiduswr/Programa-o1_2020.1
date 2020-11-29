#include <stdio.h>
#include <locale.h>

float maior_valor(float val1, float val2, float val3){
	//Cria variavel auxiliar
	float val_aux;
	
	//Atribui valor a variavel
	val_aux = 0;
	
	//Verifica qual o maior
		if(val1 > val_aux){
			val_aux = val1;	
		}
		if(val2 > val_aux){
			val_aux = val2;	
		}	
		if(val3 > val_aux){
			val_aux = val3;	
		}
	return val_aux;
}

float menor_valor(float val1, float val2, float val3){
	//Cria variavel auxiliar
	float val_aux;
	
	//Atribui valor a variavel
	val_aux = val1;
	
	//Verifica qual o menor
		if(val2 < val_aux){
			val_aux = val2;	
		}	
		if(val3 < val_aux){
			val_aux = val3;	
		}
	return val_aux;
}
	
int main(void){
	//Declara variaveis
	float val1, val2, val3, maior, menor, meio;
	
	//Solicita valores
	printf("*****VERIFICA VALORES*****\n\n");
	printf("Primeiro Valor: ");
	scanf("%f", &val1);
	printf("Segundo valor: ");
	scanf("%f", &val2);
	printf("Terceiro valor: ");
	scanf("%f", &val3);	
	
	//Ativa acentos no prompt
	setlocale(LC_ALL, "Portuguese");

	//Verifica o maior e o menor valor
	maior = maior_valor(val1, val2, val3);
	menor = menor_valor(val1, val2, val3);
	
	// Verifica o valor do meio
	if(val1 != maior && val1 != menor){
		meio = val1;
	}
	if(val2 != maior && val2 != menor){
		meio = val2;
	}	
	if(val3 != maior && val3 != menor){
		meio = val3;
	}
	
	//Imprimir os valores
	printf("\nSequencia Crescente: %2.f; %2.f e %2.f", menor, meio, maior);
	
	return(0);
	
}
	
