#include <iostream>
#include <vector>
using namespace std;

int n, r;
vector<vector<int>> maxm, alloc, need;
vector<int> avail;

void input() {
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> r;

    maxm.resize(n, vector<int>(r));
    alloc.resize(n, vector<int>(r));
    need.resize(n, vector<int>(r));
    avail.resize(r);

    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            cin >> maxm[i][j];

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            cin >> alloc[i][j];

    cout << "Enter Available Resources:\n";
    for (int j = 0; j < r; j++)
        cin >> avail[j];
}

void show() {
    cout << "\nProcess\tAllocation\tMax\t\tAvailable\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t";

        for (int j = 0; j < r; j++)
            cout << alloc[i][j] << " ";
        cout << "\t\t";

        for (int j = 0; j < r; j++)
            cout << maxm[i][j] << " ";
        cout << "\t\t";

        if (i == 0) {
            for (int j = 0; j < r; j++)
                cout << avail[j] << " ";
        }
        cout << endl;
    }
}

void deadlockDetection() {
    vector<bool> finish(n, false);
    vector<int> work = avail;
    vector<int> deadlock;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    bool flag = true;
    while (flag) {
        flag = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canExecute = true;

                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    for (int j = 0; j < r; j++)
                        work[j] += alloc[i][j];

                    finish[i] = true;
                    flag = true;
                }
            }
        }
    }

    // Check deadlock
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock.push_back(i);
        }
    }

    if (!deadlock.empty()) {
        cout << "\nSystem is in DEADLOCK.\nDeadlocked processes:\n";
        for (int i : deadlock)
            cout << "P" << i << " ";
    } else {
        cout << "\nSystem is NOT in deadlock (Safe State).\n";
    }
}

int main() {
    cout << "********** Deadlock Detection Algorithm **********\n";
    input();
    show();
    deadlockDetection();
    return 0;
}