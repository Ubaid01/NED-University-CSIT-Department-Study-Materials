#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Spiral Traversal Number 

    // int num[4][4] = {   { 23 , 14 , 28 , 92 } , 
    //                     { 15 , 77 , 47 , 2 } , 
    //                     { 22 , 88 , 66 , 51} , 
    //                     {29 , 30 , 86 , 100 }  } ;   
    
    // for(int i = 0 ; i < 4 ; i++){
    //     for(int j = 0 ; j < 4 ; j++) {
    //         if( i % 2 == 0 ) 
    //             printf("%d ", num[i][j] ) ;
    //         else 
    //             printf("%d ", num[i][3-j] ) ;
    //     }
    //     printf("\n") ;
    // }

    // Random number deletion

    // int n ;
    // printf("Enter the size of array : ") ;
    // scanf("%d", &n) ;

    // int arr[n] ;
    // srand(time(NULL)) ;
    // for(int i = 0 ; i < n ; i++) {
    //     arr[i] = rand() % 10 ;
    //     printf("%d ", arr[i] ) ;
    // }

    // int index ;
    // printf("Enter the index to br remove : ") ;
    // scanf("%d", &index ) ;

    // for( int i = 0 ; i < n - 1 ; i++) {
    //     if( i >= index - 1 )
    //         arr[i] = arr[i + 1] ;
    // }
    // n-- ;
    // for( int i = 0 ; i < n; i++) {
    //     printf("%d ", arr[i] ) ;
    // }

    // Perfect Number

    // int num , sum = 0;
    // printf("Enter your number : ") ;
    // scanf("%d", &num ) ;

    // for(int i = 1 ; i < num ; i++) {
    //     if( num % i == 0 )
    //         sum += i ;
        
    //     if( sum == num ) 
    //         break ;
    // }

    // if( sum == num ) {
    //     sum = 0 ;
    //     printf("Perfect number facotrs are : ") ;
    //     for(int i = 1 ; i < num ; i++) {
    //         if( num % i == 0 ) {
    //             sum += i ;
    //             printf("%d ", i ) ;
    //         }
    //         if ( sum == num )
    //             break ;
    //     }
    //     printf("\nWhile Perfect Number = %d\n", num) ;
    // }
    // else 
    //     printf("%d is NOT a Perfect number . ", num ) ;
    
    printf("Perfect Numbers b/w (1-1000) are : ") ;
    for( int i = 1 ; i <= 1000 ; i++) {
        int sum = 0 ;
        for(int j = 1 ; j < i ; j++) {
            if( i % j == 0 ) {
                sum += j ;
            }
            if( sum == i ) {
                printf("%d ", i ) ;
                break ;
            }
        }
    }
    
    return 0;
}