#include <stdio.h>

#define TAM_L 3 // NÃO MODIFIQUE
#define TAM_C 6 // NÃO MODIFIQUE

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_matriz deve ler uma matriz de tamanho [TAM_L, TAM_C] linha por linha.
void le_matriz(int matriz[TAM_L][TAM_C]);

// busca_linear deve implementar o algoritmo de busca linear para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_linear(int vetor[TAM_C], int chave);

// busca_binaria deve implementar o algoritmo de busca binária para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_binaria(int vetor[TAM_C], int chave);

// verifica_ordenacao deve verificar se um vetor de tamanho [TAM_C] 
// está ordenado em ordem crescente. Se estiver, a função retorna 1.
// Se não estiver, a função retorna 0. Recebe como parâmetro o vetor.
int verifica_ordenacao(int vetor[TAM_C]);

// Outro brinde =)
void exibe_matriz(int matriz[TAM_L][TAM_C]);

int main (int argc, char *argv[])
{
    int mat[TAM_L][TAM_C], chave, indice, l, ordenado; //se busca = 0 sequencial, se busca = 1 binaria
    le_matriz(mat);
    printf("Valor a ser buscado: ");
    scanf("%i",&chave);
    exibe_matriz(mat);
    for(l=0;l<TAM_L;l++){
        ordenado = verifica_ordenacao(mat[l]);
        if(ordenado == 1){
            printf("A Linha %i ordenada. Verificando por busca binaria.\n",l);
            indice = busca_binaria(mat[l], chave);
            if(indice != -1){
                printf("Chave encontrada em [%i,%i].\n",l,indice);
                break;
            }
        }
        else{
            printf("A Linha %i desordenada. Verificando por busca linear.\n",l);
            indice = busca_linear(mat[l], chave);
            if(indice != -1){
                printf("Chave encontrada em [%i,%i].\n",l,indice);
                break;
            }
        }
    }
    if(indice == -1) printf("Chave nao foi encontrada.");
    

    return 0;
}

int busca_binaria(int vetor[TAM_C], int chave) {
    int retorno = 7, ini=0, fim =TAM_C, meio, i=0;
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
    if(retorno == 7) return -1;
    else return retorno;
}

int verifica_ordenacao(int vetor[TAM_C]) {
    int j, retorno=1;
    for(j=0;j<TAM_C;j++){
        if(j > 0 && vetor[j] < vetor[j-1]){
             retorno = 0;
             break;

        }

    }
    return retorno;
}

int busca_linear(int vetor[TAM_C], int chave) {
    int j, retorno=1025;
    for(j=0;j<TAM_C;j++){
            if(vetor[j] == chave){
                retorno = j;
                break;
        }
    }
    if(retorno == 1025) return -1;
    else return retorno;
}

void le_matriz(int matriz[TAM_L][TAM_C]) {
    int i, j;
    for(j=0;j<TAM_L;j++){
        printf("Linha %i: ", j);
        for(i=0;i<TAM_C;i++){
            scanf("%i",&matriz[j][i]);
        }

    }
}

void exibe_matriz(int matriz[TAM_L][TAM_C]) {
  printf("[");
  for (int i = 0; i < TAM_L; ++i) { 
    printf("[");
    for (int j = 0; j < TAM_C; ++j) {
      printf("%i", matriz[i][j]);
      if( j < TAM_C - 1) printf(", ");
    }
    printf("]");
    if( i < TAM_L - 1 ) printf(",\n");
  }
  printf("]\n");
}
