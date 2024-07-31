#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

void displayClock(int hours, int minutes, int seconds) {
    cout << "Digital Clock: ";
    cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << endl;
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls"); // Clear screen on Windows
    #else
        std::system("clear"); // Clear screen on Unix-like systems
    #endif
}

int main() {
    int startHour, startMinute, startSecond;
    int endHour, endMinute, endSecond;

    cout << "Enter start time (HH:MM:SS): ";
    cin >> startHour;
    cin.ignore(); // Ignore the colon
    cin >> startMinute;
    cin.ignore(); // Ignore the colon
    cin >> startSecond;

    cout << "Enter end time (HH:MM:SS): ";
    cin >> endHour;
    cin.ignore(); // Ignore the colon
    cin >> endMinute;
    cin.ignore(); // Ignore the colon
    cin >> endSecond;

    if (startHour < 0 || startHour > 23 || startMinute < 0 || startMinute > 59 || startSecond < 0 || startSecond > 59 ||
        endHour < 0 || endHour > 23 || endMinute < 0 || endMinute > 59 || endSecond < 0 || endSecond > 59) {
        cout << "Invalid time input!" << endl;
        return 1; // Exit with an error code
    }

    // Calculate total seconds for start and end time
    int startTimeInSeconds = startHour * 3600 + startMinute * 60 + startSecond;
    int endTimeInSeconds = endHour * 3600 + endMinute * 60 + endSecond;

    // Display clock from start time to end time
    for (int currentTime = startTimeInSeconds; currentTime <= endTimeInSeconds; ++currentTime) {
        clearScreen( ) ;
        int hours = currentTime / 3600;
        int minutes = ( currentTime % 3600 ) / 60;
        int seconds = currentTime % 60;

        displayClock(hours, minutes, seconds);

        // Wait for one second before updating the clock
        this_thread::sleep_for( chrono::seconds(1) ) ;
    }
    Beep( 1500, 500 ) ; // Beep at 1500 Hz for 500 milliseconds

    return 0;
}
