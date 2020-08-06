#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

//Functions
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

//Main
int main(void){
	//Não foi solicitado tratamento de erros para o Usuario!
	int		n;
	int		i;
	setlocale(LC_ALL, "Portuguese");
	
	printf("VERIFICADOR DE NUMEROS PRIMOS MENORES QUE ""N""");
	printf("\n\nDigite um numero a ser verificado: ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++){
		if(isPrime(i)){
			printf("\n%d é Primo!",i);
		}
	}
}
