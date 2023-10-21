/* 
 * Enunciado: 
 *    Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 *    struct contendo o seu RA, 4 notas e a média do aluno. O programa
 *    principal deve pedir para que o usuário digite o RA e as 4 notas de 
 *    3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
*
 * Exemplos:
 * 
 *    Aluno: Rodrigo 2 3 4 5
 *    Aluno: Alexandre 10 10 8 9
 *    Aluno: Diego 7 8 10 10 
 *    (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
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

/* Funções recomendadas */
Aluno ler_aluno();
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"

int main (int argc, char *argv[])
{
  Aluno alunos;
  TLista *lista;
  char op;
  lista = cria_lista();
  do{
    alunos = ler_aluno();
    insere_no_fim(lista, alunos);
    printf("Mais itens (S/N)? ");
    setbuf(stdin,0);
    scanf("%c",&op);
  }while(toupper(op) != 'N');
  exibe_lista(lista);
  lista = destroi_lista(lista);
  return EXIT_SUCCESS;
}

Aluno ler_aluno() {
    Aluno a;
    printf("Aluno: ");
    ler_string(a.nome);
    printf("Notas: ");
    scanf("%f %f %f %f",&a.notas[0],&a.notas[1],&a.notas[2],&a.notas[3]);
    a.media = calcula_media(a.notas);
    return a;
}

float calcula_media(float* notas) {
    float media;
    media = (notas[0] + notas[1] + notas[2] + notas[3])/4;
    return media;
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

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}
