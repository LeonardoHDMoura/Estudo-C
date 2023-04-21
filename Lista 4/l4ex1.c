/* Enunciado: Desenvolva um programa capaz de ler n valores inteiros e os
 *  insira em um array. A leitura deve ser feita em uma única linha, separando 
 *  os valores por espaço. A leitura deve ser encerrada quando um 
 *  valor -100 é lido. Após a leitura ser realizada, o programa deve utilizar 
 *  o procedimento exibe_array para exibir o array em uma única linha 
 *  e entre colchetes.
 *
 *  Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *    [1, 2, 3, 4, 5, 6, 7, 8]
 *
 *    Digite os valores para o array: 1 2 3 4 -100
 *    [1, 2, 3, 4]
 *
 */

#include <stdio.h>

#define ARRAY_MAX 100 //Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_array(int array[], int tam_array);

int main (int argc, char *argv[])
{
    int vet[ARRAY_MAX];
    int i=0,j;

    printf("Digite os valores do array: ");
    while(vet[i] != -100){
        scanf("%i",&vet[i]);
        if(vet[i] != -100) i++;
        else break;
    }
    exibe_array(vet,i);
    return 0;
}
void exibe_array(int array[], int tam_array){
    int j;
    printf("[");
    for(j=0;j<tam_array-1;j++){
        printf("%i, ", array[j]);
    }
    printf("%i]",array[tam_array-1]);
}