#include <stdio.h>

/* Enunciado - Faça um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada válida ou não.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos não
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

int main (int argc, char *argv[])
{
    int dia, mes, ano;
    printf("Digite a data(D/M/A): ");
    scanf("%i/%i/%i",&dia,&mes,&ano);
    if(mes <= 12 && dia <= 31 && mes >= 1 && dia >= 1 && ano >= 0){
        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12){
            printf("Data valida!");
        }
        else{
            if((mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia <= 30){
                if(mes != 2){
                    printf("Data valida!");
                }
                else{
                    if(mes == 2 && dia <=28 || mes == 2 && ano%4 ==0 && dia <= 29) printf("Data valida!");
                    else printf("Data invalida!");
                }
            }
            else printf("Data invalida!");

        }
    }
    else printf("Data invalida!");
    return 0;
}

