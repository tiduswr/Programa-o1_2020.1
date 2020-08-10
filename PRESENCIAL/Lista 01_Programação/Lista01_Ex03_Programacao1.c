#include <stdio.h>
#include <locale.h>

float opera_choose(int opera, float val1, float val2){
	//Declara variaveis
	float resp;
	
	//Verifica a operação
	if(opera == 1){
		resp = val1 + val2;
	}
	if(opera == 2){
		resp = val1 - val2;
	}
	if(opera == 3){
		resp = val1 * val2;
	}
	if(opera == 4){
		resp = val1 / val2;
	}
}

//Programa principal
int main(void){
	//Declara variaveis
	int opera;
	float val1, val2, resp;
	
	opera = 0;
	
	//Ativa acentos no prompt
	setlocale(LC_ALL, "Portuguese");
	
	//Solicita valores
	printf("***REALIZE OPERAÇÕES ENTRE DOIS VALORES***");
	printf("\n1.Adição\n2.Subtração\n3.Multiplcação\n4.Divisão\n\n");
	
	//Laço para forçar um valor inteiro determinado
	while(opera < 1 || opera >4){
		printf("Digite o numero associado a uma das\noperações acima: ");
		scanf("%d", &opera);
	}
	
	//Solicita valores
	printf("Digite o primeiro valor: ");
	scanf("%f", &val1);
	printf("Digite o segundo valor: ");
	scanf("%f", &val2);
	
	//Realiza a operação
	resp = opera_choose(opera, val1, val2);
	printf("\nResposta: %.2f", resp);
	
	return(0);
	
}
