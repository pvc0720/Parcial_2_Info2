#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include "Player.h"

class HistoryManager {
public:
    HistoryManager();
    void recordResult(const Player& winner, const Player& loser);
    void printHistory() const;

private:
    std::string fileName;
};

#endif  // HISTORYMANAGER_H
