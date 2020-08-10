//Importa bibliotecas
#include <stdio.h>
#include <locale.h>

float med_pond(float nota1, float nota2, int peso1, int peso2){
	
	//Declara variavel
	float soma_media;
	 
	//Realiza a soma
	soma_media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
	
	//Retorna valor da função
	return soma_media;
	
}

int main(void) {

//Declara variaveis
float p1, p2;
float n1, n2, mediaP;
long id_mat;

//Ativa acentuação
setlocale(LC_ALL, "Portuguese");

//Solicita valores para os pesos das provas
printf("***** PESO DAS PROVAS *****");
printf("\nDigite o peso da primeira prova: ");
scanf("%f", &p1);

printf("Digite o peso da segunda prova: ");
scanf("%f", &p2);

//Solicita os dados do aluno
printf("\n***** DADOS DO ALUNO *****");
printf("\nInsira sua matricula: ");
scanf("%d", &id_mat);


//Solicita notas do aluno
printf("Digite a nota da sua primeira prova: ");
scanf("%f", &n1);

printf("Digite a nota da sua segunda prova: ");	
scanf("%f", &n2);

//Verifica a média ponderada
mediaP = med_pond(n1, n2, p1, p2);

//Exibe a media para o Usuario
printf("\n*****Resultado*****\nMatricula: %d | Média Ponderada: %.2f", id_mat, mediaP);

	return (0);
}

