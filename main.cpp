#include <iostream>
#include <vector>

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, EMPTY));
    char currentPlayer = PLAYER_X;
    int row, col;
    bool gameOver = false;

    std::cout << "Bem-vindo ao Jogo da Velha!\n";

    while (!gameOver) {
        printBoard(board);

        std::cout << "Jogador " << currentPlayer << ", insira a linha e a coluna (0, 1, ou 2): ";
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
            std::cout << "Movimento inválido. Tente novamente.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Jogador " << currentPlayer << " ganhou!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            std::cout << "Empate!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    return 0;
}
