#include<stdio.h>

int main(){

    char v[3] = { 'a' , 'b' } ;
    printf("%c", v[2] ) ; // As v[2] not exists or is a null character so will not print

    for( int x = 1 ; x < 5 ; x++ ) {
        printf("CSIT = ") ;
        printf("%d ", x) ; // These two will be printed 4 times and when x = 4 the loop will continue from start and will not print the below lines i.e. print ( NED and x ) 
        if( x == 4 ) {
            continue ;
            printf("NED = ") ;
            printf("%d ", x) ;
        }
    }

    // int x = 5 ;
    // while ( x = 1 ) { // Since we have used the assignment operator instead of comparison so loop condition will always be TRUE an infinite loop will run but since there is nothing to print so you will not see something on terminal
    //     if ( x == 5 ) {
    //         printf("NED = ") ;
    //         printf("%d ", x) ;
    //     }
    //     // printf("Test") ; // Printed to check
    //     x++ ;
    // }

    // int x , j = 1 ;
    // for( x = 1 ; x < 5 ; x++ ) {
    //     j = j * x ;
    //     printf("%d ", j) ; // Since j is declared outside so it will have same value throughout the loop for 1st j = 1 then j = 2 ; j = 6 ; j = 24 
    // }

    // int x = 5 ;
    // printf("%d ", x++ ) ; // It will first print then increment i.e. 5 ( post increment ) 
    // printf("%d ", ++x ) ; // It will first increment then print i.e. 6 + 1 = 7 ( pre increment )
    // x = 9 ;
    // printf("%d ", ++x ) ; // It will first increment then print i.e. 9 + 1 = 10

    // int x ;
    // for ( x = 1 ; x < 5 ; ++x ) {
    //     printf("*") ;
    //     if( x = 5 ) // Since operator error here also so condition will always be TRUE only 1 star printed
    //         break;
    // }

    // int x = 1 ;
    // switch ( x ) { // Since break condition not used in each switch-case so all cases will be run whether TRUE or FALSE and at the end x will be equal to 5
    //     case 1 :
    //         x = x + 1 ;
    //     case 2 :
    //         x = x + 2 ;
    //     default :
    //         x = x + 1 ;
    // }
    // printf("%d ", x ) ;

    // int @bbbacus ; // Error variable name can't start with any special character except of underscore so anyprogram below it will not run
    // for ( int x = 1; x < 5 ; x++ ) {
    //     @bbbacus = @bbbacus * x ;
    // }
    // printf("%d ", @bbbacus ) ;

    return 0;
}