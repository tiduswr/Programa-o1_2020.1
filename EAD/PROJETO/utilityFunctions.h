#ifndef UTILITYFUNCTIONS_H
	#define UTILITYFUNCTIONS_H
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

	char * maiuscula(char str[]);
	void ClearBuffer();
	void pauseEXE(char message[]);
	void clearWindowsTerminal();
	void removeBrkLn(char str[]);
	void strUserInput(char *str, int len);
	int intlen(int value);
	void printEspacos(int qtd);
	int charUsed(char value[]);
	char * int_to_str(int value);
	void swapStr(char* a, char* b, int sizeStrings);
	int userIptCtrl(char *str, char *keys);
	char *format(int number);
	char * dataAtual(void);
	char ** splitStr(char *str, const char *key);
	Data * str_to_data(char *str, const char *key);
	int bissexto (int ano);
	unsigned long dist_dias (Data *inicio, Data *fim);
	int dataValida(Data *analise);
	int fsavedata(void *Dados, size_t lenDados,char *nomeArq);
	long flen(FILE *arquivo);
	int fCriaBD(char *nomeArq);
	int fexiste(char * nomearq);
	void replaceChar(char *value, char *keys);
	int ValidaCPF(char *value);
	void FormataCPF(char *value, char *retorno);

#endif
