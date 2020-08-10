//Chama bibliotecas e define constantes
#include <stdio.h>
#include<locale.h>
#define INSS 0.1
#define FGTS 0.08
#define PSaude 100.00

//FUNÇÕES
float desc_INSS(float salario){
	
	//Define variaveis
	float descontado;
	
	//Faz o desconto no salario
	descontado = salario * INSS;
	
	//Retorna valor
	return descontado;
}

float desc_FGTS(float salario){
	
	//Define variaveis
	float descontado;
	
	//Faz o desconto no salario
	descontado = salario * FGTS;
	
	//Retorna valor
	return descontado;
}


//PROGRAMA PRINCIPAL
int main(void){
	//Declara variaveis
	float salario, salario_aux;
	
	//Ativa acentuação
	setlocale(LC_ALL,"Portuguese");
	
	//Solicita Salario do Usuario
	printf("*****CALCULADORA DE SALARIO COM DESCONTOS*****\n\n*Esta calculadora ira retirar os descontos do\n INSS, FGTS e Plano de Saude!");
	printf("\n\nTabela de descontos:\nINSS: 10 %c \nFGTS: 8 %c \nPlano de Saúde: R$ 100,00\n\n****Digite seu Salario: ", '%', '%');
	scanf("%f", &salario);
	
	//Realiza os descontos
	salario_aux = salario;
	salario = desc_INSS(salario_aux) + desc_FGTS(salario_aux) + PSaude;
	salario = salario_aux - salario;
	
	//Imprime valores
	printf("\nSalario com descontos: R$ %2.f", salario);
		
	return(0);
	
}
