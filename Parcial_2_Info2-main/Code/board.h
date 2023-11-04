#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    bool isValidMove(int row, int col, char color);
    void makeMove(int row, int col, char color);
    void displayBoard() const;

private:
    char board[8][8];
};

#endif  // BOARD_H
