// For Capital-X
// #include <stdio.h>

// int main() {
//     int n = 5;  // Number of rows

//     for (int i = 1; i <= 2 * n - 1; i++) {
//         for (int j = 1; j <= 2 * n - 1; j++) {
//             if (i == j || i + j == 2 * n) {
//                 printf("*");
//             } else {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }

// C Program To Print Hollow Diamond
// Pattern using for loop
#include <stdio.h>
int main()
{

	int n = 5, rows, columns;

	// for loop is used to identify
	// the number of rows and
	// it is used to print upper triangle
	for (rows = 1; rows <= n; rows++) {

		// used for printing the spaces
		for (columns = n; columns > rows; columns--) {
			printf(" ");
		}

		// print star
		printf("*");

		// again print the spaces
		for (columns = 1; columns < (rows - 1) * 2;
			columns++) {
			printf(" ");
		}
		if (rows == 1) {
			printf("\n");
		}
		else {
			printf("*\n");
		}
	}
	// for loop is used to identify
	// the number of rows and
	// it is used to print lower triangle
	for (rows = n - 1; rows >= 1; rows--) {

		// used for printing the spaces
		for (columns = n; columns > rows; columns--) {
			printf(" ");
		}

		// print star
		printf("*");
		for (columns = 1; columns < (rows - 1) * 2;
			columns++) {
			printf(" ");
		}
		if (rows == 1) {
			printf("\n");
		}
		else {
			printf("*\n");
		}
	}
	return 0;
}
