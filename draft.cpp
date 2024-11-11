#include "players.h"
#include "draft.h"
#include <iostream>
#include <string>
#include <cmath>
#include <memory>
using namespace std;


int fantasyDraft::draftPlayer(vector<unique_ptr<Players>>& list) {
    string playerName; // name of player being input
    int playerIndex = -1; // index of player on list
    bool playerInList = false;

    // make sure playerName is in file
    while (!playerInList) {
        cout << "Enter the name of the player you would like to draft: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, playerName);
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getPlayer() == playerName) {
                playerInList = true;
                playerIndex = i;
                break;
            }
        }
        if (!playerInList) {
            cout << "Invalid option" << endl;
        }
    }
    cout << "You have drafted " << playerName << endl;
    return playerIndex;
}

void fantasyDraft::addToRoster(int playerIndex, vector<unique_ptr<Players>>& roster, vector<unique_ptr<Players>>& list) {
    roster.push_back(move(list[playerIndex]));
    list.erase(list.begin() + playerIndex);
}

bool fantasyDraft::validDraftNumber(string input) {
    int num;
    stringstream ssfinal;

    // if the input is empty, set to false
    if (input.empty()) {
        return false;
    }
    // for every character in input
    for (int i = 0; i < input.length(); i++) {
        stringstream ss;
        ss << input[i];
        // if iterator[i] is not an integer, reset for loop and ask again for input
        if (!(ss >> num)) {
            cin.clear();
            return false;
        }
    }
    // output result
    return true;
}

bool fantasyDraft::validPosition(string input) {
    if (input != "qb" && input != "rb" && input != "wr") {
        cout << "Invalid input!" << endl;
        cin.clear();
        return false;
    }
    // allow input
    return true;
}




// rank_players
void fantasyDraft::rankPlayers(vector<unique_ptr<Players>>& list) {
    cout << "On the board:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << list[i]->getRank() << ". " << list[i]->getPlayer() << endl;
    }
}












