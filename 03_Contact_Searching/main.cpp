#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Contact { string name, phone; };

int main() {
    vector<Contact> contacts = {
        {"Aarav", "9000000001"}, {"Isha", "9000000002"},
        {"Karan", "9000000003"}, {"Meera", "9000000004"}
    };
    sort(contacts.begin(), contacts.end(),
         [](const Contact& a, const Contact& b) { return a.name < b.name; });
    string key;
    cout << "Enter contact name to search: ";
    cin >> key;
    auto it = lower_bound(contacts.begin(), contacts.end(), key,
        [](const Contact& c, const string& name) { return c.name < name; });
    if (it != contacts.end() && it->name == key)
        cout << "Contact found: " << it->name << " — " << it->phone << '\n';
    else
        cout << "Contact not found.\n";
    cout << "\nAvailable sample contacts:\n";
    for (const auto& c : contacts) cout << c.name << '\n';
    return 0;
}
