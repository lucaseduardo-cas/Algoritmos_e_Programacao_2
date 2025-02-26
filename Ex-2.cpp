/*
2. Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais
elementos. Escreva ao final a matriz obtida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system ("cls");

    int mat[5][5];
    int i, j;

    printf("Imprimindo matriz 5x5, cujo diagonal principal = 1 e demais = 0:\n\n");
    for (i=0; i<5; i++) {              // Linha
        printf("   ");         
        for (j=0; j<5; j++) {          // Coluna 
            if (i == j) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    return 0;
}