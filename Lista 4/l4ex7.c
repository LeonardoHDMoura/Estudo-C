/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de duas matriz 3x3 
 * e, a seguir, exiba a matriz resultante da multiplicação entre elas.
 *
 * Exemplos: 
 *
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[1, 1, 1],
 *    [2, 2, 2],
 *    [3, 3, 3]]
 *    
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[14, 14, 14],
 *    [32, 32, 32],
 *    [50, 50, 50]]
 * 
 *    Digite a linha 0: 2 0 0
 *    Digite a linha 1: 0 2 0
 *    Digite a linha 2: 0 0 2
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[2, 2, 2],
 *    [4, 4, 4],
 *    [6, 6, 6]]
 *    
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void LerMatriz(int mat[ARRAY_MAX][ARRAY_MAX]);
void ExibirMatriz3(int mat[ARRAY_MAX][ARRAY_MAX]);

int main (int argc, char *argv[])
{
    int mat1[ARRAY_MAX][ARRAY_MAX], mat2[ARRAY_MAX][ARRAY_MAX], matmulti[ARRAY_MAX][ARRAY_MAX],i;
    printf("Matriz 1: \n");
    LerMatriz(mat1);
    printf("\nMatriz 2: \n");
    LerMatriz(mat2);
    for(i=0;i<3;i++){
        matmulti[0][i] = mat1[0][0] * mat2[0][i] + mat1[0][1] * mat2[1][i] + mat1[0][2] * mat2[2][i];
        matmulti[1][i] = mat1[1][0] * mat2[0][i] + mat1[1][1] * mat2[1][i] + mat1[1][2] * mat2[2][i];
        matmulti[2][i] = mat1[2][0] * mat2[0][i] + mat1[2][1] * mat2[1][i] + mat1[2][2] * mat2[2][i];
    }
    ExibirMatriz3(matmulti);
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
