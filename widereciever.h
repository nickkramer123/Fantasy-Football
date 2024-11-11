#ifndef DEBUGGING_WIDERECIEVER_H
#define DEBUGGING_WIDERECIEVER_H


#include "players.h"
#include <string>
#include <memory>


class Widerecievers : public Players {

public:
    int targets, receptions, yards, touchdowns;
    double yardsPerTarget;

    Widerecievers();

    /*
     * Constructor
     * Requires: all variables in dataset
     * Modifies: nothing
     * Effects: Creates new value in Quarterbacks
     */
    Widerecievers(int rank,
                 string player,
                 string team,
                 int age,
                 string position,
                 int games,
                 int gamesStarted,
                 int targets,
                 int receptions,
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
        this->targets = targets;
        this->receptions = receptions;
        this->yards = yards;
        this->touchdowns = touchdowns;
        this->yardsPerTarget = yardsPerTarget;
    }


    int getTargets() const;

    int getReceptions() const;

    int getYards() const;

    int getTouchdowns() const;

    double getYardsPerTarget() const;




    void setTargets(int targets);

    void setReceptions(int receptions);

    void setYards(int yards);

    void setTouchdowns(int touchdowns);

    void setYardsPerTarget(double yardsPerTarget);





    /*
     * load from file
     * Requires: nothing
     * Modifies: fn, objs
     * Effects: Loads in dataset from csv file and into vector
     */
    static bool loadFromFile(const string fn, vector<unique_ptr<Players>> &objs);

};



#endif //DEBUGGING_WIDERECIEVER_H
