/*
1. Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system ("cls");

    int mat[4][4];
    int maiorQ10=0, elemento=0;
    int i, j;
    
    // Entrada de dados
    printf("Leia uma matriz 4x4:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%2d° elemento: ", elemento+1);
            scanf("%d", &mat[i][j]);
            elemento++;
        }
    }

    // Imprimindo matriz
    printf("\n\nImprimindo matriz:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%2d ", mat[i][j]);

            if (mat[i][j] > 10) {
                maiorQ10++;
            }
        }
        printf("\n");
    }

    // Imprimindo quantidade de valores maiores que 10 e quais esses valores
    printf("\n\nA matriz digitada possuí %d valores maior que 10, sendo:\n", maiorQ10);
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (mat[i][j] > 10) {
                printf("%2d ", mat[i][j]);
            }
        }
    }

    printf("\n\n\n");
    return 0;
}