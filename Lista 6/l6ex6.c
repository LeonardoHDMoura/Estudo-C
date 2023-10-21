/* 
 * Enunciado: 
 * Crie um programa capaz de ler dois pontos que compõe uma estrutura de um 
 * Retângulo. Os dois pontos correspondem aos vértices inferior esquerdo e 
 * superior direito. Após a leitura do Retângulo, deve ser lido um terceiro 
 * ponto. O programa, então, exibirá se o ponto digitado pertence ao retângulo.
 * 
 * Exemplos: 
 *
 *   Digite um ponto (x, y): 0, 0
 *   Digite um ponto (x, y): 4, 4
 *   Digite um ponto (x, y): 2, 1
 *   O ponto digitado faz parte do Retângulo
 *
 *   Digite um ponto (x, y): 0, 0 
 *   Digite um ponto (x, y): 3, 4
 *   Digite um ponto (x, y): 5, 7
 *   O ponto digitado não pertence ao Retângulo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto infesq;
    Ponto supdir;
} Ret;

int main (int argc, char *argv[])
{
    Ponto a;
    Ret r;
    int i,j;
    printf("Digite um ponto (x, y): ");
    scanf("%f, %f",&r.infesq.x,&r.infesq.y);
    printf("Digite um ponto (x, y): ");
    scanf("%f, %f",&r.supdir.x,&r.supdir.y);
    printf("Digite um ponto (x, y): ");
    scanf("%f, %f",&a.x,&a.y);
    if(a.y >= r.infesq.y && a.y <= r.supdir.y){
        if(a.x >= r.infesq.x && a.x <= r.supdir.x) printf("O ponto digitado faz parte do Retângulo.");
        else printf("O ponto digitado não pertence ao Retângulo");
    }
    else printf("O ponto digitado não pertence ao Retângulo");
    return 0;
}
