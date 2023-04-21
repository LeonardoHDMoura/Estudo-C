/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maíusculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
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

int main (int argc, char *argv[])
{
    char str1[MAX], str2[MAX], bstr1[MAX],bstr2[MAX];
    LerString(str1);
    MinimizaString(str1);
    strcpy(bstr1,str1);
    LerString(str2);
    MinimizaString(str2);
    strcpy(bstr2,str2);
    int v1[MAX],v2[MAX],i,valor;
    for(i=0;i<strlen(str1);i++){
        v1[i] = str1[i];
    }
    bubble_sort(v1,strlen(str1));
    for(i=0;i<strlen(str1);i++){
        str1[i] = v1[i];
    }
    for(i=0;i<strlen(str2);i++){
        v2[i] = str2[i];
    }
    bubble_sort(v2,strlen(str2));
    for(i=0;i<strlen(str2);i++){
        str2[i] = v2[i];
    }
    valor = strcmp(str1,str2);
    if(valor == 0) printf("%s é anagrama de %s",bstr1,bstr2);
    else printf("%s não é anagrama de %s",bstr1,bstr2);
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