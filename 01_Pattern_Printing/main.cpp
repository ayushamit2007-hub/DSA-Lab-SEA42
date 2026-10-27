#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    if (!(cin >> n) || n < 1 || n > 50) {
        cout << "Please enter a row count from 1 to 50.\n";
        return 1;
    }
    cout << "\nRight triangle pattern:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << "* ";
        cout << '\n';
    }
    cout << "\nNumber triangle:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
