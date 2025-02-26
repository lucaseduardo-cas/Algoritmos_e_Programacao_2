/*
4. Leia uma matriz 4 x 4, imprima a matriz e retorne a localização (linha e a coluna) do
maior valor
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void) {
    setlocale (LC_ALL, "portuguese");
    system ("cls");

    //int mat[4][4]={{1,2,3,4}, {5,20,7,8}, {9,10,11,12}, {13,14,15,16}};
    int mat[4][4];
    int maiorNumero=0, linha, coluna;
    int i, j, k=0;

    printf("Leia uma matriz 4x4:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("  %2d° elemento: ", k + 1);
            scanf("%d", &mat[i][j]);
            k++;
        }
    }

    printf("\n\nImprimindo matriz:\n\n");
    printf("      A   B   C   D\n\n");
    for (i=0; i<4; i++) {
        printf("%d    ", i + 1);
        for (j=0; j<4; j++) {
            printf("%2d  ", mat[i][j]);

            if (maiorNumero < mat[i][j]) {
                maiorNumero = mat[i][j];
                linha = i + 1;
                coluna = j + 1;
            }
        }
        printf("\n");
    }

    switch (coluna) {
        case 1: coluna = 'A'; break;
        case 2: coluna = 'B'; break;
        case 3: coluna = 'C'; break;
        case 4: coluna = 'D'; break;
        default: break;
    }

    printf("\n\nMaior valor: %d\n", maiorNumero);
    printf("Localização: Linha %d; Coluna %c", linha, coluna);

    printf("\n\n\n");
    return 0;
}