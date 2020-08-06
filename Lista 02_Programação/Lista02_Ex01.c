#include <stdio.h>

typedef struct{
	int igual;
	int maior;
	int menor;
}Dimensao;

int main(void){
	
	//Define variaveis
	int vetnum[10];
	int i, comparar;
	Dimensao grandeza;
	
	grandeza.maior = 0;
	grandeza.menor = 0;
	grandeza.igual = 0;
		
	//Solicita valores
	printf("====== COMPARA VALORES EM UM VETOR ======");
	printf("\n\nDigite os valores solicitados: \n\n");
	//Preenche os valores da matriz
	for(i = 0; i < 10; i++){
		printf("Valor %d: ", i + 1);
		scanf("%d", &vetnum[i]);
	}
	
	//Solicia valor para ser comparado na Matriz
	system("cls");
	printf("====== COMPARA VALORES EM UM VETOR ======");
	printf("\n\nDigite um valor a ser comparado: ");
	scanf("%d", &comparar);
	i = 0;
	
	//Verifica quantos valores são maiores e quantos valores são menores
	for(i = 0; i < 10; i++){
		if(comparar < vetnum[i]){
			grandeza.maior++;
		}
		else if(comparar > vetnum[i]){
			grandeza.menor++;
		}
		else if(comparar == vetnum[i]){
			grandeza.igual++;
		}
	}
	
	printf("Maior: %d\nMenor: %d\nIgual: %d", grandeza.maior, grandeza.menor, grandeza.igual);
	
	return (0);
}
