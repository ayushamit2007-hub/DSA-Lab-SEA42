#include <iostream>
#include <string>
using namespace std;

struct Node { char ch; Node* next; explicit Node(char c): ch(c), next(nullptr) {} };

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string line;
    cout << "Enter a line of text: ";
    getline(cin >> ws, line);
    for (char c : line) {
        Node* node = new Node(c);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    cout << "Text stored in linked list: ";
    for (Node* p = head; p; p = p->next) cout << p->ch;
    cout << "\nCharacter count: " << line.size() << '\n';
    while (head) { Node* temp = head; head = head->next; delete temp; }
    return 0;
}
