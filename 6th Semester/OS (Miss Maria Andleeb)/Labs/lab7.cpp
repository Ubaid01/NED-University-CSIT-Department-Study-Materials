#include <iostream>
using namespace std;

#define N 4

int completedPhilo = 0;

struct Fork {
    int taken;
} ForkAvail[N];

struct Philosopher {
    int left;
    int right;
} PhiloStatus[N];

void goForDinner(int philID) {

    if (PhiloStatus[philID].left == 10 && PhiloStatus[philID].right == 10) {
        cout << "Philosopher " << philID + 1 << " already completed dinner\n";
    }

    else if (PhiloStatus[philID].left == 1 && PhiloStatus[philID].right == 1) {
        cout << "Philosopher " << philID + 1 << " completed dinner\n";

        PhiloStatus[philID].left = 10;
        PhiloStatus[philID].right = 10;

        int otherFork = philID - 1;
        if (otherFork == -1)
            otherFork = N - 1;

        ForkAvail[philID].taken = 0;
        ForkAvail[otherFork].taken = 0;

        cout << "Philosopher " << philID + 1
             << " released fork " << philID + 1
             << " and fork " << otherFork + 1 << endl;

        completedPhilo++;
    }

    else if (PhiloStatus[philID].left == 1 && PhiloStatus[philID].right == 0) {

        if (philID == N - 1) {
            if (ForkAvail[philID].taken == 0) {
                ForkAvail[philID].taken = 1;
                PhiloStatus[philID].right = 1;

                cout << "Fork " << philID + 1
                     << " taken by philosopher " << philID + 1 << endl;
            } else {
                cout << "Philosopher " << philID + 1
                     << " is waiting for fork " << philID + 1 << endl;
            }
        } else {
            int tempID = philID;
            int leftFork = philID - 1;

            if (leftFork == -1)
                leftFork = N - 1;

            if (ForkAvail[leftFork].taken == 0) {
                ForkAvail[leftFork].taken = 1;
                PhiloStatus[tempID].right = 1;

                cout << "Fork " << leftFork + 1
                     << " taken by Philosopher " << tempID + 1 << endl;
            } else {
                cout << "Philosopher " << tempID + 1
                     << " is waiting for Fork " << leftFork + 1 << endl;
            }
        }
    }

    else if (PhiloStatus[philID].left == 0) {

        if (philID == N - 1) {
            if (ForkAvail[philID - 1].taken == 0) {
                ForkAvail[philID - 1].taken = 1;
                PhiloStatus[philID].left = 1;

                cout << "Fork " << philID
                     << " taken by philosopher " << philID + 1 << endl;
            } else {
                cout << "Philosopher " << philID + 1
                     << " is waiting for fork " << philID << endl;
            }
        } else {
            if (ForkAvail[philID].taken == 0) {
                ForkAvail[philID].taken = 1;
                PhiloStatus[philID].left = 1;

                cout << "Fork " << philID + 1
                     << " taken by Philosopher " << philID + 1 << endl;
            } else {
                cout << "Philosopher " << philID + 1
                     << " is waiting for Fork " << philID + 1 << endl;
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        ForkAvail[i].taken = 0;
        PhiloStatus[i].left = 0;
        PhiloStatus[i].right = 0;
    }

    while (completedPhilo < N) {
        for (int i = 0; i < N; i++) {
            goForDinner(i);
        }

        cout << "\nTill now number of philosophers completed dinner: "
             << completedPhilo << "\n\n";
    }
    return 0;
}