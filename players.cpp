/**
 * Nicholas Kramer
 * CS 2300
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "players.h"
using namespace std;



    Players::Players() {
    }


    // Getters
    int Players::getRank() const {
        return rank;
    }

    string Players::getPlayer() const {
        return player;
    }

    int Players::getAge() const {
        return age;
    }

    string Players::getTeam() const {
        return team;
    }

    string Players::getPosition() const {
        return position;
    }

    int Players::getGames() const {
        return games;
    }

    int Players::getGamesStarted() const {
        return gamesStarted;
    }


    // Setters
    void Players::setRank(int rank) {
        this->rank = rank;
    }

    void Players::setPlayer(string player) {
        this->player = player;
    }

    void Players::setAge(int age) {
        this->age = age;
    }

    void Players::setTeam(string team) {
        this->team = team;
    }

    void Players::setPosition(int position) {
        this->position = position;
    }

    void Players::setGames(int games) {
        this->games = games;
    }


    void Players::setGamesStarted(int gamesStarted) {
        this->gamesStarted = gamesStarted;
    }

bool operator < (const Players& lhs, const Players& rhs) {
    return lhs.getRank() < rhs.getRank();
}

bool operator > (const Players& lhs, const Players& rhs) {
    return lhs.getRank() > rhs.getRank();
}

bool operator <= (const Players& lhs, const Players& rhs) {
    return lhs.getRank() <= rhs.getRank();
}

bool operator >= (const Players& lhs, const Players& rhs) {
    return lhs.getRank() >= rhs.getRank();
}

bool operator == (const Players& lhs, const Players& rhs) {
    return lhs.getRank() == rhs.getRank();
}
