#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Default Constructor
    Time() {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }

    // Parameterized Constructor
    Time(int h, int m, int s) {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    // Getter Functions
    int getHour() {
         return this->hour; }
    int getMinute() { 
        return this->minute; }
    int getSeconds() {
         return this->second; }

    // Setter Functions
    void setHour() {
        cout << "Enter hour: ";
        cin >> this->hour;
    }

    void setMinute() {
        cout << "Enter minute: ";
        cin >> this->minute;
    }

    void setSeconds() {
        cout << "Enter second: ";
        cin >> this->second;
    }

    // Print Time 
    void printTime() {
        cout << this->hour << ":" << this->minute << ":" << this->second << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of Time objects: ";
    cin >> n;

    // Dynamically allocate memory
    Time* times = new Time[n];

    // Input and Set Time
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Time " << endl;
        times[i].setHour();
        times[i].setMinute();
        times[i].setSeconds();
    }

    // Display Times
    cout << "Displaying Times:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Time " << ": ";
        times[i].printTime();
    }

    // Free memory
    delete[] times;
    times = nullptr;

    return 0;
}
