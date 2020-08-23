#include <stdio.h>
#include <locale.h>
#define LEN 18

int buscaBinaria (int key, int lenVet, int v[]) {
    //O left começa como -1 para regularizar o tamanho do vetor 
   int left = -1, right = lenVet;
   //Vai ficar rodando enquanto a posição de left, right e mid não forem iguais
   while (left < right-1) {  
       //Calcula o valor do meio do vetor
        int mid = (left + right)/2;
        //Verifica se o valor do meio é maior que a chave
        if (v[mid] > key){
            //Se for maior, então a primeira posição se torna a do meio
            left = mid;
        }
        //Se não for maior, então a posição do meio se torna a ultima
        else{
            right = mid;
        }  
   }
   //Quando left, mid e right são iguais, o laço é quebrado e retorna a posição
   if(v[right] == key){
       return right;
   }
   else{
       return -1;
   }
}


int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int pos;
    int verify[] = {33, 50, 77, 90, 99};
    int DefaultValues[] = {99, 95, 89, 84, 77, 72, 69, 68, 57, 53, 49, 41, 37, 33, 31, 27, 16, 10};
    
    //Imprime vetores
    printf("Valores para Verificar:\n\n");
    for(int i = 0; i < sizeof(verify)/sizeof(int); i++){
        printf("%d ", verify[i]);  
    }
    printf("\n\nVetor de Busca:\n\n");
    for(int i = 0; i < sizeof(DefaultValues)/sizeof(int); i++){
        printf("%d ", DefaultValues[i]);  
    }
    //Printa uma linha de separação
    printf("\n\n");
    for(int i = 0; i < 70; i++){
        printf("-");
    }
    //Faz Busca
    printf("\n\n**Relação de valores encontrados: \n\n");
    for(int i = 0; i < LEN; i++){
        pos = buscaBinaria(verify[i], LEN, DefaultValues);
        if(pos != -1){
            printf("%d - Posição nº %d\n", DefaultValues[pos], pos+1);
        }
    }

    printf("\n");
    return 0;
}