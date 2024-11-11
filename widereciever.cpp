

#include "widereciever.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Constructors
Widerecievers::Widerecievers() {
    // set default values for the fields
    rank = -1;
    age = -1;
    games = -1;
    gamesStarted = -1;
    targets = -1;
    receptions = -1;
    yards = -1;
    touchdowns = -1;
    yardsPerTarget = -1;
    player = "INVALID";
    team = "INVALID";
    position = "INVALID";
}

int Widerecievers::getTargets() const {
    return targets;
}

int Widerecievers::getReceptions() const {
    return receptions;
}

int Widerecievers::getYards() const {
    return yards;
}

int Widerecievers::getTouchdowns() const {
    return touchdowns;
}

double Widerecievers::getYardsPerTarget() const {
    return yardsPerTarget;
}




void Widerecievers::setTargets(int targets) {
    this->targets = targets;
}

void Widerecievers::setReceptions(int receptions) {
    this->receptions = receptions;
}


void Widerecievers::setYards(int yards) {
    this->yards = yards;
}

void Widerecievers::setTouchdowns(int touchdowns) {
    this->touchdowns = touchdowns;
}

void Widerecievers::setYardsPerTarget(double yardsPerTarget) {
    this->yardsPerTarget = yardsPerTarget;
}




// Overload stream insertion operator
ostream &operator<<(ostream &outs, const Widerecievers &lec) {
    outs << lec.rank << std::endl;
    outs << lec.player << std::endl;
    outs << lec.age << std::endl;
    outs << lec.team << std::endl;
    outs << lec.position << std::endl;
    outs << lec.games << std::endl;
    outs << lec.gamesStarted << std::endl;
    outs << lec.targets << std::endl;
    outs << lec.receptions << std::endl;
    outs << lec.yards << std::endl;
    outs << lec.touchdowns << std::endl;
    outs << lec.yardsPerTarget << std::endl;
    outs << "Player Name: " << lec.player << ", Rank: " << lec.rank;
    return outs;

}




bool Widerecievers::loadFromFile(const string fn, vector<unique_ptr<Players>> &objs) {
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
    int rank, age, games, gamesStarted, targets, receptions, yards, touchdowns;
    string player, team, position;
    double yardsPerTarget;
    char comma, quote;

    // Read in data while the file is still good
    // and we haven't yet reached the end of file (EOF).
    int counter = 0;
    while (counter < 145) {
        // We initialize variables to sentinel values --
        // values we *know* will not appear in our data.
        // If any object fields have one of these values, we
        // *know* it was incorrectly set.
        rank = -1;
        age = -1;
        games = -1;
        gamesStarted = -1;
        targets = -1;
        receptions = -1;
        yards = -1;
        touchdowns = -1;
        yardsPerTarget = -1;
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
        fin >> targets;
        fin >> comma;
        fin >> receptions;
        fin >> comma;
        fin >> yards;
        fin >> comma;
        fin >> touchdowns;
        fin >> comma;
        fin >> yardsPerTarget;


        Widerecievers widereciever(rank, player, team, age, position, games, gamesStarted, targets, receptions, yards, touchdowns,
                                 yardsPerTarget);
        objs.push_back(make_unique<Widerecievers>(widereciever));
        counter += 1;


    }
    fin.close();
    return true;

}

