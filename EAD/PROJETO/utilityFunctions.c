#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

//*************** FUNÇÕES UTILITARIAS

char * maiuscula(char str[]){
        int i = 0;
        int tamStr = strlen(str);
        char *aux = malloc(sizeof(char)*tamStr);

        while(str[i] != '\0'){
            aux[i] = toupper(str[i]);
            if(str[i+1] == '\0'){
                aux[i+1] = '\0';
            }
            i++;
        }
        return aux;
}

void ClearBuffer(){
    setbuf(stdin, NULL);
}

void pauseEXE(char message[]){
    printf("%s... ", message);
    ClearBuffer();
    getchar();
}

void clearWindowsTerminal(){
    printf("\n\n!!!! NÃO FOI POSIVEL LIMPAR O TERMINAL !!!!\n\n");
    system("cls");
}

void removeBrkLn(char str[]){
    int lenStr = strlen(str);
    for(int i = 0; i < lenStr; i++){
        if( str[i] == '\n' ){
            str[i] = '\0';
        }
    }
}

void strUserInput(char *str, int len){
    ClearBuffer();
    fgets(str, len, stdin);
    removeBrkLn(str);
    ClearBuffer();
}

int intlen(int value){
    int i = 1, de = 0, tam = 0, cond = 1, ate = 0;
    while(cond == 1){
        ate = pow(10, i);
        if(value > de && value < ate){
            tam++;
        }
        else{
            if(value < ate){
                cond = 0;
            }
            else{
                tam++;
            }
        }
        de = ate - 1;
        i++;
    }
    return tam;
}

void printEspacos(int qtd){
    for(int i = 1; i <= qtd; i++){
        printf(" ");
    }
}

int charUsed(char value[]){
    int i = 0;
    while(value[i] != '\0'){
        i++;
    }
    return i;
}

char * int_to_str(int value){
    int tam_str = intlen(value)+1;
    char * str = (char *) malloc(sizeof(char) * tam_str);
    sprintf(str,"%d", value);
    str[tam_str] = '\0';
    return str;
}

void swapStr(char* a, char* b, int sizeStrings){
    char temp[sizeStrings];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int userIptCtrl(char *str, char *keys){
    if((unsigned int) charUsed(keys) > 0){
        int i = 0, j = 0, match = 0, lenStr = charUsed(str);
        while(str[i] != '\0'){
            while(keys[j] != '\0'){
                if(toupper(str[i]) == toupper(keys[j])){
                    match++;
                }
                j++;
            }
            i++;
            j=0;
        }
        i=0;
        if(lenStr == match){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

//*********************FUNÇÕES PARA TRATAMENTO DE DATA

char *format(int number){
   char *retorno,
      ret[5];

   if (number < 10){
      sprintf(ret,"0%d",number);
      retorno = ret;
      return retorno;
   }
   else{
      sprintf(ret,"%d",number);
      retorno = ret;
      return retorno;
   }
}

char * dataAtual(void){
    int dia,mes,ano;
    char var1[20],
      var2[20],
      var3[20],
      var4[20],
      *dataPtr;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano = local -> tm_year + 1900;

   sprintf(var1,"%s",format(dia));
   sprintf(var2,"%s",format(mes));
   sprintf(var3,"%s",format(ano));

   sprintf(var4,"%s/%s/%s",var1,var2,var3);
   var4[11] = '\0';

   dataPtr = var4;
   return dataPtr;
}

 //Dias do Calendário: 0 ano normal e 1 para ano bissexto
int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

char ** splitStr(char *str, const char *key){
    char **texto = NULL;
    int i = 0;
    //strdup faz uma copia da string inserindo '\0' no final
    for(char * sub = strtok(str, key); sub != NULL; sub = strtok(NULL, key)){
        texto = (char **) realloc(texto, sizeof(char *) * (i + 1));
        texto[i] = sub;
        i++;
    }
    texto = (char **) realloc(texto, sizeof(char *) * (i + 1));
    texto[i] = NULL;
    return texto;
}

Data * str_to_data(char *str, const char *key){
    Data * x = (Data *) malloc(sizeof(Data));
    char * temp = (char *) malloc(sizeof(char) * 20);
    strcpy(temp, str);
    char **texto = splitStr(temp, key);
    int i = 0;

    x->ano = atoi(texto[2]);
    x->dia = atoi(texto[0]);
    x->mes = atoi(texto[1]);
    while(texto[i] != NULL){
        free(texto[i]);
        i++;
    }
    free(temp);
    free(texto);
    return x;
}

int bissexto (int ano){
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

unsigned long dist_dias (Data *inicio, Data *fim) {
	unsigned long idias, fdias;
	unsigned long dif_anos = 0;
	int i, dbissexto;

	//Começa definindo o dia inicial como o dia digitado pelo usuario
	idias = inicio->dia;
	//Verifica se o ano é bissexto via funçao para buscar o registro na Array criada "dias_mes"
	dbissexto = bissexto (inicio->ano);
	//Esse for vai ficar somando os dias do mes anterior até o i chegar em 0 para verificar quantos dias do ano se passaram
	for (i = inicio->mes - 1; i > 0; --i){
		idias += dias_mes[dbissexto][i];
	}

	//Esse codigo tem a mesma finalidae do anterior, que é verificar quantos dias do ano se passaram
	fdias = fim->dia;
	dbissexto = bissexto (fim->ano);
	for (i = fim->mes - 1; i > 0; --i){
		fdias += dias_mes[dbissexto][i];
	}

	//Esse loop verifica se o ano inicial é menor que o ano final, e adiciona a diferença em dias
	while (inicio->ano < fim->ano){
		dif_anos += 365 + bissexto(inicio->ano);
		inicio->ano = inicio->ano + 1;
	}

	//Realiza a subtração
	return dif_anos - idias + fdias;
}

int dataValida(Data *analise){
    if(analise != NULL){
        int bsxt = bissexto(analise->ano);
        if(analise->mes >= 1 && analise->mes <= 12){
            if(analise->dia >= 1 && analise->dia <= dias_mes[bsxt][analise->mes]){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    return 0;
}

//***********************FUNÇÕES PARA TRATAMENTO DE ARQUIVOS EM GERAL

int fsavedata(void *Dados, size_t lenDados,char *nomeArq){
    FILE * arq = NULL;

    arq = fopen(nomeArq, "ab");

    if(!arq){
        fclose(arq);
        return 0;
    }
    else{
        //Indo para o final do arquivo
        fseek(arq, (long) 0, SEEK_END);
        fwrite(Dados, lenDados, 1, arq);
        fclose(arq);
        return 1;
    }
}

long flen(FILE *arquivo) {
    //Ftell() etorna o valor atual do indicador de posição do fluxo
    long posicaoAtual = ftell(arquivo);
    long tamanho;


    fseek(arquivo, (long) 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, posicaoAtual, SEEK_SET);
    return tamanho;
}


int fCriaBD(char *nomeArq){
    FILE * arq = fopen(nomeArq, "ab");
    if(!arq){
        fclose(arq);
        return 0;
    }
    fclose(arq);
    return 1;
}

int fexiste(char * nomearq){
    FILE * arq = NULL;
    arq = fopen(nomearq, "rb");
    if(!arq){
        fclose(arq);
        return 0;
    }
    else{
        fclose(arq);
        return 1;
    }
}
void replaceChar(char *value, char *keys){
    int tamKeys = charUsed(keys);
    int tamValue = charUsed(value);
    int match = 0;

    if(tamKeys > 0 && tamValue > 0){
        for(int i = 0; i < tamKeys; i++){
            for(int j = 0; j < tamValue; j++){
                if(value[j] == keys[i]){
                    match++;
                    for(int k = j; k < tamValue - 1; k++){
                        value[k] = value[k + 1];
                    }
                    value[tamValue - match] = '\0';
                }
            }
        }
    }
    free(keys);
}

int ValidaCPF(char *value){
    int tamStr = charUsed(value);
    char *temp = (char *) malloc(sizeof(char) * tamStr);
    strcpy(temp, value);

    replaceChar(temp, "'!@#$%¨&*+=`´^~:;><.,/|?°-");
    if(charUsed(temp) == 11){
        if(userIptCtrl(temp, "0123456789")){
            free(temp);
            return 1;
        }
        else{
            free(temp);
            return 0;
        }
    }
    else{
        free(temp);
        return 0;
    }
}
void FormataCPF(char *value, char *retorno){
    if(ValidaCPF(value)){
        int tamValue = charUsed(value) + 1;
        char input[tamValue];
        strcpy(input, value);
        input[tamValue-1] = '\0';
        int j = 0;

        replaceChar(input, "'!@#$%¨&*+=`´^~:;><.,/|?°-");
        for(int i = 0; i < 16; i++){
            if(i != 14){
                if(i == 3 || i == 7 || i == 11){
                    if(i == 11){
                        retorno[i] = '-';
                    }
                    else{
                        retorno[i] = '.';
                    }
                }
                else{
                    retorno[i] = input[j];
                    j++;
                }
            }
            else{
                retorno[i] = '\0';
            }
        }
    }
}
