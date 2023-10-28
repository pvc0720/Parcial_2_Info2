#include "Board.h"
#include <iostream>
using namespace std;


Board::Board() : board(8, vector<char>(8, ' ')) {
    // Inicializar el tablero con las fichas iniciales
    board[3][3] = board[4][4] = 'W'; // Fichas blancas
    board[3][4] = board[4][3] = 'B'; // Fichas negras
}


bool Board::isValidMove(int row, int col, char color) {
    // Verificar si la casilla está vacía
    if (board[row][col] != ' ') {
        return false;
    }

    char opponentColor = (color == 'B') ? 'W' : 'B';

    bool validMove = false;

    // Direcciones: arriba, abajo, izquierda, derecha, diagonales
    int dirX[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dirY[] = {-1, 1, 0, 0, -1, -1, 1, 1};

    for (int dir = 0; dir < 8; dir++) {
        int x = row + dirX[dir];
        int y = col + dirY[dir];

        // Verificar si la casilla siguiente está dentro del tablero
        if (x < 0 || x >= 8 || y < 0 || y >= 8) {
            continue;
        }

        if (board[x][y] == opponentColor) {
            // Continuar en la dirección opuesta
            x += dirX[dir];
            y += dirY[dir];

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == ' ') {
                    break;
                }
                if (board[x][y] == color) {
                    validMove = true;
                    break;
                }
                x += dirX[dir];
                y += dirY[dir];
            }
        }
    }

    return validMove;
}

void Board::makeMove(int row, int col, char color) {
    board[row][col] = color;
    char opponentColor = (color == 'B') ? 'W' : 'B';

    // Direcciones: arriba, abajo, izquierda, derecha, diagonales
    int dirX[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dirY[] = {-1, 1, 0, 0, -1, -1, 1, 1};

    for (int dir = 0; dir < 8; dir++) {
        int x = row + dirX[dir];
        int y = col + dirY[dir];

        if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] != opponentColor) {
            continue;
        }

        bool validMove = false;
        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[x][y] == ' ') {
                break;
            }
            if (board[x][y] == color) {
                validMove = true;
                break;
            }
            x += dirX[dir];
            y += dirY[dir];
        }

        if (validMove) {
            x = row + dirX[dir];
            y = col + dirY[dir];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == color) {
                    break;
                }
                board[x][y] = color;
                x += dirX[dir];
                y += dirY[dir];
            }
        }
    }
}

void Board::displayBoard() const {
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++) {
            cout << "[" << board[i][j] << "]";
        }
        cout << endl;
    }
}
