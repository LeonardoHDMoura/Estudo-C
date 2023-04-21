#include <stdio.h>

/* Enunciado - Faça um programa que calcula a associação em paralelo 
 * de dois resistores R1 e R2 fornecidos pelo usuário via teclado. 
 * O programa deverá solicitar valores e calcula a resistência equivalente até 
 * que o usuário entre com um valor para alguma das resistências igual a 0
 *
 * Exemplos:
 *
 * Digite um valor para R1: 470
 * Digite um valor para R2: 2200
 * 
 *
 * Digite um valor para R1: 0
 * Digite um valor para R2: 100
 * Finalizando o programa!
 */

int main (int argc, char *argv[])
{
    float R1, R2, P;
    R1 = 1;
    R2 = 1;
    while(R1 > 0 && R2 > 0){
        printf("Digite um valor para R1: ");
        scanf("%f",&R1);
        printf("Digite um valor para R2: ");
        scanf("%f",&R2);
        if (R1 == 0 || R2 == 0){
            printf("Finalizando o programa!");
            break;
        }
        P = (R1*R2)/(R1+R2);
        printf("P: %.2f\n", P);
    }
    return 0;
}
