/* 
 * Enunciado: 
 *    Repita o exercício anterior, mas agora utilize como entrada o arquivo
 *    notas.csv. A quantidade de alunos pode ser diferente de 3.
 *
 * Exemplo de linha:
 *    Rodrigo,1,2,3,4
 *
 *    Note que o separador utilizado é a vírgula
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista {
  Aluno aluno;
  struct SLista* prox;
} TLista;

/* Funções recomendadas (não precisa implementar nenhuma delas se não quiser)
 */
Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

int ler_alunos(TLista *alunos);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos

int main (int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

int ler_alunos(TLista *alunos) {
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
TLista* novo;
novo = (TLista*) malloc(sizeof(TLista));
if (novo == NULL) {
    printf("Nao foi possivel alocar memoria!");
    exit(EXIT_FAILURE);
}
novo->aluno = aluno;
TLista *aux;
aux = alunos;
while(aux->prox != NULL)
aux = aux->prox;
novo->prox = NULL;
aux->prox = novo;
}

TLista* cria_lista() {
TLista *p; /* Ponteiro para a lista */
p = (TLista*) malloc(sizeof(TLista));
if (p == NULL){
    printf("Não pode criar a lista");
    exit(EXIT_FAILURE);
}
p->prox = NULL; /* Atribui ponteiro nulo */
return p; /* Retorna endereço da lista */
}

TLista* destroi_lista(TLista* alunos) {
TLista *aux;
aux = alunos;
while(aux->prox != NULL) {
    aux = aux->prox;
    free(alunos);
    alunos = aux;
}
free(alunos);
return NULL;
}

float calcula_media(float* notas) {
    float media;
    media = (notas[0] + notas[1] + notas[2] + notas[3])/4;
    return media;
}

Aluno ler_aluno(char entrada[MAX]) {
    FILE *arq;
    char linha[MAX];
    arq = fopen(entrada,"r");
    if(arq == NULL){
        exit(EXIT_FAILURE);
    }
    while(1){
        lerLinha(linha,arq);
        if(feof(arq)) break;
    }
    fclose(arq);

}

void exibe_aluno(Aluno a) {
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
  TLista *aux = alunos->prox;
  while(aux != NULL) {
    exibe_aluno(aux->aluno);
    if( aux->prox != NULL ) printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}
void lerLinha(char *linha, FILE *arq){
fgets(linha, MAX, arq);
if(linha[strlen(linha)-1] == '\n') linha[strlen(linha)-1] = '\0';
}