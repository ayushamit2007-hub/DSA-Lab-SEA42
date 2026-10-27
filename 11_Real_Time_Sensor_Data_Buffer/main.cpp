#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

class SensorBuffer {
    static constexpr int CAP = 8;
    array<double, CAP> data{};
    int next = 0, count = 0;
public:
    void add(double value) {
        data[next] = value;
        next = (next + 1) % CAP;
        if (count < CAP) ++count;
        cout << "Reading stored.\n";
    }
    void display() const {
        if (!count) { cout << "No readings yet.\n"; return; }
        cout << fixed << setprecision(2) << "Oldest-to-newest readings: ";
        int start = (next - count + CAP) % CAP;
        double sum = 0;
        for (int i = 0; i < count; ++i) {
            double v = data[(start + i) % CAP];
            cout << v << ' '; sum += v;
        }
        cout << "\nAverage: " << sum / count << '\n';
    }
};
int main() {
    SensorBuffer buffer; int ch;
    do {
        cout << "\n1.Add sensor reading 2.Display readings and average 0.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            double value; cout << "Sensor value: "; cin >> value;
            if (!cin) { cout << "Invalid input.\n"; return 1; }
            buffer.add(value);
        } else if (ch == 2) buffer.display();
    } while (ch != 0);
    return 0;
}
