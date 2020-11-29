#include <ctype.h>
#include <stdlib.h>

int main(void){

    int number = 1234;
    char number_str[5];

    itoa(number, number_str, 10);

    printf("%s", number_str);    

}