#include <stdio.h>

#define ARR_SIZE 10
#define L 2

void troca_elementos(int vetor[ARR_SIZE], int i, int j);
void bubble_sort(int vetor[L][ARR_SIZE], int tam_vetor);
int busca_binaria(int vetor[ARR_SIZE], int chave);
void le_vetor(int vetor[ARR_SIZE]);
void exibe_vetor(int vetor[ARR_SIZE]);

int main (int argc, char *argv[])
{
  int vet[L][ARR_SIZE], chave, b,i;
  le_vetor(vet[0]);
  for(i=0;i<ARR_SIZE;i++){
    vet[1][i] = i;
  }
  printf("\nValor a ser buscado: ");
  scanf("%i", &chave);
  exibe_vetor(vet[0]);
  bubble_sort(vet, ARR_SIZE);
  b = busca_binaria(vet[0], chave);
  if (b == -1) printf("\nChave %i não foi encontrada.", chave);
  else printf("\nChave %i foi encontrada na posição %i.", chave, vet[1][b]);
  return 0;
}


void troca_elementos(int vetor[ARR_SIZE], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void bubble_sort(int vetor[L][ARR_SIZE], int tam_vetor){
  int i,j;
    for(i=tam_vetor-1;i>0;i-=1){
      for(j=0;j<i;j++){
        if(vetor[0][j]>vetor[0][j+1]){
            troca_elementos(vetor[0], j, j+1);
            troca_elementos(vetor[1], j, j+1);
        } 
      }
    }
}

int busca_binaria(int vetor[ARR_SIZE], int chave) {
    int retorno = 11, ini=0, fim =ARR_SIZE, meio, i=0;
    while(i == 0){
        meio = (ini + fim)/2;
        if(vetor[meio] == chave){
            retorno = meio;
            i++;
        }
        if(vetor[meio] > chave) fim = meio -1;
        if(vetor[meio] < chave) ini = meio +1;
        if(fim < ini) i++;
    }
    if(retorno == 11) return -1;
    else return retorno;
}

void le_vetor(int vetor[ARR_SIZE]) {
    int i;
    printf("Digite os valores do vetor: ");
    for (i=0; i < ARR_SIZE; i++){
        scanf("%i", &vetor[i]);
    }    
}

void exibe_vetor(int vetor[ARR_SIZE]) {
  printf("[");
  for (int i = 0; i < ARR_SIZE; i++) {
    printf("%i", vetor[i]);
    if ( i < ARR_SIZE - 1 ) printf(", ");
  }
  printf("]\n");
}
