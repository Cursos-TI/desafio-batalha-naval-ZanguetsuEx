#include <stdio.h>

int main() {
    int matriz[10][10]; // Declaração de uma matriz 10x10

    // Inicializando todos os elementos da matriz com 0 (água)
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            matriz[x][y] = 0;
        }
    }

    // Posicionando o primeiro navio horizontalmente (linha 1, coluna 1)
    matriz[1][1] = 3;
    matriz[1][2] = 3;
    matriz[1][3] = 3;

    // Posicionando o segundo navio verticalmente (linha 5, coluna 5)
    matriz[5][5] = 3;
    matriz[6][5] = 3;
    matriz[7][5] = 3;

    // Exibindo o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("%d ", matriz[x][y]); // Exibe cada elemento da matriz
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    return 0;
}