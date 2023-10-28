#include "Player.h"
using namespace std;

Player::Player(const string& name, char color) : name(name), color(color), score(2) {}

const string& Player::getName() const {
    return name;
}

char Player::getColor() const {
    return color;
}

int Player::getScore() const {
    return score;
}

void Player::incrementScore(int amount) {
    score += amount;
}
