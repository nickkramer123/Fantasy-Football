//
// Created by nflan on 9/25/2024.
//



#include "runningback.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


// Constructors
Runningbacks::Runningbacks() {
    // set default values for the fields
    rank = -1;
    age = -1;
    games = -1;
    gamesStarted = -1;
    attempts = -1;
    yards = -1;
    touchdowns = -1;
    yardsPerAttempt = -1;
    player = "INVALID";
    team = "INVALID";
    position = "INVALID";
}







int Runningbacks::getAttempts() const {
    return attempts;
}

int Runningbacks::getYards() const {
    return yards;

}

int Runningbacks::getTouchdowns() const {
    return touchdowns;
}

double Runningbacks::getYardsPerAttempt() const {
    return yardsPerAttempt;
}


void Runningbacks::setAttempts(int attempts) {
    this->attempts = attempts;
}

void Runningbacks::setYards(int yards) {
    this->yards = yards;
}

void Runningbacks::setTouchdowns(int touchdowns) {
    this->touchdowns = touchdowns;
}

void Runningbacks::setYardsPerAttempts(double yardsPerAttempt) {
    this->yardsPerAttempt = yardsPerAttempt;
}

/**
 * Overload stream insertion operator
 */
ostream &operator<<(ostream &outs, const Runningbacks &lec) {
    outs << lec.rank << std::endl;
    outs << lec.player << std::endl;
    outs << lec.age << std::endl;
    outs << lec.team << std::endl;
    outs << lec.position << std::endl;
    outs << lec.games << std::endl;
    outs << lec.gamesStarted << std::endl;
    outs << lec.attempts << std::endl;
    outs << lec.yards << std::endl;
    outs << lec.touchdowns << std::endl;
    outs << lec.yardsPerAttempt << std::endl;
    outs << "Player Name: " << lec.player << ", Rank: " << lec.rank;
    return outs;

}



bool Runningbacks::rbLoadFromFile(const string fn, vector<unique_ptr<Players>> &objs) {
    ifstream fin;
    fin.open(fn);

    if (!fin) {
        // Bad file / could not open
        return false;
    }

    // Opened file OK

    // Get rid of the header line
    string header = "";
    getline(fin, header);

    // Declare variables to be used inside the while loop
    int rank, age, games, gamesStarted, attempts, yards, touchdowns;
    string player, team, position;
    double yardsPerAttempt;
    char comma, quote;

    // Read in data while the file is still good
    // and we haven't yet reached the end of file (EOF).
    int counter = 0;
    while (counter < 80) {
        // We initialize variables to sentinel values --
        // values we *know* will not appear in our data.
        // If any object fields have one of these values, we
        // *know* it was incorrectly set.
        rank = -1;
        age = -1;
        games = -1;
        gamesStarted = -1;
        attempts = -1;
        yards = -1;
        touchdowns = -1;
        yardsPerAttempt = -1;
        player = "INVALID";
        team = "INVALID";
        position = "INVALID";
        comma = ',';

        fin >> rank;
        fin >> comma;
        if (fin.peek() == ' ') {
            fin >> quote;
            getline(fin, player, ' ');
            fin >> comma;
        } else {
            getline(fin, player, ',');
        }
        getline(fin, team, ',');
        fin >> age;
        fin >> comma;
        getline(fin, position, ',');
        fin >> games;
        fin >> comma;
        fin >> gamesStarted;
        fin >> comma;
        fin >> attempts;
        fin >> comma;
        fin >> yards;
        fin >> comma;
        fin >> touchdowns;
        fin >> comma;
        fin >> yardsPerAttempt;





        Runningbacks runningback(rank, player, team, age, position, games, gamesStarted, attempts, yards, touchdowns, yardsPerAttempt);
        objs.push_back(make_unique<Runningbacks>(runningback));
        counter += 1;


    }
    fin.close();
    return true;

}