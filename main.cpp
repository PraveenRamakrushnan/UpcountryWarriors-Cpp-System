#include <iostream>
#include <conio.h>
#include "auth.h"
#include "player.h"
#include "team.h"
using namespace std;

int main() {
    while (true) {
        if (!login()) continue;

    int choice;
    do {
        cout << "\n===== Upcountry Warriors Menu =====" << endl;
        cout << "1. Add Player\n2. Display Players\n3. Search Player" << endl;
        cout << "4. Manage Teams\n5. View Team Details\n6. Delete Player by ID\n7. Delete Team by Name\n8. Logout\n9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: displayPlayers(); break;
            case 3: searchPlayer(); break;
            case 4: manageTeams(); break;
            case 5: viewTeamDetails(); break;
            case 6: deletePlayerById(); break;
			case 7: deleteTeamByName(); break;
            case 8:
                logout();
                choice = 7;
                break;
            case 9:
                cout << "Exiting...";
                return 0;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 7);

    
    }
    return 0;
}

