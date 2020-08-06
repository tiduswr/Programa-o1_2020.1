#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Functions
int FibonacciFind(int term){
	//O numero de ouro, quando aplicado na formula de binet tende a zero, por isso o resultado n�o � exato nesta fun��o
	//A raz�o de n+1 por n n�o � exata, e o valor considerado atualmente � chamado de PHI que armazenei na variavel
	//AUREA, esta fun��o foi s� para testar uma forma nova de calculo por meio de uma fun��o fechada
	//Obs: Conforme o termo aumenta, o valor retornado pode ficar negativo!
	
	const float 	AUREA = 1.618034;
	double 			x;
	
	if(term == 1){
		return 0;
	}
	
	term = term - 1;
	x = pow(AUREA,term) - pow((1-AUREA),term);
	x = x/sqrt(5);
	return floor(x);
}

//MAIN
int main(void){
	int		lenght;
	int		option;
	
	setlocale(LC_ALL, "Portuguese");
	printf("VERIFIQUE UMA SEQUENCIA FIBONACCI:\n\n");
	printf("1. Verificar um termo 'n' na sequencia Fibonacci\n");
	printf("2. Verficiar a sequencia de termos completa\n\n");
	printf("Digite a Op��o: ");
	scanf("%d", &option);
	system("cls");
	if(option != 1 && option != 2){
		printf("\nOp��o incorreta, encerrando..\n");
		exit(0);
	}
	
	if(option == 2){
		//N�o consegui criar uma fun~��o que retornasse um array, li em foruns e disseram que n�o � possivel
		printf("VERIFIQUE UMA SEQUENCIA FIBONACCI:\n\n");
		printf("\nDigite a Quantidade de termos desejados: ");
		scanf("%d", &lenght);
		system("cls");
		if(lenght > 46){
			printf("\nOp��o incorreta, encerrando..\n");
			exit(0);
		}
		//Define variaveis para loop
		int		array[lenght];
		int		i;
		//Define valore padr�es		
		if(lenght >= 1){
			array[0] = 0;
		}
		if(lenght >= 2){
			array[1] = 1;
		}
		//Preenche vetor para lenght maior que 2
		printf("VERIFIQUE UMA SEQUENCIA FIBONACCI:\n\n");
		printf("\nSegue abaixo os termos da Sequencia Solicitada:\n\n");
		for(i=0;i<=(lenght-1);i++){
			if(lenght > 2 && i >= 2){
				array[i] = array[i-2] + array[i-1];
			}
			printf("Termo %d: %d\n", i+1, array[i]);
		}
	}
	else{
		printf("VERIFIQUE UMA SEQUENCIA FIBONACCI:\n\n");
		printf("\nDigite o termo desejado: ");
		scanf("%d", &lenght);
		system("cls");
		if(lenght > 46){
			printf("\nOp��o incorreta, encerrando..\n");
			exit(0);
		}
		
		//Verifica o termo
		int 	fibTermo;
		fibTermo = FibonacciFind(lenght);
		printf("VERIFIQUE UMA SEQUENCIA FIBONACCI:\n\n");
		printf("O valor correspondente ao termo n� %d � aproximadamente %d\n", lenght, fibTermo);
	}
	return 0;
}
