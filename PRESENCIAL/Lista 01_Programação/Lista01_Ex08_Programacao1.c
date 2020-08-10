#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include<stdbool.h>

int main(void){
	
	//Verifica se deve continuar
	bool continuar;
	int opcao;
	continuar = true;
	while(continuar = true){
	
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
				
				//Avisa que ele ganhou e encerra o jogo
				printf("\n\n*********Você descobriu a senha!*********\n\n");
				//Linha de codigi para ir para uma linha especificada do programa
				goto tentar;
			}
			
			//Se chegou até aqui ele errou
			//Limpa o Prompt
			system("cls");
			printf("Senha incorreta, tente novamente!!\n\n");
			
			//Verifica a senha esta proxima
			if(senhaaux == senha - 1 || senhaaux == senha + 1){
				system("cls");
				printf("TÁ QUENTE!!\n\n\n");
			}
		}
		//Encerra o programa caso ele erre todas as senhas
		//Apaga prompt
		system("cls");
		printf("Você perdeu todas as chances, jogo encerrado!!\n\nDeseja tentar novamente?");
		
		//Atalho do goto
		tentar:
		opcao = 2;
		//Verifica se deseja continuar
		while(opcao < 0 || opcao > 1){
			printf("Digite 1 para continuar e 0 para sair\n");
			scanf("%d", &opcao);
		}
		
		//Verifica opções
		if(opcao == 1){
			continuar = true;
			system("cls");
		}
		if(opcao == 0){
			continuar = false;
			system("cls");
			printf("Jogo encerrado!");
			return(0);
		}
	}
	return (0);
}
