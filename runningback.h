#ifndef DEBUGGING_RUNNINGBACK_H
#define DEBUGGING_RUNNINGBACK_H


#include "players.h"
#include <string>
#include <memory>


class Runningbacks : public Players {


public:
    int yards, touchdowns, attempts;
    double yardsPerAttempt;

    Runningbacks();

    /*
     * Constructor
     * Requires: all variables in dataset
     * Modifies: nothing
     * Effects: Creates new value in Quarterbacks
     */
    Runningbacks(int rank,
                 string player,
                 string team,
                 int age,
                 string position,
                 int games,
                 int gamesStarted,
                 int attempts,
                 int yards,
                 int touchdowns,
                 double yardsPerAttempt) {
        this->rank = rank;
        this->player = player;
        this->age = age;
        this->team = team;
        this->position = position;
        this->games = games;
        this->gamesStarted = gamesStarted;
        this->attempts = attempts;
        this->yards = yards;
        this->touchdowns = touchdowns;
        this->yardsPerAttempt = yardsPerAttempt;
    }


    int getAttempts() const;

    int getYards() const;

    int getTouchdowns() const;

    double getYardsPerAttempt() const;




    void setAttempts(int attempts);

    void setYards(int yards);

    void setTouchdowns(int touchdowns);

    void setYardsPerAttempts(double yardsPerAttempt);







    /*
     * load from file
     * Requires: nothing
     * Modifies: fn, objs
     * Effects: Loads in dataset from csv file and into vector
     */
    static bool rbLoadFromFile(const string fn, vector<unique_ptr<Players>> &objs);

};



#endif //DEBUGGING_RUNNINGBACK_H
