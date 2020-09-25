#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");

    /* ***********RESPOSTA DA QUEST�O**************
    a){
        Saida do programa: 25 2752296 2752296 25 50 2752292
    }
    b){
        1 - Ao printar o "a", � impresso o valor da variavel "a" que no caso � 25;
        2 - Ao printar "pa", � impresso o endere�o da variavel para o qual "pa" aponta, no caso "a";
        3 - Ao printar "&a", e impresso o endere�o da variavel "a";
        4 - Ao printar "*pa", � impresso o valor da variavel para qual "pa" aponta, que no caso � "a"
        5 - Ao printar "b", � impresso o valor da variavel b, que no caso � o valor ao qual "pa"
        aponta somado com "a", que tambem � a variavel que pa aponta. No caso seria equivalente a 2*(*pa);
        6 - Ao printar "&b", � impresso o endere�o da variavel b
    }
    */
   
    int a = 25; 
    int *pa = &a; 
    int b = *pa + a; 
    printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b); 

    printf("\n");
    return 0;
}