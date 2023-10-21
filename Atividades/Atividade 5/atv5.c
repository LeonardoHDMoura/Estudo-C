/* 
 * Enunciado: 
 *  Elabore um programa capaz de fazer a leitura de uma lista de pokemons 
 *  de um arquivo csv (separador ',') e aramazene esses dados em uma estrutura
 *  do tipo lista. Após a construção da lista de pokemons, seu programa deve 
 *  permitir ao usuário que informe o nome de um pokemon a ser buscado na lista
 *  para exibir todas as suas informações na tela ou, caso a busca não tenha
 *  encontrado nada, informar isso ao usuário.
 *
 *  É OBRIGATÓRIO implementar as subrotinas descritas nos protótipos do código.
 *
 * Exemplos:
 *
 *   Digite o pokemon a ser buscado: Zapdos
 *   Zapdos (90 HP, 90 AT, 85 DEF, 100 SP)
 *
 *   Digite o pokemon a ser buscado: Pikachu
 *   Pikachu (35 HP, 55 AT, 40 DEF, 90 SP)
 *
 *   Digite o pokemon a ser buscado: Pichu
 *   O pokemon não foi encontrado...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  int HP, AT, DEF, SP;
} Pokemon;

typedef struct Slista {
  Pokemon pk;
  struct Slista* prox;
} TLista;

/* 
 * Subrotinas de implementação OBRIGATÓRIA 
 * Essas subrotinas devem ser implementadas de acordo com a sua descrição.
 * Não modifique os protótipos.
 * 
 */ 

// A função cria_lista deve criar uma estrutura do tipo lista.
// Seu retorno é um ponteiro que aponta para o começo da lista.
TLista* cria_lista();

// A função destrói lista deve liberar a memória de todos os elementos da lista.
// Seu retorno deve ser NULL se o procedimento foi bem sucedido.
TLista* destroi_lista(TLista* pokedex);

// O procedimento insere_no_fim deve inserir um novo elemento no final da lista.
void insere_no_fim(TLista* pokedex, Pokemon pk);

// A função preenche_pokedex deve realizar a leitura de um arquivo e armazenar
// as informações lidas em uma estrutura do tipo lista. Seu retorno deve ser
// -1 se houve algum erro ou a quantidade de itens lidos, em caso de sucesso.
int preenche_pokedex(TLista* pokedex, char nome_arq[MAX]);

// A função busca_pokemon deve um pokemon a partir de seu nome em uma estrutura
// do tipo lista, armazenando o resultado no endereço pk. Seu retorno é 0 em
// caso de busca bem sucedida e -1 caso o pokemon não tenha sido encontrado.
int busca_pokemon(TLista* pokedex, char nome_pk[MAX], Pokemon* pk);

// A função ler_pokemon realiza a leitura de uma estrutura Pokemon a partir de
// uma linha. Seu retorno é a estrutura lida.
Pokemon ler_pokemon(char linha[MAX]);


/* 
 * Funções para uso livre 
 * Não modifique nada. Essas funções já estão prontas para uso.
 *
 */
// exibe um pokemon
void exibe_pokemon(Pokemon pk); 
// exibe a lista de pokemons
void exibe_pokedex(TLista* pokedex); 
// le uma string de forma "segura" de um arquivo.
// No prâmetro arq, é possível usar stdin para ler uma string do console
//Ex.: ler_string(linha,stdin) -> le do console
void ler_string(char* s,FILE* arq); 

int main (int argc, char *argv[]){
char nome_arq[MAX] = "pokedex.csv", pk_nome[MAX];
TLista *pokedex;
Pokemon *pokemon;
int numero, resp;
pokedex = cria_lista();
numero = preenche_pokedex(pokedex, nome_arq);
exibe_pokedex(pokedex);
setbuf(stdin,0);
printf("Digite o nome do pokemon a ser buscado: ");
fgets(pk_nome, MAX, stdin);
if(pk_nome[strlen(pk_nome) - 1] == '\n'){
    pk_nome[strlen(pk_nome) - 1] = '\0';
}
printf("%s",pk_nome);
resp = busca_pokemon(pokedex,pk_nome,pokemon);
if(resp == -1)printf("O pokemon não foi encontrado...");
else exibe_pokemon(*pokemon);
pokedex = destroi_lista(pokedex);
return EXIT_SUCCESS;
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

TLista* destroi_lista(TLista* pokedex) {
TLista *aux;
aux = pokedex;
while(aux->prox != NULL) {
    aux = aux->prox;
    free(pokedex);
    pokedex = aux;
}
free(pokedex);
return NULL;
}

void insere_no_fim(TLista *p, Pokemon pk) {
TLista* novo;
novo = (TLista*) malloc(sizeof(TLista));
if (novo == NULL) {
    printf("Nao foi possivel alocar memoria!");
    exit(EXIT_FAILURE);
}
novo->pk = pk;
TLista *aux;
aux = p;
while(aux->prox != NULL)
aux = aux->prox;
novo->prox = NULL;
aux->prox = novo;
}

int busca_pokemon(TLista* pokedex, char nome_pk[MAX], Pokemon* pk) {
    int j;
    TLista *aux;
    aux = pokedex;
    while(aux->prox != NULL){
            if(strcmp(aux->pk.nome,nome_pk) == 0){
                strcpy(pk->nome, aux->pk.nome);
                pk->HP = aux->pk.HP;
                pk->AT = aux->pk.AT;
                pk->DEF = aux->pk.DEF;
                pk->SP = aux->pk.SP;
                return 0;
        }
        aux = aux->prox;
    }
   return -1;
	
}

Pokemon ler_pokemon(char linha[MAX]) {
Pokemon pklido;
char *token = strtok(linha,",");
    strcpy(pklido.nome, token);
    token = strtok(NULL,",");
    pklido.HP = atoi(token);
    token = strtok(NULL,",");
    pklido.AT = atoi(token);
    token = strtok(NULL,",");
    pklido.DEF = atoi(token);
    token = strtok(NULL,",");
    pklido.SP = atoi(token);
	return pklido;
}

int preenche_pokedex(TLista* pokedex, char nome_arq[MAX]) {
FILE *file = fopen(nome_arq,"r");
Pokemon pklido;
int i = 0;
if(file == NULL){
    printf("Erro ao ler arquivo.");
    return -1;
}
char buffer[MAX];
ler_string(buffer, file);
while(1){
    if(feof(file)) break;
    ler_string(buffer, file);
    pklido = ler_pokemon(buffer);
    insere_no_fim(pokedex, pklido);
    i++;
}
fclose(file);
return i;
}

void exibe_pokemon(Pokemon pk) {
  printf("%s (%i HP, %i AT, %i DEF, %i SP)\n",
         pk.nome, pk.HP, pk.AT, pk.DEF, pk.SP);
}

void exibe_pokedex(TLista* pokedex) {
  TLista* aux = pokedex->prox;  
  while(aux != NULL) {
    printf("%10s", "");
    exibe_pokemon(aux->pk);
    aux = aux->prox;
  }
}

void ler_string(char* linha,FILE* arq) { 
	fgets(linha, MAX, arq);
    if (linha[strlen(linha) - 1] == '\n')
      linha[strlen(linha) - 1] = '\0';
}
