/* Enunciado:
 *  Desenvolva um programa capaz de ler dois vetores com três elementos
 *  inteiros cada. A leitura deve ser feita em uma única linha para cada vetor,
 *  com os elementos separados por espaços. Após a leitura, o programa
 *  deve exibir o produto escalar entre os vetores digitados no formato
 *  exemplificado abaixo. O cálculo do produto escalar deve obrigatoriamente
 *  ser feito pela função produto_escalar, que recebe como referência os
 *  dois arrays e retorna um valor inteiro referente ao resultado do produto
 *  escalar.
 *
 *  Exemplos:
 *      Digite o primeiro array: 1 2 3
 *      Digite o segundo array: 3 2 1
 *      [1, 2, 3] . [3, 2, 1] = 10
 *      
 *      Digite o primeiro array: 10 20 30
 *      Digite o segundo array: -10 2 5
 *      [10, 20, 30] . [-10, 2, 5] = 90
 *
 */

#include <stdio.h>
#include <math.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int produto_escalar(int array[], int array2[]);

void LerArray(int vet[]);
void ExibirArray(int vet[]);
int main (int argc, char *argv[])
{
    int array1[ARRAY_MAX], array2[ARRAY_MAX],esc;
    LerArray(array1);
    LerArray(array2);
    printf("\n");
    ExibirArray(array1);
    printf(" . ");
    ExibirArray(array2);
    esc = produto_escalar(array1,array2);
    printf(" = %i",esc);
    return 0;
}

int produto_escalar(int array[], int array2[]) {
    int a, b, c;
    a = array[0] * array2[0];
    b = array[1] * array2[1];
    c = array[2] * array2[2];
    return a+b+c;
}

void LerArray(int vet[]){
    int i;
    printf("Digite os valores do array: ");
    for(i=0;i<3;i++){
        scanf("%i",&vet[i]);
    }
}
void ExibirArray(int vet[]){
    int j;
    printf("[");
    for(j=0;j<2;j++){
        printf("%i, ", vet[j]);
    }
    printf("%i]",vet[2]);
}