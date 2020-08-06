#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

bool isPrime(int N){	
	int		i;
	if(N != 1){
		for(i=2; i<N; i++){
			if(N%i == 0){
				return 0;
				break;
			}	
		}
	}
	return 1;
}

int main(void){
	//A questão não solicitou tratamento de erros por parte do Usuario
	int		n;
	setlocale(LC_ALL,"Portuguese");
	
	printf("VERIFIQUE SE UM NUMERO É PRIMO!!\n\n\n");
	printf("Digite o numero inteiro a ser verificado!");
	scanf("%d", &n);
	
	if(isPrime(n)){
		printf("\nSeu número é Primo!");
	}
	else{
		printf("\nSeu número não é primo");
	}
	return 0;
}
