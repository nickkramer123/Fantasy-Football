#ifndef DEBUGGING_QUARTERBACK_H
#define DEBUGGING_QUARTERBACK_H

#include "players.h"
#include <string>
#include <memory>

class Quarterbacks : public Players {

protected:



public:
    int yards, touchdowns;
    double completionPercentage;

    Quarterbacks();

    /*
     * Constructor
     * Requires: all variables in dataset
     * Modifies: nothing
     * Effects: Creates new value in Quarterbacks
     */
    Quarterbacks(int rank,
            string player,
            int age,
            string team,
            string position,
            int games,
            int gamesStarted,
            double completionPercentage,
            int yards,
            int touchdowns) {
        this->rank = rank;
        this->player = player;
        this->age = age;
        this->team = team;
        this->position = position;
        this->games = games;
        this->gamesStarted = gamesStarted;
        this->completionPercentage = completionPercentage;
        this->yards = yards;
        this->touchdowns = touchdowns;
    }




    double getCompletionPercentage() const;

    int getYards() const;

    int getTouchdowns() const;







    void setCompletionPercentage(double completionPercentage);

    void setYards(int yards);

    void setTouchdowns(int touchdowns);





    /*
     * load from file
     * Requires: nothing
     * Modifies: fn, objs
     * Effects: Loads in dataset from csv file and into vector
     */
    static bool qbLoadFromFile(const string fn, vector<unique_ptr<Players>> &objs);

};




#endif //DEBUGGING_QUARTERBACK_H
