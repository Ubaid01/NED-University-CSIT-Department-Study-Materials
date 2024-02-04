#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double stringToNum(char *str) {
    double num = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    else if ( str[0] == '+' ) { // If mistakenlt + also given
        sign = 1;
        i = 1 ;
    }

    int decimalPosition = -1; // Track the position of the decimal point
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') 
            num = num * 10 + (str[i] - '0');
        else if (str[i] == '.' && decimalPosition == -1) 
            decimalPosition = i; // Set the position of the decimal point
        else 
            break;
        i++;
    }

    // Adjust the result if a decimal point was encountered
    if (decimalPosition != -1) {
        int exponent = i - decimalPosition - 1; // At which index decimal is encountered move to that by dividing by 10 power
        num /= pow(10, exponent);
    }

    return num * sign;
}

int main() {
    char n1[100], n2[100], op;
    printf("Enter the arithmetic operation to perform with operator (e.g., 3 * 5): ");
    scanf("%s %c %s", n1, &op, n2);

    switch (op) {
        case '+':
            printf("\nThe sum of given two numbers is %.3lf", stringToNum(n1) + stringToNum(n2) );
            break;
        case '-':
            printf("\nThe difference of given two numbers is %.3lf", stringToNum(n1) - stringToNum(n2) );
            break;
        case '*':
            printf("\nThe product of given two numbers is %.3lf", stringToNum(n1) * stringToNum(n2) );
            break;
        case '/':
            printf("\nThe division of given two numbers is %.3lf", stringToNum(n1) / stringToNum(n2) );
            break;
        default:
            printf("\nWrong Operator given !");
            break;
    }

    return 0;
}