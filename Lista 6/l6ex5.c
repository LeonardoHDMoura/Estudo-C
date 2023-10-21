/* 
 * Enunciado: 
 * Crie um programa capaz de ler os valores(float) de x e y de uma 
 * estrutura Ponto. A seguir, o programa deve calcular e exibir a distância 
 * entre esses dois pontos.
 * 
 * Exemplos: 
 *
 *   Digite um ponto (x, y): 0, 1
 *   Digite um ponto (x, y): 0, 0
 *   Distancia: 1.00
 *   
 *   Digite um ponto (x, y): 5, 7
 *   Digite um ponto (x, y): 10, 3
 *   Distancia: 6.40
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;

} Ponto;

int main (int argc, char *argv[])
{
    Ponto a, b;
    float dist;
    printf("Digite um ponto (x, y): ");
    scanf("%f, %f",&a.x,&a.y);
    printf("Digite um ponto (x, y): ");
    scanf("%f, %f",&b.x,&b.y);
    dist = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    printf("Distancia: %.2f", dist);
    return 0;
}
