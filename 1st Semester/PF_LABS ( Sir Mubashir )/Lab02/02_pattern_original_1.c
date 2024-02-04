// For Capital-N
// #include <stdio.h>

// int main() {
//     int n = 5;  // Number of rows

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (j == 1 || j == i || j == n) {
//                 printf("*");
//             } else {
//                 printf(" ");
//             }
//             if (j < n) {
//                 printf("    ");  // Adjust the number of spaces as needed
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }

#include <stdio.h>

int main() {
    int n = 5;  // Number of rows

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1 || (i > 1 && i < n && j == 3) || (i == ( n / 2 + 1 ) && j == n)) {
                printf("*");
            } 
            else {
                printf(" ");
            }

            if (j < n) { // Adds extra space to adjust as per requirement
                printf("    ");  // Adjust the number of spaces as needed
            }
        }
        printf("\n");
    }

    return 0;
}
