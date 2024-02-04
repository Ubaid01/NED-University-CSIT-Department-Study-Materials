#include <stdio.h>
#include <math.h>

int main() {
    int reportLength = 140;
    int attendees = 25;
    int copies = attendees + 5;
    int sheetsNeeded = reportLength * copies;
    int reamsNeeded = ceil((double)sheetsNeeded / 500);

    printf("Reams of paper needed: %d\n", reamsNeeded);

    return 0;
}
