/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um 
 * array. A leitura deve ser feita de acordo com o programa feito no ex1. 
 * Após a leitura, desenvolva a função calcula_media e calcula_dvp 
 * para calcular a média e o desvio padrão dos valores informados. 
 * O programa principal deve receber os valores lidos pelo array e retornar a 
 * média e o desvio padrão no seguinte formato: MÉDIA +- DVP
 *
 * Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 -100
 *    4.00 +- 1.7
 *
 *    Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 *    1.00 +- 0.0
 *
 *    Digite os valores para o array: 10 20 1 40 50 90 100 -100
 *    44.43 +- 29.8
 *
 */

#include <stdio.h>
#include <math.h> // A biblioteca math tem pow e sqrt

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
float calcula_media(int array[], int tam_array);
float calcula_dvp(int array[], int tam_array);


int main (int argc, char *argv[])
{
    int i=0, vet[ARRAY_MAX];
    float mediaf,dvp;

    printf("Digite os valores do array: ");
    while(vet[i] != -100){
        scanf("%i",&vet[i]);
        if(vet[i] != -100) i++;
        else break;
    }
    mediaf = calcula_media(vet, i);
    dvp = calcula_dvp(vet, i);
    printf("%.2f +- %.2f", mediaf, dvp);
    return 0;
}

float calcula_media(int array[], int tam_array) {
    int j;
    float media=0;
    for(j=0;j<tam_array;j++){
        media = media + array[j];
    }
    return media/tam_array;
}

float calcula_dvp(int array[], int tam_array) {
    float i,soma=0,media;
    int j;
    media = calcula_media(array, tam_array);
    for(j=0;j<tam_array;j++){
        soma = soma + pow(array[j] - media, 2);
    }
    return sqrt(soma/tam_array);
}
