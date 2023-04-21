#include <stdio.h>

/* Enunciado - Faça um programa que leia duas notas de um aluno em uma
 * única linha, separando cada valor com uma vírgula. Verifique se as notas
 * são válidas e, caso sejam exiba a média do aluno na tela. Para que a nota 
 * seja válida, ela deve estar entre 0.0 e 10.0. Caso alguma das notas não seja
 * válida, o programa deve informar o usuário e encerrar sua operação.
 *
 * Exemplos:
 *
 * Notas: 5.0, 10.0
 * 7.5
 *
 * Notas: 5, 5.0
 * 5.0
 *
 * Notas: -1.0, 5.0
 * Nota invalida. Deve ser entre 0.0 e 10.0
 */

int main (int argc, char *argv[])
{
    float Nota1, Nota2, Media;
    printf("Notas: ");
    scanf("%f, %f", &Nota1,&Nota2);
    if(Nota1 >= 0 && Nota1 <= 10 && Nota2 >= 0 && Nota2 <=10){
        Media = (Nota1 + Nota2) / 2;
        printf("%.1f",Media);
    }
    else{
        printf("Nota invalida. Deve ser entre 0.0 e 10.0");
    }
    return 0;
}

