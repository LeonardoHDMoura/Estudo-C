#include <stdio.h>
#include <stdlib.h>

//Não modifique esse valor!!
#define MAX_ARR 1024 

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// troca_elementos deve receber um vetor e dois índices e trocar os troca 
// os elementos do vetor de lugar.
void troca_elementos(int vetor[MAX_ARR], int i, int j);

// particiona deve receber um vetor, o começo e o fim do intervalo a ser
// considerado. A seguir, deve reposicionar um pivô (valor médio do intervalo)
// de forma que à sua esquerda estejam apenas valores menores que ele e, à sua
// direita, apenas valores maiores que ele. Retorna a posição final do pivô.
int particiona(int vetor[MAX_ARR], int comeco, int fim);

// quicksort deve receber como parâmetros um vetor, seu tamanho, o começo e 
// o fim do intervalo a ser considerado no vetor. O procedimento deve
// implementar o algoritmo quicksort recursivo e exibir os resultados de cada
// uma de suas chamadas.
void quicksort(int vetor[MAX_ARR], int tam_vetor, int comeco, int fim);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

int main (int argc, char *argv[]){
  int v[MAX_ARR], tam_vetor = le_vetor(v);
  quicksort(v, tam_vetor, 0, tam_vetor-1);
  return 0;
}

void quicksort(int vetor[MAX_ARR], int tam_vetor, int comeco, int fim) {
  int indice_pivo;
  
  printf(">> Quicksort(começo = %i, fim = %i). Vetor  = ", comeco, fim);
  exibe_vetor(vetor, tam_vetor);
  
  if(comeco < fim){
    
    indice_pivo = particiona(vetor, comeco, fim);
    quicksort(vetor, tam_vetor, comeco, indice_pivo - 1); // analisa a esquerda
    quicksort(vetor, tam_vetor, indice_pivo + 1, fim); // analisa a direita
    
    printf("** Quicksort(começo = %i, fim = %i). Vetor  = ", comeco, fim);
    exibe_vetor(vetor, tam_vetor);
    
  } else if (comeco == fim){
    
    printf("** Quicksort(começo = %i, fim = %i). Vetor  = ", comeco, fim);
    exibe_vetor(vetor, tam_vetor);
    
  } else if (comeco > fim){
    
    printf("** Quicksort(começo = %i, fim = %i). Vetor  = ", comeco, fim);
    exibe_vetor(vetor, tam_vetor);
    
  }
}

int particiona(int vetor[MAX_ARR], int comeco, int fim) {
  int meio, i, j=0; // meio é o pivo

  meio = (fim - comeco)/2;
  troca_elementos(vetor, meio, fim);

  for(i=comeco;i<fim;i++){ // i é o ql elemento ta analisando, j é a primeira posição vaga para realocar o elemento 
    if(vetor[i]<vetor[fim]){
      troca_elementos(vetor, i, j); // joga o elemento menor que o pivo no vago
      j++;
    }
  }
  troca_elementos(vetor, fim, j); // joga o pivo na posição certa
  return j; // indice correto do pivo
}

void troca_elementos(int vetor[MAX_ARR], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < tam_vetor; i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}

int le_vetor(int vetor[MAX_ARR]) {
  int i = 0;
  printf("Digite valores para o vetor: ");
  while(vetor[i] != -100){
    scanf("%i", &vetor[i]);
    if (vetor[i] != -100 && i != MAX_ARR) i++;
    else break;
  } 
  return i;
}