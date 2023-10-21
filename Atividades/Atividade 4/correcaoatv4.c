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
void lerLinha(char *linha, FILE *arq);
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
    escreve_dados(saida,pontos,linhas);
    
    return 0;
}

void troca_char(char *linha, char antigo, char novo) {
for(int i=0; i<strlen(linha); i++){
    if(linha[i] == antigo)
    linha[i] = novo;
}

}

void ler_ponto(char *linha, Gps *ponto) {
    char *token = strtok(linha,";");
    ponto->lat = atof(token);
    token = strtok(NULL,";");
    ponto->lon = atof(token);
    token = strtok(NULL,";");
    ponto->alt = atof(token);
    token = strtok(NULL,";");
    ponto->tempo = atoi(token);
}

double calcula_velocidade(Gps pa, Gps pb) {
    return 3.6 * calcula_distancia(pa,pb)/(pa.tempo - pb.tempo);
}

double calcula_distancia(Gps pa, Gps pb) {
    double dh,dv;
    dh = RAIO * acos(sin(pa.lat* M_PI/180)*sin(pb.lat * M_PI/180) + cos(pa.lat * M_PI/180)*cos(pb.lat * M_PI/180)*cos(pa.lon*M_PI/180-pb.lon*M_PI/180));
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
        troca_char(linha, ',', '.');
        ler_ponto(linha, pontos + i);
        i++;
        if(feof(arq)) break;
    }
    fclose(arq);
    return i;
}

int escreve_dados(char *nome_arq, Gps *pontos, int tam) {
    FILE *arq;
    float vel = 0;
    int i=0;
    char linha[MAX_STRING];

    arq = fopen(nome_arq,"w");
    if(arq == NULL){
        return -1;
    }

    fputs("Lat;Lon;Alt;Tempo;Vel\n",arq);
    sprintf(linha, "%f;%f;%.0f;%i;%f\n", pontos[0].lat,pontos[0].lon,pontos[0].alt,pontos[0].tempo,0.0);
    troca_char(linha,'.',',');
    fputs(linha,arq);

    for(i=1;i<tam;i++){
        if(calcula_distancia(pontos[i], pontos[i-1]) !=0 && (pontos[i].tempo != pontos[i-1].tempo)){
            vel = calcula_velocidade(pontos[i],pontos[i-1]);
            sprintf(linha, "%f;%f;%.0f;%i;%f\n", pontos[i].lat,pontos[i].lon,pontos[i].alt,pontos[i].tempo,vel);
            troca_char(linha,'.',',');
            fputs(linha,arq);
        }
    }

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
void lerLinha(char *linha, FILE *arq){
fgets(linha, MAX_STRING, arq);
if(linha[strlen(linha)-1] == '\n') linha[strlen(linha)-1] = '\0';
}
