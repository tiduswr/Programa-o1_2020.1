#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL,"portuguese");
    FILE *file;
    char leitor[100];
    
    /*É possivel redirecionar a entrada padrão do sistema, que nesse caso é o teclado
    para um arquivo, fazendo com que o fgets pegue todo o valor do arquivo e jogue em uma variavel*/
    setbuf(stdin, NULL);
    file = freopen("string.txt", "r", stdin); //Esse codigo faz um ponteiro(arg 3) apontar para outro diretorio
    setbuf(stdin, NULL);
    fgets(leitor, 100, stdin);
    printf("%s", leitor);

    fclose(file);
    return 0;
}