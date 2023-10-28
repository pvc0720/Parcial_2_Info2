#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "HistoryManager.h"
using namespace std;

int main() {
    // Crear jugadores
    Player player1("Jugador1", 'B');
    Player player2("Jugador2", 'W');

    // Iniciar el juego
    Game othelloGame(player1, player2);

    // Jugar el juego
    othelloGame.play();

    // Determinar al ganador
    Player winner = othelloGame.getWinner();

    // Registrar el resultado en el historial
    HistoryManager historyManager;
    historyManager.recordResult(winner, (winner == player1) ? player2 : player1);

    // Imprimir el historial de partidas
    historyManager.printHistory();

    return 0;
}
