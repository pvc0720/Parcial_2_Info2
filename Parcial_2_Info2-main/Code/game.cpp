#include "Game.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Game::Game(const Player& player1, const Player& player2)
    : player1(player1), player2(player2), currentPlayer(&player1), board() {
    // Inicializa el juego con los jugadores proporcionados
}

void Game::play() {
    int turn = 1;

    while (true) {
        // Mostrar el estado actual del tablero
        board.displayBoard();

        // Determinar el color del jugador actual
        char currentPlayerColor = (turn % 2 == 1) ? 'B' : 'W';

        // Verificar si el jugador actual puede realizar un movimiento válido
        bool canMove = false;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (board.isValidMove(row, col, currentPlayerColor)) {
                    canMove = true;
                    break;
                }
            }
            if (canMove) {
                break;
            }
        }

        cout<<"Turno # "<<turn<<endl;
        // Si el jugador no puede mover, pasa su turno
        if (!canMove) {
            cout << "El jugador " << currentPlayer->getName() << " no puede mover. Pasa el turno." << endl;
        } else {
            // Pedir al jugador actual que realice un movimiento
            cout << "Turno del jugador " << currentPlayer->getName() << " (Fichas color " << currentPlayerColor << ")." << endl;
            int row, col;
            char colLabel; // Agregar una variable para la etiqueta de la columna

            do {
<<<<<<< HEAD:Parcial_2_Info2-main/Code/game.cpp
                cout << "Ingrese la fila (1-8) y columna (a-h) separadas por espacio: ";

                           // Manejo de excepciones para formato inadecuado
                           try {

                               cin >> row >> colLabel;
                               if (cin.fail() || row < 1 || row > 8 || colLabel < 'a' || colLabel > 'h') {
                                   throw invalid_argument("Entrada invalida. Por favor, ingrese una fila (1-8) y una columna (a-h).");
                               }
                               col = colLabel - 'a';
                               row--;
                           } catch (const invalid_argument& e) {
                               cin.clear();
                               cin.ignore(10, '\n'); // Limpiar el buffer del cin en maximo 10 caracteres o hasta una nueva linea
                               cerr << "Error: " << e.what() << endl;
                               continue; // Volver al inicio del bucle y solicitar la entrada nuevamente
                           }
                if(!board.isValidMove(row,col,currentPlayerColor))
                    cout<<"El movimiento ingresado no es invalido, ingrese otro para el color "<<currentPlayerColor<<endl;

=======
                cout << "Ingrese la fila (1-8) y columna (a-h) separadas por espacio: "; // Cambiar las instrucciones para incluir letras
                cin >> row >> colLabel;
                col = colLabel - 'a'; // Convierte la letra en un índice de columna
                row--; // Convierte la fila de 1-8 a 0-7
>>>>>>> 0ce348b009a393a28378b742a7377da0d47c738d:Code/game.cpp
            } while (!board.isValidMove(row, col, currentPlayerColor));

            // Realizar el movimiento
            board.makeMove(row, col, currentPlayerColor);
        }

        // Cambiar al siguiente jugador
        if (currentPlayer == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }

        // Incrementar el contador de turnos
        turn++;


        // Verificar si el juego ha terminado
        if (turn > 60) {
            break;  // El tablero está lleno, el juego termina
        }
    }

    // Determinar al ganador
    Player winner = getWinner();
    cout << "Juego terminado." << endl;
    if (winner.getScore() > player1.getScore()) {
        cout << winner.getName() << " gana el juego con " << winner.getScore() << " fichas." << endl;
    } else if (winner.getScore() > player2.getScore()) {
        cout << winner.getName() << " gana el juego con " << winner.getScore() << " fichas." << endl;
    } else {
        cout << "¡Es un empate!" << endl;
    }
}


Player Game::getWinner() const {
    // Determina al ganador y retorna al jugador con más fichas al final del juego
    int player1Score = player1.getScore();
    int player2Score = player2.getScore();

    if (player1Score > player2Score) {
        return player1;
    } else if (player2Score > player1Score) {
        return player2;
    } else {
        return Player("Empate", ' ');
    }
}
