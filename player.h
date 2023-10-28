#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name, char color);

    const std::string& getName() const;
    char getColor() const;
    int getScore() const;
    void incrementScore(int amount);

    // Operador de igualdad para comparar dos jugadores
    bool operator==(const Player& other) const {
        return this->name == other.name && this->color == other.color;
    }

private:
    std::string name;
    char color;
    int score;
};

#endif  // PLAYER_H
