/*
3. Faça um programa que preenche uma matriz 4 x 4 com o produto do valor da linha e da
coluna de cada elemento. Em seguida, imprima na tela a matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system ("cls");

    int mat[4][4];
    int i, j;

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            mat[i][j] = i + j;
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    return 0;
}