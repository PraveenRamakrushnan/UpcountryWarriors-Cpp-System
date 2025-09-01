#include "team.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void manageTeams() {
    int option;
    cout << "1. Add New Team\nEnter option: ";
    cin >> option;
    cin.ignore();

    if (option == 1) {
    string teamName, playerID;
    cout << "Enter Team Name: ";
    cin >> teamName;
    ofstream file("data/teams.txt", ios::app);
    cout << "Enter Player IDs to add (enter 'done' to finish):\n";
    while (true) {
        cout << "Player ID: ";
        cin >> playerID;
        if (playerID == "done") break;
        file << teamName << "," << playerID << endl;
    }
    file.close();
        cout << "Team updated.";
    }else {
        cout << "Invalid option.";
    }
}

void editTeamDetails();

void viewTeamDetails() {
    ifstream file("data/teams.txt");
    string line;
    cout << "Team Details:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void deleteTeamByName() {
    string teamName;
    cout << "Enter Team Name to delete: ";
    cin.ignore();
    getline(cin, teamName);

    ifstream in("data/teams.txt");
    ofstream out("data/temp.txt");
    string line;
    bool found = false;

    while (getline(in, line)) {
        size_t comma = line.find(',');
        if (comma != string::npos && line.substr(0, comma) == teamName) {
            found = true;
            continue;
        }
        out << line << endl;
    }

    in.close();
    out.close();
    remove("data/teams.txt");
    rename("data/temp.txt", "data/teams.txt");

    if (found) cout << "Team deleted successfully.\n";
    else cout << "Team not found.\n";
}


