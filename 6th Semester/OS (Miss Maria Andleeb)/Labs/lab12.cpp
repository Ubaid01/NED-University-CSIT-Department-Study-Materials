#include <iostream>
using namespace std;

int main() {
    int b[20], l[20];
    int n, i;
    int segment, d;   // segment number and displacement
    int pa;

    cout << "Program for Segmentation\n";
    cout << "Enter the number of segments: ";
    cin >> n;

    cout << "Enter the base address and limit for each segment:\n";
    for (i = 0; i < n; i++) {
        cout << "Segment " << i << ":\n";
        cout << "Base: ";
        cin >> b[i];
        cout << "Limit: ";
        cin >> l[i];
    }

    cout << "Enter the segment number: ";
    cin >> segment;

    cout << "Enter the displacement: ";
    cin >> d;

    if (segment >= n) {
        cout << "Invalid segment\n";
    } 
    else if (d >= l[segment]) {
        cout << "Segment limit exceeded\n";
    } 
    else {
        pa = b[segment] + d;
        cout << "\nSegment\tBase\tPhysical Address\n";
        cout << segment << "\t" << b[segment] << "\t" << pa << endl;
    }

    return 0;
}