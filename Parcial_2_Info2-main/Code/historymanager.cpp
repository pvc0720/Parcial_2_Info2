#include "HistoryManager.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

HistoryManager::HistoryManager() : fileName("othello_results.txt") {}

void HistoryManager::recordResult(const Player& winner, const Player& loser) {
    // Registra el resultado de la partida en el archivo de historial

    FILE* historyFile = fopen(fileName.c_str(), "a"); // Abre el archivo en modo de apertura para agregar al final

    if (historyFile != NULL) {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        fprintf(historyFile, "Fecha: %d/%d/%d ", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        fprintf(historyFile, "Hora: %d:%d:%d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fprintf(historyFile, "Ganador: %s (%c) con %d fichas.\n", winner.getName().c_str(), winner.getColor(), winner.getScore());
        fprintf(historyFile, "Perdedor: %s (%c) con %d fichas.\n", loser.getName().c_str(), loser.getColor(), loser.getScore());
        fprintf(historyFile, "----------------------------------\n");

        fclose(historyFile);
    } else {
        cerr << "Error al abrir el archivo de historial." << endl;
    }
}

void HistoryManager::printHistory() const {
    // Imprime por pantalla el histórico de todas las partidas almacenadas en el archivo

    FILE* historyFile = fopen(fileName.c_str(), "r");

    if (historyFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), historyFile)) {
            cout << line;
        }
        fclose(historyFile);
    } else {
        cerr << "Error al abrir el archivo de historial." << endl;
    }
}
