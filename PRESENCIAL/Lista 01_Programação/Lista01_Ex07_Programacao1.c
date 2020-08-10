#include <stdio.h>
#define taxa 2.50
#include <locale.h>

//Define um tipo de variavel data com valores dia, mes e ano inteiros
typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

 //Guarda os dias nos meses no caso de 0 ano normal e 1 para ano bissexto
int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

//Retorna 1 caso o ano seja bissexto e 0 caso contr�rio, essa fun�ao simplificada s� verifica se as 
//condi��es logicas s�o verdadeiras ou falsas e retorna o valor binario correspondente
int bissexto (int ano) {
	//Se o resto da divis�o do ano por quatro for igual a 0
	// e se tambem o resto da divis�o por 100 ou 400 for 0 ent�o o ano � bissexto
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

//Fun��o para calcular a distancia de dias, foi definida em unsigned long pois "dias" s�o sempre positivos
// e dependendo da distancia entre as datas, o numero de dias pode ser extremamente longo!
//O termo unsigned � usado para se obter apenas valores positivos em uma variavel, e por consequencia
//o numero de valores positivos que essa variavel pode guardar � dobrada
unsigned long dist_dias (Data inicio, Data fim) {
	//Define variaveis
	unsigned long idias, fdias;
	unsigned long dif_anos = 0;
	int i, dbissexto;

	//Come�a definindo o dia inicial como o dia digitado pelo usuario
	idias = inicio.dia;
	//Verifica se o ano � bissexto via fun�ao para buscar o registro na Array criada "dias_mes"
	dbissexto = bissexto (inicio.ano);
	//Esse for vai ficar somando os dias do mes anterior at� o i chegar em 0 para verificar quantos dias do ano se passaram
	for (i = inicio.mes - 1; i > 0; --i){
		idias += dias_mes[dbissexto][i];
	}
	
	//Esse codigo tem a mesma finalidae do anterior, que � verificar quantos dias do ano se passaram
	fdias = fim.dia;
	dbissexto = bissexto (fim.ano);
	for (i = fim.mes - 1; i > 0; --i){
		fdias += dias_mes[dbissexto][i];
	}
	
	//Esse loop verifica se o ano inicial � menor que o ano final, e adiciona a diferen�a em dias	
	while (inicio.ano < fim.ano){
		dif_anos += 365 + bissexto(inicio.ano);
		inicio.ano = inicio.ano + 1;
	}
	
	//Realiza a subtra��o
	return dif_anos - idias + fdias;
}

int main(void) {
	//Define variaveis
	Data dia_col, dia_dev;
	unsigned long dias_emprest;
	float val_pago;
	
	//Ativa acentos no terminal
	setlocale(LC_ALL, "Portuguese");
	
	//Solicita valores
	printf("=+=+=+=VERIFICAR MULTA POR ATRASO=+=+=+=\n\n");
	printf("Coloque a data de coleta do livro\nno formato: dia/mes/ano\n");
	
	//Algo interessante a acrescentar � que voc� pode com o scanf definir uma "mascara personalizada" para estocar os
	//dados do usuario em varias variaveis diferentes, aqui por exemplo adicionei o "/" para complementar uma mascara
	// de data personalizada!
	scanf("%d/%d/%d", &dia_col.dia, &dia_col.mes, &dia_col.ano);
	printf("Coloque a data de devolu�ao do livro\nno formato: dia/mes/ano\n");
	scanf("%d/%d/%d", &dia_dev.dia, &dia_dev.mes, &dia_dev.ano);
	
	// "%lu" � uma mascara para unsigned long que � o tipo de dado utilizado na fun��o dist_dias
	system("cls");
	
	//Verifica diferen�a de dias via fun��o
	dias_emprest = dist_dias (dia_col, dia_dev);
	printf("=+=+=+=VERIFICAR MULTA POR ATRASO=+=+=+=\n");
	printf("\nO livro ficou emprestado por %lu dias\n", dist_dias (dia_col, dia_dev));
	
	//Verifica se o Usuario ter� de pagar uma multa
	if(dias_emprest >= 15){
		val_pago = dias_emprest * taxa;
		printf("\nFoi superado 15 dias de emprestimo do livro\nser� necess�rio pagar uma multa!\n\nValor da multa: R$ %.2f", val_pago);
	}
	else{
		printf("\nNenhuma multa a ser paga!");
	}
	
	//encerra programa
	printf("\n\nPrograma encerrado!\n");
	return (0);
}
