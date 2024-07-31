#include<iostream>
using namespace std ;

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

unsigned long long binomialCoeff(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r)); // Use Combinations nCr = n! / r!(n - r)!
}

void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << binomialCoeff(i, j) << " ";
        }
        cout << endl;
    }
}

int main(){
    int n ;
    cout << "Enter no.of Rows : " ;
    cin >> n ;

    // int row, spaces, column ;
    // for(row = 0; row < n; row++){
    //     for(spaces = n - row; spaces >= 1; spaces--){
    //         cout << " " ;
    //     }

    //     int printChar = 1;
    //     int numerator = row;
    //     int denominator = 1;

    //     for(column = 0; column<= row ; column++){ // Since in row = 0 combination is 0C0
    //         cout << " " << printChar ;
    //         printChar = printChar * numerator;
    //         printChar = printChar / denominator;
    //         numerator --;
    //         denominator ++;
    //     }

    //     cout << endl ;
    // }

    printPascalTriangle( n ) ;
    return 0;
}