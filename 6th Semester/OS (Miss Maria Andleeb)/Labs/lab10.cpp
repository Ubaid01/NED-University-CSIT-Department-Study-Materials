#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void FCFS() {
    int t[20], n, i, tohm[20], tot = 0;
    float avhm;

    cout << "Enter the number of tracks: ";
    cin >> n;
    cout << "Enter the tracks to be traversed:\n";
    for (i = 0; i < n; i++)
        cin >> t[i];

    for (i = 0; i < n - 1; i++) {
        tohm[i] = abs(t[i + 1] - t[i]);
    }

    for (i = 0; i < n - 1; i++)
        tot += tohm[i];

    avhm = (float)tot / (n - 1);

    cout << "Tracks Traversed\tDifference\n";
    for (i = 0; i < n - 1; i++)
        cout << t[i] << " -> " << t[i + 1] << "\t\t" << tohm[i] << endl;

    cout << "Average head movement: " << avhm << endl;
}

void SSTF() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;

    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter request sequence:\n";
    for (i = 0; i < n; i++)
        cin >> RQ[i];

    cout << "Enter initial head position: ";
    cin >> initial;
    while (count != n) {
        int min = 1000, d, index = -1;

        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (d < min) {
                min = d;
                index = i;
            }
        }

        TotalHeadMoment += min;
        initial = RQ[index];
        RQ[index] = 1000; // mark as visited
        count++;
    }

    cout << "Total head movement: " << TotalHeadMoment << endl;
}

void SCAN() {
    int t[20], d[20], h, i, j, n, temp, k = 0, atr[20], sum = 0;

    cout << "Enter number of tracks: ";
    cin >> n;
    cout << "Enter initial head position: ";
    cin >> h;
    t[0] = 0;
    t[1] = h;

    cout << "Enter track requests:\n";
    for (i = 2; i < n + 2; i++)
        cin >> t[i];

    // // sorting
    // for (i = 0; i < n + 2; i++) {
    //     for (j = 0; j < n + 1 - i; j++) {
    //         if (t[j] > t[j + 1]) {
    //             temp = t[j];
    //             t[j] = t[j + 1];
    //             t[j + 1] = temp;
    //         }
    //     }
    // }
    sort(t, t + n + 2);

    // find head index
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }

    int p = 0;

    // move towards 0
    while (j >= 0) {
        atr[p++] = t[j];
        j--;
    }

    // then move to higher tracks
    for (j = k + 1; j < n + 2; j++)
        atr[p++] = t[j];

    // calculate movement
    for (i = 0; i < p - 1; i++) {
        d[i] = abs(atr[i + 1] - atr[i]);
        sum += d[i];
    }

    cout << "Average head movement: " << (float)sum / n << endl;
}

int main() {
    cout << "First Come First Serve" << endl;
    FCFS() ;
    cout << "\nShortest Seek Time First" << endl;
    SSTF() ;
    cout << "\nSCAN (Elevator Algorithm)" << endl;
    SCAN() ;
    return 0;
}