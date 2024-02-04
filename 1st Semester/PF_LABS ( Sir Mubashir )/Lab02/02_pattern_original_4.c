#include <stdio.h>

int main() {
    int n = 9;  // Number of rows

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 3) {
                printf("*");
            } else if (i == 2 && (j == 2 || j == 3 || j == 4)) {
                printf("*");
            } else if (i == 3 && (j >= 1 && j <= 5)) {
                printf("*");
            } else if (i >= 4 && i <= 9 && j == 3) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
