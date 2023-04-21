/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string 
 * da seguinte maneira:
 *
 *            Z <-> P 
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *   
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
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
    char s[MAX],s2[MAX];
    int i;
    LerString(s);
    MinimizaString(s);
    for(i = 0; i < strlen(s); i++ ){
        switch(s[i]){
            case 'z': s2[i] = 'p';break;
            case 'p': s2[i] = 'z';break;
            case 'n': s2[i] = 'l';break;
            case 'l': s2[i] = 'n';break;
            case 'e': s2[i] = 'o';break;
            case 'o': s2[i] = 'e';break;
            case 'i': s2[i] = 'a';break;
            case 'a': s2[i] = 'i';break;
            case 't': s2[i] = 'r';break;
            case 'r': s2[i] = 't';break;
            default: s2[i] = s[i];break;
        }
    }
    printf("%s",s2);
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