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
	//A quest�o n�o solicitou tratamento de erros por parte do Usuario
	int		n;
	setlocale(LC_ALL,"Portuguese");
	
	printf("VERIFIQUE SE UM NUMERO � PRIMO!!\n\n\n");
	printf("Digite o numero inteiro a ser verificado!");
	scanf("%d", &n);
	
	if(isPrime(n)){
		printf("\nSeu n�mero � Primo!");
	}
	else{
		printf("\nSeu n�mero n�o � primo");
	}
	return 0;
}
