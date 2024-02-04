#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void fillArray(int Arr[] , int size ) {
    srand( time( NULL ) ) ;
    for(int i = 0 ; i < size ; i++) 
        Arr[i] = ( rand( ) % 100 ) + 1 ; // Populate with random number b/w 1 to 100.
}

void printArray(int Arr[] , int size) {
    for( int i = 0 ; i < size ; i++ ) {
        printf("%d ", Arr[i] ) ;
    }
}

void sortArray(int *ptr , int size ) {

    for( int i = 0 ; i < size - 1 ; i++ ) {
        for( int j = i + 1 ; j < size ; j++ ) {
            if ( *( ptr + i ) > ptr[j] ) {
            // for (int j = 0; j < size - i - 1; j++) {
            // if (arr[j] > arr[j + 1]) {
            //     // Swap arr[j] and arr[j+1]
                int temp = *( ptr + i ) ;
                *( ptr + i ) = *( ptr + j ) ;
                *( ptr + j ) = temp ;
            }
        }
    }
}

int main(){
    int n ;
    printf("Enter the size of array : ") ;
    scanf("%d", &n ) ;  

    int *arr = (int *) malloc( n * sizeof( int ) ) ;

    fillArray(arr , n ) ;
    printf("\nBefore Sorting : ") ;
    printArray(arr , n ) ;

    sortArray(arr , n ) ;
    // qsort( arr , n , sizeof( int ) , compare ) ; // OR
    printf("\nAfter Sorting : ") ;
    printArray(arr , n ) ;
    free( arr ) ;
    return 0 ;
}