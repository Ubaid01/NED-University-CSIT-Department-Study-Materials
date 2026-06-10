#include <iostream>
using namespace std;

int main() {
    int ms, ps, nop, np, rempages;
    int i, j, x, y, offset, pa;

    int s[10];           // pages required by each process
    int fno[10][20];     // frame numbers

    cout << "Enter the memory size -- ";
    cin >> ms;
    cout << "Enter the page size -- ";
    cin >> ps;

    nop = ms / ps;
    cout << "The no. of pages available in memory are -- " << nop << endl;

    cout << "Enter number of processes -- ";
    cin >> np;
    rempages = nop;
    for (i = 1; i <= np; i++) {
        cout << "Enter no. of pages required for p[" << i << "] -- ";
        cin >> s[i];

        if (s[i] > rempages) {
            cout << "Memory is Full" << endl;
            break;
        }
        rempages -= s[i];

        cout << "Enter pagetable for p[" << i << "] --- ";
        for (j = 0; j < s[i]; j++) {
            cin >> fno[i][j];
        }
    }

    cout << "Enter Logical Address to find Physical Address" << endl;
    cout << "Enter process no., page number and offset -- ";
    cin >> x >> y >> offset;

    if ( x > np || y >= s[x] || offset >= ps ) {
        cout << "Invalid Process or Page Number or offset" << endl;
    } 
    else {
        pa = fno[x][y] * ps + offset;
        cout << "The Physical Address is -- " << pa << endl;
    }

    return 0;
}