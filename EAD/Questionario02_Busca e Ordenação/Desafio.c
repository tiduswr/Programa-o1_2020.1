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
    //O left come�a como -1 para regularizar o tamanho do vetor 
   int left = -1, right = lenVet;
   //Vai ficar rodando enquanto a posi��o de left, right e mid n�o forem iguais
   while (left < right-1) {  
       //Calcula o valor do meio do vetor
        int mid = (left + right)/2;
        //Verifica se o valor do meio � menor que a chave
        if (v[mid] < key){
            //Se for menor, ent�o a primeira posi��o se torna a do meio
            left = mid;
        }
        //Se n�o for menor, ent�o a posi��o do meio se torna a ultima
        else{
            right = mid;
        }  
   }
   //Quando left, mid e right s�o iguais, o la�o � quebrado e retorna a posi��o
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
    printf("**Procure um valor no Array Informado!!(Busca Bin�ria)\n\n");
    printf("Digite o valor para Buscar: ");
    scanf("%d", &verify);

    //Organiza vetor do maior para menor:
    BubbleSort(values, len);

    //Realiza Busca Binaria
    pos = buscaBinaria(verify, len, values);

    //Resultado
    printf("\n**Resultado: ");
    printf("O valor %d foi encontrado na posi��o %d ", verify, pos + 1);

    printf("\n");
    return 0;
}