/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maíusculas e 
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerString(char s[]);
void MinimizaString(char s[]);
void bubble_sort(int vetor[MAX], int tam_vetor);
void troca_elementos(int vetor[MAX], int i, int j);
void troca_char(char s[], int i, int j);

int main (int argc, char *argv[])
{
    char s[MAX],s2[MAX];
    int v[MAX],i;
    LerString(s);
    MinimizaString(s);
    for(i=0;i<strlen(s);i++){
        v[i] = s[i];
    }
    bubble_sort(v,strlen(s));
    for(i=0;i<strlen(s);i++){
        s[i] = v[i];
        printf("%c",s[i]);
    }

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
void bubble_sort(int vetor[MAX], int tam_vetor) {
    int i,j;
    for(i=tam_vetor-1;i>0;i-=1){
        for(j=0;j<i;j++){
            if(vetor[j]>vetor[j+1])troca_elementos(vetor, j, j+1);
        }
    }
}
void troca_elementos(int vetor[MAX], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}
