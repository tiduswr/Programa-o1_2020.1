
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * NOTE: unsafe (and leaky) implementation using strtok
 *
 * *into must point to a memory space where tokens can be stored
 * or if *into is NULL then it allocates enough space.
 * Returns:
 *  allocated array of items that you must free yourself
 *
 */


char **__split(char *src, const char *delim)
{
    size_t idx = 0;
    char *next;
    char **dest = NULL;


    do {
        dest = realloc(dest, (idx + 1)* sizeof(char *));
        next = strtok(idx > 0 ? NULL:strdup(src), delim);
        dest[idx++] = next;
    } while(next);


    return dest; 
}


int main() {
    int x = 0;
    char **here = NULL;
    here = __split("30/11/2020", "/");

    while(here[x]) {
        printf("here: %s\n", here[x]);
        x++;
    }
    return 0;
}