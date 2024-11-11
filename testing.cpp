#include "players.h"
#include "quarterback.h"
#include "runningback.h"
#include "widereciever.h"
#include "draft.h"
#include <iostream>
#include <vector>
using namespace std;


bool testFantasyDraft();


int main() {
    if (testFantasyDraft()) {
        cout << "Passed all test cases" << endl;
    }
    return 0;
}

bool testFantasyDraft() {
    bool passed = true;

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

    if (quarterbacks.size() != 75) {
        cout << "FAILED test case qb size" << endl;
        passed = false;
    }

    if (runningbacks.size() != 80) {
        cout << "FAILED test case rb size" << endl;
        passed = false;
    }

    if (widerecievers.size() != 145) {
        cout << "FAILED test case wr size" << endl;
        passed = false;
    }

    for (const auto& player : quarterbacks) {
        if (player->getPlayer() == "INVALID") {
            cout << "FAILED test case qb name" << endl;
            passed = false;
        }
    }


    for (const auto& player : runningbacks) {
        if (player->getPlayer() == "INVALID") {
            cout << "FAILED test case rb name" << endl;
            passed = false;
        }
    }

    for (const auto& player : widerecievers) {
        if (player->getPlayer() == "INVALID") {
            cout << "FAILED test case wr name" << endl;
            passed = false;
        }
    }


    if (!draft.validDraftNumber("100")) {
        cout << "FAILED valid draft number false" << endl;
        passed = false;
    }

    if (draft.validDraftNumber("abc")) {
        cout << "FAILED valid draft number true" << endl;
        passed = false;
    }

    if (!draft.validPosition("qb")) {
        cout << "FAILED test valid position true" << endl;
        passed = false;
    }

    if (draft.validPosition("invalid input")) {
        cout << "FAILED test case valid position false" << endl;
        passed = false;
    }



    return passed;





}