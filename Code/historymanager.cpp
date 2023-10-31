#include "HistoryManager.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;


HistoryManager::HistoryManager() : fileName("othello_results.txt") {}

void HistoryManager::recordResult(const Player& winner, const Player& loser) {
    // Registra el resultado de la partida en el archivo de historial

    ofstream historyFile(fileName, ios::app); // Abre el archivo en modo de apertura para agregar al final

    if (historyFile.is_open()) {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        historyFile << "Fecha: " << localTime->tm_mday << "/" << localTime->tm_mon + 1 << "/" << localTime->tm_year + 1900 << " ";
        historyFile << "Hora: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
        historyFile << "Ganador: " << winner.getName() << " (" << winner.getColor() << ") con " << winner.getScore() << " fichas." << endl;
        historyFile << "Perdedor: " << loser.getName() << " (" << loser.getColor() << ") con " << loser.getScore() << " fichas." << endl;
        historyFile << "----------------------------------" << endl;

        historyFile.close();
    } else {
        cerr << "Error al abrir el archivo de historial." << endl;
    }
}

void HistoryManager::printHistory() const {
    // Imprime por pantalla el histórico de todas las partidas almacenadas en el archivo

    ifstream historyFile(fileName);

    if (historyFile.is_open()) {
        string line;
        while (getline(historyFile, line)) {
            cout << line <<endl;
        }
        historyFile.close();
    } else {
        cerr << "Error al abrir el archivo de historial." << endl;
    }
}
