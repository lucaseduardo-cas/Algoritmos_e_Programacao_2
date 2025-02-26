#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função para exibir o tabuleiro no formato desejado

void escolher_simbolo(char *opcao) {
    while(1) {
        system("cls");
        printf("==================== JOGO DA VELHA ====================\n");
        printf("\nEscolha seu símbolo:\n");
        printf("  [X]\n");
        printf("  [O]\n");
        printf("\nOpção: ");
        scanf(" %c", opcao);

        if (*opcao != 'x' && *opcao != 'X' && *opcao != 'o' && *opcao != 'O' && *opcao != '0') {
            printf("Caractér inválido!\n\n");
            system("pause");
            continue;
        } else {
            break;
        }
    }
}

void exibir_tabuleiro(char grade[3][3]) {  
    printf("\n    A     B     C\n");  
    printf("1   %c  |  %c  |  %c   \n", grade[0][0], grade[0][1], grade[0][2]);  
    printf("   ----+-----+----\n");  
    printf("2   %c  |  %c  |  %c   \n", grade[1][0], grade[1][1], grade[1][2]);  
    printf("   ----+-----+----\n");  
    printf("3   %c  |  %c  |  %c   \n", grade[2][0], grade[2][1], grade[2][2]);  
    printf("\n");
}  

void exibir_cabecalho(char opcao) {
    system("cls");
    printf("==================== JOGO DA VELHA ====================\n");
    printf("\nDigite a coordenada de (%c): (Linha / Coluna):\n", opcao);
}


int exibir_vencedor(char opcao, char grade[3][3]) {
    if (((opcao == grade[0][0]) && (opcao == grade[0][1]) && (opcao == grade[0][2])) ||
        ((opcao == grade[1][0]) && (opcao == grade[1][1]) && (opcao == grade[1][2])) ||
        ((opcao == grade[2][0]) && (opcao == grade[2][1]) && (opcao == grade[2][2])) ||
        ((opcao == grade[0][0]) && (opcao == grade[1][0]) && (opcao == grade[2][0])) ||
        ((opcao == grade[0][1]) && (opcao == grade[1][1]) && (opcao == grade[2][1])) ||
        ((opcao == grade[0][2]) && (opcao == grade[1][2]) && (opcao == grade[2][2])) ||
        ((opcao == grade[0][0]) && (opcao == grade[1][1]) && (opcao == grade[2][2])) ||
        ((opcao == grade[0][2]) && (opcao == grade[1][1]) && (opcao == grade[2][0]))) {     
        printf("\nFim de jogo! (%c) é o vencedor.\n\n", (opcao == 'X') ? 'X' : 'O');

        return 1;
    } else {
        printf("\nEMPATE!\n\n");
        return 0;
    }
}


int main (void) {
    setlocale (LC_ALL, "portuguese");

    char opcao, coordenadaLetra=0, confirmarOpcao=0;
    char grade[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int coordenadaNumero=0;
    int i, j;
    
    escolher_simbolo(&opcao);

    // Escolha do símbolo
    do {  
        // Normalizando a opção escolhida  
        opcao = (opcao == 'x' || opcao == 'X') ? 'X' : 'O';  

        // Escolha da coordenada
        exibir_cabecalho(opcao);
        exibir_tabuleiro(grade);    

        // Validando dados Linha
        while(1) {
            printf("Linha  (1, 2, 3): ");
            if (scanf(" %d", &coordenadaNumero) != 1) {  // Verifica se a entrada NÃO é um número
                printf("\nLinha inválida!\n\n");
                system("pause");
                exibir_cabecalho(opcao);
                exibir_tabuleiro(grade); 
                while (getchar() != '\n');
                continue;
            }

            if (coordenadaNumero != 1 && coordenadaNumero != 2 && coordenadaNumero != 3) {
                printf("\nLinha inválida!\n\n");
                //exibir_cabecalho(opcao);
                //exibir_tabuleiro(grade); 
                continue;
            } else {
                i = coordenadaNumero - 1;
                break;
            }
        }
        
        // Validando dados Coluna
        while (1) {
            printf("Coluna (A, B, C): ");
            scanf(" %c", &coordenadaLetra);
            if (coordenadaLetra != 'a' && coordenadaLetra != 'A' &&
                coordenadaLetra != 'b' && coordenadaLetra != 'B' &&
                coordenadaLetra != 'c' && coordenadaLetra != 'C') {
                printf("\nColuna inválida!\n\n");
                system("pause");
                exibir_cabecalho(opcao);
                exibir_tabuleiro(grade); 
                printf("Linha  (1, 2, 3): %d\n", coordenadaNumero);
                continue;
            } else {
                if (coordenadaLetra == 'a' || coordenadaLetra == 'A') {j = 0;}
                if (coordenadaLetra == 'b' || coordenadaLetra == 'B') {j = 1;}
                if (coordenadaLetra == 'c' || coordenadaLetra == 'C') {j = 2;}
                break;     
            }
        }

        // Verifica se a posição está vazia antes de atribuir 
        if (grade[i][j] != ' ') {  
            printf("\nEssa posição já está ocupada! Escolha outra.\n");  
            system("pause");  
            continue;  
        } else { // Confirma a coordenada escolhida pelo usuário
            grade[i][j] = opcao;
            exibir_cabecalho(opcao);
            exibir_tabuleiro(grade); 

            if (grade[i][j] == opcao) {
                printf("\nDeseja confirmar a coordenada selecionada? (s/n) ");
                scanf(" %c", &confirmarOpcao);
    
                if (confirmarOpcao == 's' || confirmarOpcao == 'S') {
                    exibir_tabuleiro(grade); 
                } else if (confirmarOpcao == 'n' || confirmarOpcao == 'N') {
                    grade[i][j] = ' ';
                    continue;
                }
            }            
        }

        // Exibir tabuleiro atualizado  
        exibir_cabecalho(opcao);
        exibir_tabuleiro(grade); 
        if (exibir_vencedor(opcao, grade)) {
            system("pause");  
            return 0;
        }

        // Alterna a opção a cada jogada.
        opcao = (opcao == 'X') ? 'O' : 'X'; 

    } while(1);

    printf("\n\n\n");
    return 0;
}