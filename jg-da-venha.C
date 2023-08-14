#include <stdio.h>

char board[3][3]; // Tabuleiro 3x3

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char player) {
    // Verificar linhas, colunas e diagonais
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // Vitória
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // Vitória
    }
    return 0; // Sem vitória ainda
}

int main() {
    char currentPlayer = 'X';
    int row, col;

    initializeBoard();

    printf("Bem-vindo ao Jogo da Velha!\n");

    for (int i = 0; i < 9; i++) {
        printf("\n");
        printBoard();

        printf("Jogador %c, digite a linha (0-2) e a coluna (0-2) separadas por um espaço: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            i--; // Para repetir a jogada do mesmo jogador
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            printf("\n");
            printBoard();
            printf("Jogador %c venceu! Parabéns!\n", currentPlayer);
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!checkWin('X') && !checkWin('O')) {
        printf("\n");
        printBoard();
        printf("Empate! O jogo terminou.\n");
    }

    return 0;
}
