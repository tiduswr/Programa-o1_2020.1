#include <stdlib.h>
#include <locale.h>
#define len 10

int BubbleSort(int arr[], int lenVetor){
    int temp;
    for(int i = 0; i < lenVetor; i++){
        for(int j = 0; j < lenVetor; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}

int buscaBinaria (int key, int lenVet, int v[]) {
    //O left começa como -1 para regularizar o tamanho do vetor 
   int left = -1, right = lenVet;
   //Vai ficar rodando enquanto a posição de left, right e mid não forem iguais
   while (left < right-1) {  
       //Calcula o valor do meio do vetor
        int mid = (left + right)/2;
        //Verifica se o valor do meio é menor que a chave
        if (v[mid] < key){
            //Se for menor, então a primeira posição se torna a do meio
            left = mid;
        }
        //Se não for menor, então a posição do meio se torna a ultima
        else{
            right = mid;
        }  
   }
   //Quando left, mid e right são iguais, o laço é quebrado e retorna a posição
   return right;
}
int main(void){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int values[len], verify, pos;

    printf("**Insira 10 Valores: \n\n");
    for(int i = 0; i < len; i++){
        printf("Valor[%d]: ", i + 1);
        scanf("%d", &values[i]);
    }
    system("cls");
    printf("**Procure um valor no Array Informado!!(Busca Binária)\n\n");
    printf("Digite o valor para Buscar: ");
    scanf("%d", &verify);

    //Organiza vetor do maior para menor:
    BubbleSort(values, len);

    //Realiza Busca Binaria
    pos = buscaBinaria(verify, len, values);

    //Resultado
    printf("\n**Resultado: ");
    printf("O valor %d foi encontrado na posição %d ", verify, pos + 1);

    printf("\n");
    return 0;
}