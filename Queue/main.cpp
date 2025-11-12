#include <iostream>
#include <string>
#include "queue.hpp"  // include your Queue class
#define NAME_LEN 50
using namespace std;
int main() {
    Queue buffet;   // create queue object
    int choice;
    char person[NAME_LEN];

    cout << "=== 🍽 Buffet Queue Simulation (FIFO) ===" << endl;

    do {
        cout << "\n1. Person joins the line (enqueue)" << endl;
        cout << "2. Serve next person (dequeue)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter initial letter of name: ";
                cin >> person;
                buffet.enqueue(person);
                cout << person << " joined the buffet line." << endl;
                break;

            case 2:
                buffet.dequeue();
                break;

            case 3:
                cout << "Buffet closed! Everyone served." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
