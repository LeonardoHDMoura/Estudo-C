/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve exibir o
 * array de Pessoas digitadas em ordem alfabética (nome). Utilize o algoritmo
 * de ordenação que preferir.
 * 
 * Exemplos: 
 *
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Tawfik
 *   Endereço: Praça da Mesquita, 17
 *   Idade: 18
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Praça Mauá, 1
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   [Pessoa{'Alexandre',34,'Praça Mauá, 1'},Pessoa{'Diego',30,'Rua da Miséria, 666'},Pessoa{'Tawfik',18,'Praça da Mesquita, 17'}]
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_PESSOAS 100

typedef struct {
    char nome[MAX];
    char end[MAX];
    int idade;
    
} Pessoa;

void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibe_pessoa(Pessoa p);
void exibe_pessoas(Pessoa p[MAX], int i);
void bubble_sort(Pessoa p[MAX_PESSOAS], int tam_vetor);
void troca_elementos(Pessoa p[MAX], int i, int j);

int main (int argc, char *argv[])
{
    Pessoa pessoas[MAX_PESSOAS];
    int i=0, busca;
    char resposta = 's', chave[MAX];

    while(resposta == 's'){
        pessoas[i]=ler_pessoa();
        printf("Deseja adicionar outra pessoa? (s/n): ");
        setbuf(stdin,0);
        scanf("%c",&resposta);
        if(resposta == 'n'){
            bubble_sort(pessoas, i);
            exibe_pessoas(pessoas,i);
        }
        i++;
    }
  return 0;
}

void ler_string(char s[MAX]){
    //printf("Digite a string: "); não usado
    setbuf(stdin,0);
    fgets(s, MAX, stdin);
    if(s[strlen(s) - 1] == '\n'){
        s[strlen(s) - 1] = '\0';
    }
}

Pessoa ler_pessoa(){
    Pessoa p;
    printf("Nome: ");
    ler_string(p.nome);
    printf("Endereço: ");
    ler_string(p.end);
    printf("Idade: ");
    scanf("%i",&p.idade);
    return p;
}

void exibe_pessoa(Pessoa p){
    printf("Pessoa{'%s','%s','%i'}",p.nome,p.end,p.idade);
}

void exibe_pessoas(Pessoa p[MAX], int i){
    int j;
    printf("[");
    for(j=0;j<i;j++){
        exibe_pessoa(p[j]);
        printf(", ");
    }
    exibe_pessoa(p[i]);
    printf("]");
}
void bubble_sort(Pessoa p[MAX_PESSOAS], int tam_vetor) {
    int i,j;
    for(i=tam_vetor-1;i>0;i-=1){
        j = strcmp(p[i].nome,p[i+1].nome);
        if(j > 0) troca_elementos(p, i, i+1);
        /*for(j=0;j<i;j++){
            if(vetor[j]>vetor[j+1])troca_elementos(vetor, j, j+1);
        }*/
    }
}

void troca_elementos(Pessoa p[MAX], int i, int j){
    Pessoa aux;
    aux = p[i];
    p[i] = p[j];
    p[j] = aux;
}