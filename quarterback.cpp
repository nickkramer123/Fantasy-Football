

#include "quarterback.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


// Constructors
Quarterbacks::Quarterbacks() {
    // set default values for the fields
    rank = -1;
    age = -1;
    games = -1;
    gamesStarted = -1;
    completionPercentage = -1;
    yards = -1;
    touchdowns = -1;
    player = "INVALID";
    team = "INVALID";
    position = "INVALID";
}







double Quarterbacks::getCompletionPercentage() const {
    return completionPercentage;
}

int Quarterbacks::getYards() const {
    return yards;

}

int Quarterbacks::getTouchdowns() const {
    return touchdowns;
}



void Quarterbacks::setCompletionPercentage(double completionPercentage) {
    this->completionPercentage = completionPercentage;
}

void Quarterbacks::setYards(int yards) {
    this->yards = yards;
}


void Quarterbacks::setTouchdowns(int touchdowns) {
    this->touchdowns = touchdowns;
}



/**
 * Overload stream insertion operator
 */
ostream &operator<<(ostream &outs, const Quarterbacks &lec) {
    outs << lec.rank << std::endl;
    outs << lec.player << std::endl;
    outs << lec.age << std::endl;
    outs << lec.team << std::endl;
    outs << lec.position << std::endl;
    outs << lec.games << std::endl;
    outs << lec.gamesStarted << std::endl;
    outs << lec.completionPercentage << std::endl;
    outs << lec.yards << std::endl;
    outs << lec.touchdowns << std::endl;
    outs << "Player Name: " << lec.player << ", Rank: " << lec.rank;
    return outs;

}

bool Quarterbacks::qbLoadFromFile(const string fn, vector<unique_ptr<Players>> &objs) {
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
    int rank, age, games, gamesStarted, yards, touchdowns;
    double completionPercentage;
    string player, team, position;
    char comma, quote;

    // Read in data while the file is still good
    // and we haven't yet reached the end of file (EOF).
    int counter = 0;
    while (counter < 75) {
        // We initialize variables to sentinel values --
        // values we *know* will not appear in our data.
        // If any object fields have one of these values, we
        // *know* it was incorrectly set.
        rank = -1;
        age = -1;
        games = -1;
        gamesStarted = -1;
        completionPercentage = -1;
        yards = -1;
        touchdowns = -1;
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
        fin >> age;
        fin >> comma;
        getline(fin, team, ',');
        getline(fin, position, ',');
        fin >> games;
        fin >> comma;
        fin >> gamesStarted;
        fin >> comma;
        fin >> completionPercentage;
        fin >> comma;
        fin >> yards;
        fin >> comma;
        fin >> touchdowns;




        Quarterbacks quarterback(rank, player, age, team, position, games, gamesStarted, completionPercentage, yards, touchdowns);
        objs.push_back(make_unique<Quarterbacks>(quarterback));
        counter += 1;


    }
    fin.close();
    return true;

}


