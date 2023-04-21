/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3 
 * e, a seguir, exiba a sua forma transposta
 *
 * Exemplos: 
 *
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    [[1, 4, 7],
 *    [2, 5, 8],
 *    [3, 6, 9]]
 *    
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    [[1, 0, 0],
 *    [0, 1, 0],
 *    [0, 0, 1]]
 *    
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerMatriz(int mat[ARRAY_MAX][ARRAY_MAX]);
void ExibirMatriz3(int mat[ARRAY_MAX][ARRAY_MAX]);

int main (int argc, char *argv[])
{
    int mat1[ARRAY_MAX][ARRAY_MAX], mat1t[ARRAY_MAX][ARRAY_MAX],i;
    LerMatriz(mat1);
    for(i=0;i<3;i++){
        mat1t[0][i] = mat1[i][0];
        mat1t[1][i] = mat1[i][1];
        mat1t[2][i] = mat1[i][2];
    }

    ExibirMatriz3(mat1t);



    return 0;
}

void LerMatriz(int mat[ARRAY_MAX][ARRAY_MAX]){
        int i, j;
        for(j=0;j<3;j++){
            printf("Linha %i: ", j);
            for(i=0;i<3;i++){
                scanf("%i",&mat[j][i]);
        }

    }
}
void ExibirMatriz3(int mat[ARRAY_MAX][ARRAY_MAX]){
    int i, j;
    printf("[");
    for(j=0;j<3;j++){
            for(i=0;i<2;i++){
                printf("%i, ",mat[j][i]);
        }
        if(j == 2) break;
        printf("%i],\n",mat[j][2]);

    }
    printf("%i]]\n",mat[2][2]);
    
}