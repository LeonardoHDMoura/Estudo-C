#include <stdio.h>

void LeNotas(float v[]);

int main (int argc, char *argv[])
{
    float Vet[8], media=0.0;
    int k;
    /*int i;
    for(i=0;i<8;i++){
        printf("Nota do Aluno %i: ", i+1);
        scanf("%f",&Vet[i]);
        media = media + Vet[i];
    }*/
    LeNotas(Vet);
    for(k=0;k<8;k++){
        media = media = Vet[k];
    }
    media = media/8;
    printf("\nMedia: %.2f\n", media);
    printf("------------------\n");
    for(k=0;k<8;k++){
        if (Vet[k] >= media){
            printf("Aluno %i = %.2f\n",k+1,Vet[k]);
        }
        
    }
    return 0;
}

void LeNotas(float v[]){
    int i;
    for(i=0;i<8;i++){
        printf("Nota do Aluno %i: ", i+1);
        scanf("%f",&v[i]);
    }
}