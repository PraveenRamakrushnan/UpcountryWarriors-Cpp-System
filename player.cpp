#include "player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Player {
    string id, firstName, lastName, dob;
    int runs;
};

void addPlayer() {
    Player p;
    cout << "\nEnter Player ID: ";
	while (true) {
    	getline(cin, p.id);
    	bool duplicate = false;
    	ifstream infile("data/players.txt");
    	string line;
    	while (getline(infile, line)) {
        	if (line.find("Player ID: ") == 0 && line.substr(11) == p.id) {
            	duplicate = true;
            	break;
        	}
    	}
    infile.close();
    if (duplicate) {
        cout << "Duplicate Player ID. Please enter a different ID: ";
    } else {
        break;
    }
}

    cout << "First Name: "; getline(cin, p.firstName);
    cout << "Last Name: "; getline(cin, p.lastName);
    cout << "Date of Birth (YYYY-MM-DD): ";
		while (true) {
    		getline(cin, p.dob);
    		if (p.dob.length() == 10 &&
        		isdigit(p.dob[0]) && isdigit(p.dob[1]) && isdigit(p.dob[2]) && isdigit(p.dob[3]) &&
        		p.dob[4] == '-' &&
        		isdigit(p.dob[5]) && isdigit(p.dob[6]) &&
        		p.dob[7] == '-' &&
        		isdigit(p.dob[8]) && isdigit(p.dob[9])) {
        		break;
    		} else {
        		cout << "Invalid format. Please enter date as YYYY-MM-DD: ";
    		}
		}

    cout << "Runs Scored: ";
		while (!(cin >> p.runs)) {
    		cout << "Invalid input. Please enter a number for runs: ";
    		cin.clear();           
    		cin.ignore(1000, '\n');     
		}


    ofstream file("data/players.txt", ios::app);
    if (file.is_open()) {
        file << "Player ID: " << p.id << endl;
        file << "First Name: " << p.firstName << endl;
        file << "Last Name: " << p.lastName << endl;
        file << "Date of Birth : " << p.dob << endl;
        file << "Runs Scored: " << p.runs << endl;
        file << endl;
        file.close();
        cout << "Player added successfully.\n";
    } else {
        cout << "Unable to open file to save player.\n";
    }
}

void displayPlayers() {
    ifstream file("data/players.txt");
    string line;
    if (file.is_open()) {
        cout << "\nRegistered Players:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open player file.\n";
    }
}

void searchPlayer() {
    string keyword;
    cout << "\nEnter player ID or name to search: ";
    cin.ignore();
    getline(cin, keyword);

    ifstream file("data/players.txt");
    string line;
    bool found = false;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(keyword) != string::npos) {
                cout << line << endl;
                found = true;
                for (int i = 0; i < 4; i++) {
                    if (getline(file, line)) cout << line << endl;
                }
                cout << endl;
            }
        }
        if (!found) cout << "No player found.\n";
        file.close();
    } else {
        cout << "Unable to open player file.\n";
    }
}

void deletePlayerById() {
    string id;
    cout << "Enter Player ID to delete: ";
    cin.ignore();
    getline(cin, id);

    ifstream in("data/players.txt");
    ofstream out("data/temp.txt");
    string line;
    bool found = false;
    int skipLines = 0;

    while (getline(in, line)) {
        if (skipLines > 0) {
            skipLines--;
            continue;
        }

        if (line.find("Player ID: ") == 0) {
            string currentId = line.substr(11);
            if (currentId == id) {
                found = true;
                skipLines = 5;
                continue;
            }
        }

        out << line << endl;
    }

    in.close();
    out.close();
    remove("data/players.txt");
    rename("data/temp.txt", "data/players.txt");

    if (found)
        cout << "Player deleted successfully.\n";
    else
        cout << "Player not found.\n";
}

