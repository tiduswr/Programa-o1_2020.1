#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

char * maiuscula(char str[], int tamStr){
        int i = 0;
        char *aux;
        aux = malloc(sizeof(char)*tamStr);
        while(str[i] != '\0'){
            aux[i] = toupper(str[i]);
            if(str[i+1] == '\0'){
                aux[i+1] = '\0';
            }
            i++;
        }
        return aux;
}

int main(void){

    char arg1[] = "abc";
    char arg2[] = "def";


    printf("%d",memcmp(arg2,arg1,3));


    printf("%s", maiuscula(arg2, 7));
}