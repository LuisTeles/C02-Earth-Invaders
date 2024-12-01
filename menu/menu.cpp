#include <iostream>
using namespace std;

//here
void showMenu() {
    cout << "========== MENU ==========" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Exit" << endl;
    cout << "==========================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    while (true) { // Infinite loop to keep showing the menu
        showMenu();

        cin >> choice;

        if (cin.fail()) { 
            cin.clear(); // Clear the input error
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "You selected Option 1." << endl;
                break;
            case 2:
                cout << "You selected Option 2." << endl;
                break;
            case 3:
                cout << "You selected Option 3." << endl;
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please select a number between 1 and 4." << endl;
        }

        cout << endl; // Add a line break before redisplaying the menu
    }

    return 0;
}

