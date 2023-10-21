/* 
 * Enunciado: 
 * Crie um programa capaz de ler 4 estruturas Retângulo
 * (leitura de 2 em 2 pontos) que devem ser armazenados em um array.
 * A seguir, o programa deve exibir o array de retângulos, ordenando-os por
 * área. Utilize o algoritmo de ordenação que preferir.
 * 
 * Exemplos: 
 *
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,2,2
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1,1 
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,3,3
 *   Digite os valores do retângulo (x1, y1, x2, y2): 0,0,1.5,1.5
 *   [Ret{Ponto{0.00, 0.00},Ponto{1.00, 1.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{1.50, 1.50}},
 *   Ret{Ponto{0.00, 0.00},Ponto{2.00, 2.00}},
 *   Ret{Ponto{0.00, 0.00},Ponto{3.00, 3.00}}]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 4

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto infesq;
    Ponto supdir;
} Ret;

float calcula_area(Ret r);
void bubble_sort(float vetor[N], int tam_vetor, Ret R[N]);
void troca_elementos(float vetor[N], int i, int j);
void exibe_retangulos(Ret R[N], int i);
void troca_retangulo(Ret R[N], int i, int j);

int main (int argc, char *argv[])
{
    Ret Rets[N];
    float areas[N];
    int i;

    for(i=0; i<N; i++){
    printf("Digite os valores do retangulo (x1, y1, x2, y2): ");
    scanf("%f, %f, %f, %f", &Rets[i].infesq.x, &Rets[i].infesq.y, &Rets[i].supdir.x, &Rets[i].supdir.y);
    areas[i] = calcula_area(Rets[i]);
    }
    bubble_sort(areas, N, Rets);
    exibe_retangulos(Rets,N-1);
    return 0;
}

float calcula_area(Ret r){
    return fabs(r.supdir.x - r.infesq.x) * fabs(r.supdir.y - r.infesq.y);
}
void bubble_sort(float vetor[N], int tam_vetor, Ret R[N]) {
    int i,j;
    for(i=tam_vetor-1;i>0;i-=1){
        for(j=0;j<i;j++){
            if(vetor[j]>vetor[j+1]){
                troca_elementos(vetor, j, j+1);
                troca_retangulo(R, j, j+1);
        }
    }
}
}
void troca_elementos(float vetor[N], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}
void troca_retangulo(Ret R[N], int i, int j){
    Ret aux;
    aux = R[i];
    R[i] = R[j];
    R[j] = aux;
}

void exibe_retangulos(Ret R[N], int i){
    int j;
    printf("[");
    for(j=0;j<i;j++){
        printf("Ret{Ponto{%.2f, %.2f},Ponto{%.2f, %.2f}}",R[j].infesq.x,R[j].infesq.y,R[j].supdir.x,R[j].supdir.y);
        printf(", ");
    }
    printf("Ret{Ponto{%.2f, %.2f},Ponto{%.2f, %.2f}}",R[i].infesq.x,R[i].infesq.y,R[i].supdir.x,R[i].supdir.y);
    printf("]");
}