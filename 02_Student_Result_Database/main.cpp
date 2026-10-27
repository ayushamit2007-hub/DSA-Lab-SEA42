#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int roll;
    string name;
    float m1, m2, m3;
    float total() const { return m1 + m2 + m3; }
    float percentage() const { return total() / 3.0f; }
};

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "\n1. Add student  2. Display all  3. Search by roll  0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            Student s{};
            cout << "Roll number: "; cin >> s.roll;
            cout << "Name (one word): "; cin >> s.name;
            cout << "Marks in 3 subjects (0-100): ";
            cin >> s.m1 >> s.m2 >> s.m3;
            if (!cin || s.m1 < 0 || s.m1 > 100 || s.m2 < 0 || s.m2 > 100 ||
                s.m3 < 0 || s.m3 > 100) {
                cout << "Invalid marks/input. Try again.\n";
                return 1;
            }
            students.push_back(s);
            cout << "Student added.\n";
        } else if (choice == 2) {
            if (students.empty()) cout << "No records available.\n";
            for (const auto& s : students)
                cout << "Roll: " << s.roll << " Name: " << s.name
                     << " Total: " << s.total() << "/300 Percentage: "
                     << fixed << setprecision(2) << s.percentage() << "%\n";
        } else if (choice == 3) {
            int roll; cout << "Enter roll number: "; cin >> roll;
            bool found = false;
            for (const auto& s : students) if (s.roll == roll) {
                cout << "Found: " << s.name << ", percentage "
                     << fixed << setprecision(2) << s.percentage() << "%\n";
                found = true; break;
            }
            if (!found) cout << "Student not found.\n";
        }
    } while (choice != 0);
    return 0;
}
