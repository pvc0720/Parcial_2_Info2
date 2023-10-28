#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game {
public:
    // Constructor que acepta dos jugadores
    Game(const Player& player1, const Player& player2);

    void play();
    Player getWinner() const;

private:
    Player player1;
    Player player2;
    const Player* currentPlayer; // Cambio a puntero constante
    Board board;
};

#endif  // GAME_H
