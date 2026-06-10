#include <iostream>
#include <vector>
using namespace std;

int main() {
    int processes, resources;
    cout << "\nEnter number of processes: ";
    cin >> processes;
    cout << "Enter number of resources: ";
    cin >> resources;

    vector<vector<int>> current(processes, vector<int>(resources));
    vector<vector<int>> maximum_claim(processes, vector<int>(resources));
    vector<int> available(resources);
    vector<int> maxres(resources);
    vector<int> allocation(resources, 0);
    vector<bool> running(processes, true);

    // Input Claim Vector
    cout << "\nEnter Claim Vector:\n";
    for (int i = 0; i < resources; i++) {
        cin >> maxres[i];
    }

    // Input Allocated Resource Table
    cout << "\nEnter Allocated Resource Table:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> current[i][j];
        }
    }

    // Input Maximum Claim Table
    cout << "\nEnter Maximum Claim Table:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> maximum_claim[i][j];
        }
    }

    // Display Claim Vector
    cout << "\nThe Claim Vector is:\n";
    for (int i = 0; i < resources; i++) {
        cout << maxres[i] << "\t";
    }

    // Display Allocation Table
    cout << "\n\nThe Allocated Resource Table:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cout << current[i][j] << "\t";
        }
        cout << endl;
    }

    // Display Maximum Claim Table
    cout << "\nThe Maximum Claim Table:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cout << maximum_claim[i][j] << "\t";
        }
        cout << endl;
    }

    // Calculate allocated resources
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            allocation[j] += current[i][j];
        }
    }

    cout << "\nAllocated resources:\n";
    for (int i = 0; i < resources; i++) {
        cout << allocation[i] << "\t";
    }

    // Calculate available resources
    for (int i = 0; i < resources; i++) {
        available[i] = maxres[i] - allocation[i];
    }

    cout << "\nAvailable resources:\n";
    for (int i = 0; i < resources; i++) {
        cout << available[i] << "\t";
    }
    cout << endl;

    int counter = processes;
    // Banker's Algorithm Safety Check
    while (counter != 0) {
        bool safe = false;

        for (int i = 0; i < processes; i++) {
            if (running[i]) {
                bool exec = true;

                for (int j = 0; j < resources; j++) {
                    if ((maximum_claim[i][j] - current[i][j]) > available[j]) {
                        exec = false;
                        break;
                    }
                }

                if (exec) {
                    cout << "\nProcess " << i + 1 << " is executing\n";
                    running[i] = false;
                    counter--;
                    safe = true;

                    for (int j = 0; j < resources; j++) {
                        available[j] += current[i][j];
                    }

                    break;
                }
            }
        }

        if (!safe) {
            cout << "\nThe processes are in an unsafe state.\n";
            break;
        } else {
            cout << "System is in safe state.\nAvailable vector: ";
            for (int i = 0; i < resources; i++) {
                cout << available[i] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}