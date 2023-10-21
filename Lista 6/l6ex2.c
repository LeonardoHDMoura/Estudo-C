/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve pedir para
 * o usuário digitar um nome a ser buscado no array de Pessoas. Caso o nome
 * seja encontrado, o endereço da Pessoa buscada deve ser exibido. Caso o nome
 * não seja encontrado, o usuário deve ser informado de que a busca não foi 
 * bem sucedida. Utilize o algoritmo de busca que preferir.
 *
 * Exemplos:
 *   Nome: Rodrigo
 *   Endereço: Aqui
 *   Idade: 31
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Ali
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   Endereço de Alexandre: Ali
 *
 *   Nome: Camila
 *   Endereço: Rua da Felicidade, 340
 *   Idade: 20
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Diego
 *   Endereço de Diego: Rua da Miséria, 666
 *
 *   Nome: Ahmad 
 *   Endereço: Avenida Brasil, 5670
 *   Idade: 19
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   'Alexandre' não foi encontrado
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
int busca_linear(char s[MAX], char chave[MAX]);
void MinimizaString(char s[MAX]);

int main (int argc, char *argv[])
{
    Pessoa p, pessoas[MAX_PESSOAS];
    int i=0, busca;
    char resposta = 's', chave[MAX];

    while(resposta == 's'){
        pessoas[i]=ler_pessoa();
        printf("Deseja adicionar outra pessoa? (s/n): ");
        setbuf(stdin,0);
        scanf("%c",&resposta);
        if(resposta == 'n'){
            printf("Digite um nome para ser buscado: ");
            ler_string(chave);
            busca = busca_linear(pessoas[i].nome,chave);
            if(busca == -1) printf("'%s' não foi encontrado.",chave);
            else printf("Endereço de %s: %s",chave,pessoas[i].end);
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

int busca_linear(char s[MAX], char chave[MAX]) {
    int j, retorno=MAX+1, resp;
    MinimizaString(chave);
    MinimizaString(s);
    for(j=0;j<MAX;j++){
        resp = strcmp(s,chave);
            if(resp == 0){
                retorno = j;
                break;
        }
    }
    if(retorno == MAX+1) return -1;
    else return retorno;
}

void MinimizaString(char s[MAX]){
    int i;
    for(i=0;i<strlen(s);i++){
        s[i] = tolower(s[i]);
    }
}
