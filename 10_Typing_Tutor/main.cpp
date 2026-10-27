#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;

int main() {
    const string target = "Data structures and algorithms";
    cout << "Type this sentence exactly:\n" << target << "\n\nYour input: ";
    string typed;
    auto start = chrono::steady_clock::now();
    getline(cin >> ws, typed);
    auto end = chrono::steady_clock::now();
    double seconds = chrono::duration<double>(end - start).count();
    size_t correct = 0;
    for (size_t i = 0; i < min(target.size(), typed.size()); ++i)
        if (target[i] == typed[i]) ++correct;
    double accuracy = target.empty() ? 0 : 100.0 * correct / target.size();
    cout << fixed << setprecision(2)
         << "\nTime: " << seconds << " seconds\n"
         << "Matching character accuracy: " << accuracy << "%\n"
         << "Target length: " << target.size()
         << ", typed length: " << typed.size() << '\n';
    return 0;
}
