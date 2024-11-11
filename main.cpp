#include "players.h"
#include "quarterback.h"
#include "runningback.h"
#include "widereciever.h"
#include "draft.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>



// Load in dataset

int main() {
    class fantasyDraft draft;
    // read in datasets for each position
    vector<unique_ptr<Players>> quarterbacks;
    string fn = "../quarterbacks.csv";
    Quarterbacks::qbLoadFromFile(fn, quarterbacks);

    vector<unique_ptr<Players>> runningbacks;
    fn = "../runningbacks.csv";
    Runningbacks::rbLoadFromFile(fn, runningbacks);

    vector<unique_ptr<Players>> widerecievers;
    fn = "../widerecievers.csv";
    Widerecievers::loadFromFile(fn, widerecievers);





    int drafters;  // number of people drafting

    // ask how many people will be drafting, then validate
    bool validDraft = false;
    while (!validDraft) {
        cin.clear();
        cout << "Enter how many people will be drafting: " << endl;
        cin >> drafters;

        if (drafters >= 1 && drafters <= 16) {
            string draftersString = to_string(drafters);
            if (draft.validDraftNumber(draftersString)) {
                validDraft = true;
            }
            else {
                cout << "Invalid draft number. Please enter a number between 1 and 16." << endl;
            }
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),  '\n');
            cout << "Invalid draft number. Please enter a number between 1 and 16." << endl;
        }
    }


    // create rosters
    vector<vector<unique_ptr<Players>>> rosterList; // vector full of every roster
    for (int i = 0; i < drafters; i++) {
        rosterList.push_back(vector<unique_ptr<Players>>());
    }

    // clear cin so no logic errors occur
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Start the draft
    for (int p = 0; p < 5; p++) { // number of picks per round
        for (int d = 1; d <= drafters; d++) { // number of drafters
            string choice;
            cout << "Drafter number " << d << ", you are on the clock!" << endl;
            // figure out what position they would like to draft
            bool posPick = false;
            while (!posPick) {
                cout << "Pick your position - qb, rb, or wr: " << endl;
                cin >> choice;
                if (draft.validPosition(choice)) {
                    posPick = true;
                }
            }

            while (!draft.validPosition(choice)) {
                cout << "Pick your position - qb, rb, or wr: " << endl;
                cin >> choice;
            }

            if (choice == "qb") {
                draft.rankPlayers(quarterbacks);
                draft.addToRoster(draft.draftPlayer(quarterbacks), rosterList[d - 1],quarterbacks);
            }
            if (choice == "rb") {
                draft.rankPlayers(runningbacks);
                draft.addToRoster(draft.draftPlayer(runningbacks), rosterList[d - 1],runningbacks);
            }
            if (choice == "wr") {
                draft.rankPlayers(widerecievers);
                draft.addToRoster(draft.draftPlayer(widerecievers), rosterList[d - 1],widerecievers);
            }
        }
    }


    cout << "The draft is over!" << endl;
    // print results
    for (int d = 0; d < drafters; d++) {
        cout << "roster " << d + 1 << ":" << endl;
        for (const auto& player : rosterList[d]) {
            cout << player->getPlayer() << " (" << player->getPosition() << ")" << endl;
        }
    }

}

