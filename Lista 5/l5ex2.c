/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve descosiderar diferença entre maíusculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerString(char s[]);
void MinimizaString(char s[]);

int main (int argc, char *argv[])
{
    char s[MAX];
    int i, result;
    LerString(s);
    MinimizaString(s);
    for(i = 0; i < strlen(s); i++ ){
        if(s[i] != s[strlen(s)-i-1]){
            result = 0;
            break;
        }
        else result = 1;
    }
    if(result == 1) printf("É palíndromo");
    else printf("Não é palíndromo.");


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
void MinimizaString(char s[]){
    int i;
    for(i=0;i<strlen(s);i++){
        s[i] = tolower(s[i]);
    }
}