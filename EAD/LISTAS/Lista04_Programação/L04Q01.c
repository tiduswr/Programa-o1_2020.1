#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MUS 11

int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    //Define variaveis
    int qtdMus = MUS, aux = 0, j = 0, continua = 1, track;
    char musicas[qtdMus - 1][50]; 
    char delimitador = ';';
    /*Para o split funcionar, tenha certeza de que a variavel tenha a soma do numero de caracteres para verificar
    +1, pois o /0 entra na contagem*/
    char bd_mus[93];

    //Guarda as musicas em um array(Não verifica se a variavel estoura!!)
    strcpy(bd_mus, "PROXYCITY;P.Y.N.G.;DNSUEY;SERVERS;HOST;CRIPTONIZE;OFFLINE DAY;SALT;ANSWER;RAR?;WIFI ANTENNAS");
    //Teste de algoritmo para dar split em uma string
    for(int i = 0; i < qtdMus; i++){
        while(continua == 1){
            if(bd_mus[j] != delimitador && bd_mus[j] != '\0'){
                musicas[i][aux] = bd_mus[j];
                aux++;
                j++;
            }
            else{
                musicas[i][aux] = '\0';
                continua = 0;
                j++;
            }
        }
        if(i != qtdMus - 1){
            continua = 1;
            aux = 0;
        }
    }

    printf("**Escolha uma Musica(Por meio da Soma de dois Numeros):\n\n*Digite dois numeros para escolher a musica:\n\n");
    scanf("%d", &aux);
    track = track + aux;
    scanf("%d", &track);
    track = track + aux;
    printf("\n*Faixa escolhida:\n\n");

    //Imprime musica escolhida
    if(track <= 10 && track >= 0){
        printf("%d - %s", track, musicas[track]);
    }
    else{
        printf("Faixa Não Encontrada!!!");
    }    
    printf("\n");
    return 0;
}