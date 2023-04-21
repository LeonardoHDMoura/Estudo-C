#include <stdio.h>

/* Enunciado - Em matemática, o número harmônico designado por H(n) define-se
 * como sendo a soma da série harmônica:
 * 
 *                         H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
 *
 * Faça um programa que leia um valor n inteiro e positivo e 
 * apresente o valor de H(n) com duas casas decimais
 *
 * Exemplos:
 *
 * Digite um valor para n: 10
 * 2.93
 *
 * Digite um valor para n: -1
 * Erro, n menor que 0!
 */

int main (int argc, char *argv[])
{
    float n, H, c;
    printf("Digite um valor para n: ");
    scanf("%f",&n);
    if(n>0){
        H = 0;
        for(c=1; c<=n; c++){
            H = H + 1/c;
        }
        printf("%.2f", H);
    }
    else printf("Erro, n menor que 0!");
    return 0;
}
