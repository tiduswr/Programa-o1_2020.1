#include <stdio.h>
#include <locale.h>

int main(void){
	
	//Ativa acentos no prompt
	setlocale(LC_ALL, "Portuguese");
	
	//Declara as variaveis
	int senha, senhaaux, cont;
	senha = 0;
	
	//Solicita a senha ao usuario
	while(senha <= 0 || senha >= 100){
		printf("*****BRINCADEIRA DA SENHA*****\n\n\nJogador 1, digite sua senha entre 0 e 100: ");
		scanf("%d", &senha);
		system("cls");
	}
	
	//Jogador 2 tenta descobrir a senha
	for(cont = 1; cont <=5; cont++){
		
		//Cabeçalho do game
		if(cont > 1){
			printf("*****BRINCADEIRA DA SENHA*****\n\n");
		}
		
		//Solicita valor do Jogador 2
		printf("Chances Restantes: %d\n\nJogador 2, Descubra a senha entre 0 e 100 que foi\n digitada pelo Jogador 1: ", 6 - cont);
		scanf("%d", &senhaaux);
		
		//Verifica se ele acertou
		if(senha == senhaaux){
			////Limpa o Prompt
			system("cls");
			
			//Avisa que ele ganhou e encerra o programa
			printf("\n\n*********Você descobriu a senha!*********\n\n");
			return (0);
		}
		
		//Se chegou até aqui ele errou
		//Limpa o Prompt
		system("cls");
		printf("Senha incorreta, tente novamente!!\n\n");
		
		//Verifica a senha é maior ou maior
		if(senhaaux > senha){
			system("cls");
			printf("Sua senha é maior que a do jogador 1!!\n\n");
		}
		if(senhaaux < senha){
			system("cls");
			printf("Sua senha é menor que a do jogador 1!!\n\n");
		}
	}
	
	//Encerra o programa caso ele erre todas as senhas
	//Apaga prompt
	system("cls");
	printf("Você perdeu todas as chances, jogo encerrado!!");
	return(0);
}
