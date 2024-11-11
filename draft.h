
#ifndef M1OEP_NCKRAMER_DRAFT_H
#define M1OEP_NCKRAMER_DRAFT_H


#include <iostream>
#include <vector>
#include <memory>
#include "players.h"

class fantasyDraft {
private:

public:


    /*
     * Draft player
     * Requires: nothing
     * Modifies: list
     * Effects: Prompt user to draft a player. Once drafted, they leave the board and nobody else can draft them.
     */
    static int draftPlayer(vector<unique_ptr<Players>>& list);


    /*
     * Add to roster
     * Requires: playerIndex
     * Modifies: roster, list
     * Effects: Once a player is drafted, add them to your team and remove them from the big board
     */
    static void addToRoster(int playerIndex, vector<unique_ptr<Players>>& roster, vector<unique_ptr<Players>>& list);


    /*
     * Valid draft number
     * Requires: input
     * Modifies: nothing
     * Effects: Validates that number of drafters chosen is an int between 1 and 16
     */
    static bool validDraftNumber(string input);

    /*
     * Valid draft number
     * Requires: input
     * Modifies: nothing
     * Effects: Validates that the position being drafted is qb, rb or wr
     */
    static bool validPosition(string input);




    /*
     * Rank players
     * Requires: list
     * Modifies: nothing
     * Effects: prints a list of the five highest remaining players on the big board
     */
    static void rankPlayers(vector<unique_ptr<Players>>& list);
};



#endif //M1OEP_NCKRAMER_DRAFT_H
