/* 
 * Enunciado: 
 * Implemente um programa que leia dois valores inteiros - a e b - e, a seguir
 * troque os seus valores utilizando a subrotina troca_valores. A subrotina 
 * deve receber dois ponteiros para inteiros e trocar os seus valores de lugar.
 *
 * Exemplos:
 * 
 * Digite os valores de (a, b): 2, 3
 * A = 2, B = 3
 * A = 3, B = 2
 *
 */

#include <stdio.h>

void troca_valores(int *a, int *b);

#define MAX 100

int main (int argc, char *argv[])
{
    int a,b;
    printf("Digite os valores de (a, b): ");
    scanf("%i, %i",&a,&b);
    printf("A = %i, B = %i\n",a,b);
    troca_valores(&a,&b);
    printf("A = %i, B = %i\n",a,b);
    return 0;
}

void troca_valores(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
