#include <stdio.h>

int main(void){

    //Saida par o Programa abaixo: X = 3 | y = 4 | p = 4

    int x, y, *p;

    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x--;
    (*p) += x;

    printf("X = %d | y = %d | p = %d\n",x,y,*p);

    return 0;
}