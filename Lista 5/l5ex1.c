/* 
 * Enunciado: 
 *  Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerString(char s[]);
void Inverte_String(char s[], char s2[]);

int main (int argc, char *argv[])
{
    int i, j=0;
    char s[MAX],s2[MAX];
    LerString(s);
    Inverte_String(s,s2);
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
void Inverte_String(char s[], char s2[]) {
int i;
for(i = 0; i < strlen(s); i++ ){
s2[i] = s[strlen(s)-i-1];
}
}