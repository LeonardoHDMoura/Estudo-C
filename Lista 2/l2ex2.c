#include <stdio.h>

/* Enunciado - Faça um programa que receba um número inteiro digitado pelo
 * usuário e retorna se o número é par ou ímpar.
 *
 * Exemplos:
 *
 * Digite um numero: 5
 * Impar
 *
 * Digite um numero: 4
 * Par
 */

int main (int argc, char *argv[])
{
    int a;
    printf("Digite um numero: ");
    scanf("%i",&a);
    if(a%2 == 0) printf("\nPar");
    else printf("\nImpar");
    return 0;
}

