#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

void tweakStatus( int arr[] , int len , int index ) {

    for( int i = 0; i < len; i++ ) { // Question was to modify array[0] by the index number and decrement the previous arr[0] by 1 and exchange at that index
        if ( i == index ) {
            if( arr[ index] < 0  )
                arr[index] = 0 ;

            int temp = arr[0] ;
            arr[0] = arr[index] ;
            arr[index] =  temp - 1 ; 
        }
    }

    printf("[ ") ;
    for( int i = 0; i < len; i++ ) {
        if( i == len - 1 )
            printf("%d ]\n", arr[i] ) ;
        else 
            printf("%d ", arr[i] ) ;
    }
}

int main(){
    // // Orders Question
    // int n ;
    // printf("Enter number orders : ") ;
    // scanf("%d", &n ) ;

    // if( n > 0 ) {
    //     double orders[n] , sum = 0 ; 
    //     for( int i = 0 ; i < n ; i++ ) {
    //         printf("Price of %d-Item (in $): " , i + 1 ) ;
    //         scanf("%lf", &orders[i] ) ;
    //         sum += orders[i] ;
    //     }  

    //     if( sum < 200 ) {
    //         printf("Total order cost = %.2lf", sum + ( n * 10 ) ) ; // Shipping cose included
    //     }
    //     else 
    //         printf("Total order cost = %.2lf", sum ) ;
    // }
    // else 
    //     printf("Invalid number!") ;


    // // Right Triangle & Digit Question
    // double side1, side2, side3 ;
    // printf("For Triangle:\n") ;
    // printf("Enter the length of side1 : ") ;
    // scanf("%lf", &side1 ) ;
    // printf("Enter the length of side2 : ") ;
    // scanf("%lf", &side2 ) ;
    // printf("Enter the length of side3 : ") ;
    // scanf("%lf", &side3 ) ;

    // if ((pow( side1 , 2 ) == pow( side2 , 2 ) + pow( side3 , 2 ) ) ||
    //     (pow( side2 , 2 ) == pow( side1 , 2) + pow( side3 , 2 ) ) ||
    //     (pow( side3 , 2 ) == pow( side1 , 2) + pow( side2 , 2 ) ) )
    //     printf("Given Triangle is a Right Angled triangle.\n");
    // else 
    //     printf("Given Triangle is NOT a Right Angled triangle.\n") ;

    // // Character detection using switch
    // char ch ;
    // printf("Enter any character : ") ;
    // scanf("%c", &ch ) ;

    // // switch(tolower( ch ) ) {
    //     switch( ch ) {
    //     case '0' ... '9' :
    //         printf("You entered a digit.\n") ;
    //         break ;
    //     case 'a' ... 'z' :
    //     case 'A' ... 'Z' : // OR can use OR operator in switch like this one 
    //         printf("You entered an alphabet.\n") ;
    //         break ;
    //     // case 'A' ... 'Z' : // You have to retype same statement again as OR-operator is not allowed in switch cases
    //     //     printf("You entered an alphabet.\n") ;
    //         break ;
    //     default :
    //         printf("You entered a special character.\n") ;
    //         break ;
    // }

    int N , sum = 0 ;
    printf("Enter the size of Array : ") ;
    scanf("%d", &N ) ;

    if( N < 1 || N > 100000 ) {
        printf("Errored index size.Returning...\n") ;
        return 1 ;
    }
    // srand( time(0) ) ;
    int A[N] , check = -1 ;

    for(int i = 0 ; i < N ; i++) {
        printf("Enter Element[%d] : ", i + 1 ) ;
        scanf("%d", &A[i] ) ;
        sum += A[i] ;
        // A[i] = rand() % ( N + 5 ) ;
        if( A[0] == 0 ) 
            i-- ;
    }
    
    if( sum > 200000 ) {
        printf("Unbounded Numbers given as input. Returning....\n") ;
        return 1 ; 
    }
    
    printf("The game starts now : \n") ;
    while( A[0] != 0 ) {
        int num ;
        if( check == -1 ) {
            printf("Ahmed Turn : enter the index i of the array you have selected : ") ;
            scanf("%d", &num ) ;
            if( num < N && num >= 0 ) {
                check = 0 ;
                tweakStatus( A  , N , num ) ;
            }
            else 
                printf("Incorrect-Index.Try Again !\n") ;
        }
        else if ( check == 0 ) {
            printf("Ali Turn : enter the index i of the array you have selected : ") ;
            scanf("%d", &num ) ;
            if( num < N && num > 0 ) {
                check = -1 ;
                tweakStatus( A  , N , num ) ;
            }
            else 
                printf("Incorrect-Index.Try Again !\n") ;
        }
    }
    if( check == 0 )
        printf("The game is over since a[0] = 0 and the winner is Ahmed.") ;
    else 
        printf("The game is over since a[0] = 0 and the winner is Ali.") ;

    return 0;
}