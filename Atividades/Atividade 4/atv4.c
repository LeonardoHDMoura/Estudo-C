/* 
 * Enunciado no PDF!!!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING 100
#define MAX_ARRAY 4000
#define RAIO 6372795.477598

typedef struct {
  double lat, lon, alt;
  int tempo;
} Gps;

/* Funções de implementação obrigatória */
void troca_char(char *linha, char antigo, char novo);
void ler_ponto(char *linha, Gps *ponto);
double calcula_distancia(Gps pa, Gps pb);
double calcula_velocidade(Gps pa, Gps pb);
int ler_arquivo(char *nome_arq, Gps *pontos);
int escreve_dados(char *nome_arq, Gps *pontos, int tam);

/* Fuções para ajudar com testes */
void exibe_ponto(Gps ponto);
void exibe_pontos(Gps *pontos, int tam);
void lerLinha(char linha[], FILE *arq);
void separarInteiros(char linha[], int quantidade, int valores[]);
void separarFloats(char linha[], int quantidade, double valores[]);

int main (int argc, char *argv[])
{
    char entrada[MAX_STRING] = "entrada.csv";
    char saida[MAX_STRING] = "saida.csv";
    Gps pontos[MAX_ARRAY],*p;
    p = &pontos;
    int linhas,velocidades;
    linhas = ler_arquivo(entrada,p);
    if(linhas == -1) printf("Nao foi possivel ler os pontos...\n");
    else printf("%i de linhas lidas\n", linhas);
    velocidades = escreve_dados(saida,p,linhas);
    if(velocidades == -1) printf("Erro ao gravar as velocidades...\n");
    else printf("%i de velocidades gravadas\n", velocidades);
    
    return 0;
}

void troca_char(char *linha, char antigo, char novo) {
for(int i=0; i<strlen(linha); i++){
    if(linha[i] == antigo)
    linha[i] = novo;
}

}

void ler_ponto(char *linha, Gps *ponto) {
    double valores[MAX_ARRAY];
    troca_char(linha, ',','.');
    separarFloats(linha, MAX_STRING,valores);
    ponto->lat = valores[0];
    ponto->lon = valores[1];
    ponto->alt = valores[2];
    ponto->tempo = valores[3];
}

double calcula_velocidade(Gps pa, Gps pb) {
    return 3.6 * calcula_distancia(pa,pb)/(pa.tempo - pb.tempo);
}

double calcula_distancia(Gps pa, Gps pb) {
    double dh,dv;
    dh = RAIO * acos(sin(pa.lat)*sin(pb.lat) + cos(pa.lat)*cos(pb.lat)*cos(pa.lon-pb.lon));
    dv = pa.alt - pb.alt;
    return sqrt(pow(dh,2)+pow(dv,2));
} 

int ler_arquivo(char *nome_arq, Gps *pontos) {
    FILE *arq;
    char linha[MAX_STRING];
    int i=0;
    //printf("%s\n",nome_arq);
    arq = fopen(nome_arq,"r");
    if(arq == NULL){
        return -1;
    }
    lerLinha(linha,arq);
    //printf("%s\n",linha);
    while(1){
        lerLinha(linha,arq);
        ler_ponto(linha,&pontos[i]);
        i++;
        if(feof(arq)) break;
    }
    fclose(arq);
    return i;
}

int escreve_dados(char *nome_arq, Gps *pontos, int tam) {
    FILE *arq;
    char linha[MAX_STRING];
    int i,repeats=0;
    double velocidade = 0;
    arq = fopen(nome_arq,"w");
    sprintf(linha, "%d;%d;%d;%i;%d\n",pontos[0].lat,pontos[0].lon,pontos[0].alt,pontos[0].tempo,velocidade);
    fprintf(arq,"%s",linha);
    for(i=1;i<tam;i++){
        if(pontos[i].tempo != pontos[i-1].tempo){
            velocidade = calcula_velocidade(pontos[i],pontos[i-1]);
            sprintf(linha, "%d;%d;%d;%i;%d\n",pontos[i].lat,pontos[i].lon,pontos[i].alt,pontos[i].tempo,velocidade);
            fprintf(arq,"%s",linha);
        }
        else repeats++;
    }
    fclose(arq);
    return i-repeats;
}

void exibe_pontos(Gps *pontos, int tam) {
  for( int i = 0; i < tam; ++i )
    exibe_ponto(pontos[i]);
}

void exibe_ponto(Gps ponto) {
  printf("Coord: %f %s %f %s | Alt: %.1f m | Tempo: %i s\n",
      fabs(ponto.lat), ponto.lat<0?"Sul":"Norte",
      fabs(ponto.lon), ponto.lon<0?"Oeste":"Leste",
      ponto.alt, ponto.tempo);
}
void lerLinha(char linha[], FILE *arq){
fgets(linha, MAX_STRING, arq);
if(linha[strlen(linha)-1] == '\n') linha[strlen(linha)-1] = '\0';
}
void separarInteiros(char linha[], int quantidade, int valores[]){
char *token = strtok(linha,";");
for(int i=0;i<quantidade;i++){
    valores[i] = atoi(token);
    token = strtok(NULL,";");
}
}
void separarFloats(char linha[], int quantidade, double valores[]){
char *token = strtok(linha,";");
for(int i=0;i<quantidade;i++){
    valores[i] = atof(token);
    token = strtok(NULL,";");
}
}