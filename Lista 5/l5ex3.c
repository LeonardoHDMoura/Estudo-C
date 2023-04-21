/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a difereça entre maíusculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerString(char s[]);
int busca_linear(char s[], char chave);
void MinimizaString(char s[]);

int main (int argc, char *argv[])
{
    char s[MAX], chave;
    int result;
    LerString(s);
    MinimizaString(s);
    printf("Digite a chave: ");
    setbuf(stdin,0);
    scanf("%c",&chave);
    chave = tolower(chave);
    result = busca_linear(s,chave);
    if(result == -1) printf("Caractere %c não foi encontrado.",chave);
    else printf("Caractere %c foi encontrado na posição %i",chave,result);

    return 0;
}
void LerString(char s[]){
    printf("Digite a string: ");
    setbuf(stdin,0);
    fgets(s, MAX, stdin);
    if(s[strlen(s) - 1] == '\n'){
        s[strlen(s) - 1] = '\0';
    }
}
int busca_linear(char s[], char chave) {
    int j, retorno=MAX+1;
    for(j=0;j<MAX;j++){
            if(s[j] == chave){
                retorno = j;
                break;
        }
    }
    if(retorno == MAX+1) return -1;
    else return retorno;
}
void MinimizaString(char s[]){
    int i;
    for(i=0;i<strlen(s);i++){
        s[i] = tolower(s[i]);
    }
}