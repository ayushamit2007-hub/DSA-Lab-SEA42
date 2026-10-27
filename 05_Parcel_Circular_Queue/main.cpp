#include <iostream>
#include <array>
#include <string>
using namespace std;

class ParcelQueue {
    static constexpr int CAP = 5;
    array<string, CAP> q{};
    int front = 0, rear = -1, count = 0;
public:
    void add(const string& id) {
        if (count == CAP) { cout << "Queue full. Cannot accept parcel.\n"; return; }
        rear = (rear + 1) % CAP; q[rear] = id; ++count;
        cout << "Parcel " << id << " added.\n";
    }
    void dispatch() {
        if (!count) { cout << "No parcels waiting.\n"; return; }
        cout << "Dispatched parcel: " << q[front] << '\n';
        front = (front + 1) % CAP; --count;
    }
    void display() const {
        if (!count) { cout << "Queue empty.\n"; return; }
        cout << "Waiting parcels: ";
        for (int i = 0; i < count; ++i) cout << q[(front + i) % CAP] << ' ';
        cout << '\n';
    }
};
int main() {
    ParcelQueue q; int ch; string id;
    do {
        cout << "\n1.Add parcel 2.Dispatch parcel 3.Display queue 0.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) { cout << "Parcel ID: "; cin >> id; q.add(id); }
        else if (ch == 2) q.dispatch();
        else if (ch == 3) q.display();
    } while (ch != 0);
}
