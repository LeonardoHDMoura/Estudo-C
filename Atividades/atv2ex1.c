// Amanda Carolina Ambrizzi Ramin; 22.00721-0
//Leonardo Henrique Dias Moura; 21.01837-5

#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// selection_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// bubble_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// troca_elementos deve receber um vetor e dois índices e trocar os troca 
// os elementos do vetor de lugar.
void troca_elementos(int vetor[MAX_ARR], int i, int j);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

int main (int argc, char *argv[])
{
  int vet[MAX_ARR], op1, op2, a;
  a = le_vetor(vet);
  exibe_vetor(vet,a);
  printf("Selecione o método de ordenação (1 - Selection, 2 - Bubble): ");
  scanf("%i", &op1);
  printf("Ordenação crescente (1) ou decrescente (0): ");
  scanf("%i", &op2);
  
  if(op1 == 2) bubble_sort(vet,a,op2);
  else if(op1 == 1) selection_sort(vet,a,op2);
  exibe_vetor(vet,a);
  return 0;
}

void troca_elementos(int vetor[MAX_ARR], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente) {
  int i,j,min,velhomin;
  if(crescente == 1){
    for(i=0;i<tam_vetor;i++){
      min = i;
      for(j=tam_vetor-1;j>i;j-=1){
        if(vetor[j]<vetor[min]) min = j;
      }
      troca_elementos(vetor,min,i);
    }
  }
  else{
    for(i=0;i<tam_vetor;i++){
      min = i;
      for(j=tam_vetor-1;j>i;j-=1){
        if(vetor[j]>vetor[min]) min = j;
      }
      troca_elementos(vetor,min,i);
    }
  }
}

void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente) {
  int i,j;
  if(crescente == 1){
    for(i=tam_vetor-1;i>0;i-=1){
      for(j=0;j<i;j++){
        if(vetor[j]>vetor[j+1]) troca_elementos(vetor, j, j+1);
      }
    }
  }
  else{
    for(i=tam_vetor-1;i>0;i-=1){
      for(j=0;j<i;j++){
        if(vetor[j]<vetor[j+1]) troca_elementos(vetor, j, j+1);
      }
    }
  }
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

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < tam_vetor; i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}
