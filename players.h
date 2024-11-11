#ifndef M1OEP_NCKRAMER_PLAYERS_H
#define M1OEP_NCKRAMER_PLAYERS_H
using namespace std;


#include <iostream>
#include <vector>
#include <memory>

#include <iomanip>

class Players {


public:

    int rank, age, games, gamesStarted;
    string player, team, position;


    // Constructors
    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: Sets default values to all fields
     */
    Players();


    /*
     * getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns value for specific player
     */
    int getRank() const;

    string getPlayer() const;

    int getAge() const;

    string getTeam() const;

    string getPosition() const;

    int getGames() const;

    int getGamesStarted() const;



    /*
     * setters
     * Requires: nothing
     * Modifies: specific variable
     * Effects: changes value for specific player
     */
    void setRank(int rank);

    void setPlayer(string player);

    void setAge(int age);

    void setTeam(string team);

    void setPosition(int position);

    void setGames(int games);

    void setGamesStarted(int gamesStarted);



    /*
 * Overloaded operators
 * Requires: nothing
 * Modifies: nothing
 * Effects: Compares rank of two players
 */
    friend ostream &operator << (ostream &outs, const Players &lec);

    friend bool operator < (const Players& lhs, const Players& rhs);

    friend bool operator > (const Players& lhs, const Players& rhs);

    friend bool operator <= (const Players& lhs, const Players& rhs);

    friend bool operator >= (const Players& lhs, const Players& rhs);

    friend bool operator == (const Players& lhs, const Players& rhs);

};


#endif //M1OEP_NCKRAMER_PLAYERS_H
