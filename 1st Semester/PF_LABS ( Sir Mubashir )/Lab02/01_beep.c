#include <stdio.h>
#include <windows.h>

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        // printf("\a");
        Beep(750, 300); // Beep at 750 Hz for 300 milliseconds(More better way)
        Sleep(500);     // Sleep for 500 milliseconds(0.5 seconds) between beeps
    }
    return 0;
}

// For Unix-Linux
// #include <stdio.h>
// #include <time.h>

// void sleep_ms(int milliseconds) {
//     struct timespec ts;
//     ts.tv_sec = milliseconds / 1000;
//     ts.tv_nsec = (milliseconds % 1000) * 1000000;
//     nanosleep(&ts, NULL);
// }

// int main() {
//     int i;
//     for (i = 0; i < 5; i++) {
//         printf("\a");    // Produces a terminal beep
//         sleep_ms(500);    // Sleep for 500 milliseconds between beeps
//     }
//     return 0;
// }
