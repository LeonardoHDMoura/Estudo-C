#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// busca_linear deve receber um vetor, seu tamanho e uma chave a ser buscada.
// A função deve implementar o algoritmo de busca linear.
// Seu retorno deve ser o índice onde a chave for encontrada ou,
// caso não tenha encontrado nada, -1.
int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

//Definindo o vetor comom uma variável universal :)
int vet[MAX_ARR];

int main (int argc, char *argv[])
{
    int tam_vetor,chave,indice;
    tam_vetor = le_vetor(vet);
    printf("Digite a chave a ser procurada: ");
    scanf("%i",&chave);
    indice = busca_linear(vet, tam_vetor, chave);
    exibe_vetor(vet,tam_vetor);
    if(indice != -1) printf("A Chave %i encontrada na posicao %i.",chave,indice);
    else printf("A Chave %i nao foi encontrada.",chave);
    return 0;
}

int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave) {
    int j, retorno=1025;
    for(j=0;j<tam_vetor;j++){
            if(vetor[j] == chave){
                retorno = j;
                break;
        }
    }
    if(retorno == 1025) return -1;
    else return retorno;
}

int le_vetor(int vetor[MAX_ARR]) {
    int i=0;
    printf("Digite os valores do array: ");
    while(vetor[i] != -100){
        scanf("%i",&vetor[i]);
        if(vetor[i] != -100) i++;
        else if(vetor[i] == 100 || i == MAX_ARR) break;
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
