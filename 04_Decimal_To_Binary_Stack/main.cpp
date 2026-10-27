#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long n;
    cout << "Enter a non-negative decimal integer: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid input. Enter a non-negative integer.\n";
        return 1;
    }
    if (n == 0) { cout << "Binary: 0\n"; return 0; }
    stack<int> bits;
    while (n > 0) { bits.push(static_cast<int>(n % 2)); n /= 2; }
    cout << "Binary: ";
    while (!bits.empty()) { cout << bits.top(); bits.pop(); }
    cout << '\n';
    return 0;
}
