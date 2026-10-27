#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> requests;
    int choice;
    do {
        cout << "\n1. Add booking request  2. Process next request  3. Show count  0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            cout << "Passenger name (one word): "; cin >> name;
            requests.push(name);
            cout << "Request added to queue.\n";
        } else if (choice == 2) {
            if (requests.empty()) cout << "No booking requests waiting.\n";
            else { cout << "Processing booking for " << requests.front() << '\n'; requests.pop(); }
        } else if (choice == 3) {
            cout << "Waiting requests: " << requests.size() << '\n';
        }
    } while (choice != 0);
    return 0;
}
