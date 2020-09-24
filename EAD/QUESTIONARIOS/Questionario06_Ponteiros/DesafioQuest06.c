#include <stdio.h>

int main(void){

    int x=2, y=8, *p=&x, *q=&y;

    printf("Endereco de X = %p | Valor de X = %d\n",&x,x);
    printf("Endereco de P = %p | Valor de P = %d\n",&p,*p);
    printf("Endereco de Y = %p | Valor de Y = %d\n",&y,y);
    printf("Endereco de Q = %p | Valor de Q = %d\n",&q,*q);
    printf("Endereco de P = %p | Endereco de Q = %p\n",&p,&q);
    return 0;
}