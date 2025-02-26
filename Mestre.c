#include <stdio.h>

// Definição do tamanho das matrizes de habilidade
#define TAMANHO_HABILIDADE 5

// Valor para representar agua, navios e areas afetadas
#define AGUA 0 
#define NAVIO 3 
#define HABILIDADE 1 // Valor para representar as áreas afetadas pelas habilidades

// Protótipos das funções
void criarCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void aplicarHabilidade(int matriz[10][10], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int x, int y);

int main() {
    int matriz[10][10]; // Declaração de uma matriz 10x10

    // Inicializando todos os elementos da matriz com 0 (água)
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            matriz[x][y] = AGUA;
        }
    }

    // Posicionando o primeiro navio horizontalmente (linha 1, coluna 1)
    matriz[1][1] = NAVIO;
    matriz[1][2] = NAVIO;
    matriz[1][3] = NAVIO;

    // Posicionando o segundo navio verticalmente (linha 6, coluna 8)
    matriz[6][8] = NAVIO;
    matriz[7][8] = NAVIO;
    matriz[8][8] = NAVIO;

    // Posicionando o terceiro navio diagonalmente (linha 1, coluna 6)
    matriz[1][6] = NAVIO;
    matriz[2][5] = NAVIO;
    matriz[3][4] = NAVIO;

    // Posicionando o quarto navio diagonalmente (linha 4, coluna 6)
    matriz[4][6] = NAVIO;
    matriz[5][5] = NAVIO;
    matriz[6][4] = NAVIO;

    // Criando as matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicando as habilidades ao tabuleiro
    aplicarHabilidade(matriz, cone, 2, 2); // Cone na posição (2, 2)
    aplicarHabilidade(matriz, cruz, 5, 5); // Cruz na posição (5, 5)
    aplicarHabilidade(matriz, octaedro, 8, 8); // Octaedro na posição (8, 8)

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

// Função para criar a matriz de habilidade "Cone"
void criarCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || (i == 1 && j >= 1 && j <= 3) || (i == 3 && j >= 1 && j <= 3)) {
                cone[i][j] = HABILIDADE;
            } else {
                cone[i][j] = AGUA;
            }
        }
    }
}

// Função para criar a matriz de habilidade "Cruz"
void criarCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = HABILIDADE;
            } else {
                cruz[i][j] = AGUA;
            }
        }
    }
}

// Função para criar a matriz de habilidade "Octaedro"
void criarOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if ((i == 1 && j >= 1 && j <= 3) || (i == 2 && j >= 1 && j <= 3) || (i == 3 && j >= 1 && j <= 3)) {
                octaedro[i][j] = HABILIDADE;
            } else {
                octaedro[i][j] = AGUA;
            }
        }
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int matriz[10][10], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int x, int y) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (x + i < 10 && y + j < 10) { // Verifica se a posição está dentro do tabuleiro
                matriz[x + i][y + j] += habilidade[i][j];
            }
        }
    }
}