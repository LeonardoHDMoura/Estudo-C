/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de uma pessoa 
 * e armazene esses dados em uma estrutura. Em seguida, imprima na tela os 
 * dados da estrutura lida. Para armazenar os dados, escolha os tipos de dados 
 * mais adequados para cada informação. Utilize, obrigatoriamente, uma função 
 * para realizar a leitura da estrutura e outra função para realizar sua 
 * exibição. Outras funções auxiliares podem ser utilizadas.
 *
 * Exemplos:
 *
 *  Nome: Rodrigo Nicola
 *  Endereço: Praça Mauá, 1
 *  Idade: 31
 *  Pessoa{'Rodrigo Nicola',31,'Praça Mauá, 1'}
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[MAX];
    char end[MAX];
    int idade;
    
} Pessoa;

void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibe_pessoa(Pessoa p);

int main (int argc, char *argv[]){
    Pessoa p;
    p = ler_pessoa();
    exibe_pessoa(p);
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
