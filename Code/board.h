#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    bool isValidMove(int row, int col, char color);
    void makeMove(int row, int col, char color);
    void displayBoard() const;

private:
    std::vector<std::vector<char>> board;
};

#endif  // BOARD_H
