#include<stdio.h>

// struct Element {
//     int value ;
// } ;

// void recurseOp( struct Element arr[][3], int  rows, int cols, int i, int j ) {
//     if( i < rows ) {
//         if( j < cols ) {
//             printf("%d ", arr[i][j] ) ; // So first 1 printed then 2 , 3, space 4, 5, 6 end
//             recurseOp(arr, rows, cols, i, j + 1) ;
//         }
//         else {
//             printf("\n") ;
//             recurseOp(arr, rows, cols, i + 1, 0) ;
//         }
//     } // end if ( i < rows )
// }

int main(){
    // struct Element arr[2][3] = {
    //                            { { 1 }, { 2 } , { 3 } } ,
    //                             {  { 4 }, { 5 } , { 6 }  } } ;
    // recurseOp(arr, 2, 3, 0, 0 ) ;

    // int arr1[] = { 1, 2, 3, 10 } ;
    // int arr2[] = { 4, 5, 6 , 11 } ;
    // int arr3[] = { 7, 8, 9 , 12 } ;

    // int *ptrArr[] = { arr1, arr2, arr3 } ; // It means it is a 2D_Array

    // printf("Original Array : \n") ;
    // for(int i = 0; i < 3; ++i) {
    //     for(int j = 0; j < 4; ++j) {
    //         printf("%d ", ptrArr[i][j] );
    //     }
    //     printf("\n");
    // }

    // for(int i = 0; i < 3; ++i) {
    //     int *start = ptrArr[i] ; // Points to ptrArr[i][0]
    //     int *end = ptrArr[i] + 2 ; // Points to ptrArr[i][0] + 2 (Wrong) Now it will refer to ptrArr[i][2]
    //     while ( start < end ) { // So for 1st start = 1, end = 3 hence 3 and 1 swapped since it loops in rows only so only i and i + 2 index will be swapped.
    //         int temp = *start ;
    //         *start = *end ;
    //         *end = temp ;
    //         start++ ; end-- ;
    //     }
    // }

    // printf("Modified: \n") ;
    // for(int i = 0; i < 3; ++i) {
    //     for(int j = 0; j < 4; ++j) {
    //     printf("%d ", ptrArr[i][j] ); // All 1st and ends swapped 3 2 1 6 5 4 9 8 7
    //     }
    //     printf("\n") ;
    // }

    int i, j, k, n = 7 ;

    for( i = 0; i < n; i++ ){
        for( j = 0; j <= n - i; j++ ) // For first 8 spaces 8 , 7, till 1
            printf("  ") ;

        for( k = 0; k <= i; k++) // for first i also 0 so 65 = 'A' printed
            printf("%c ", 64 + k + 1) ;

        for(j = i; j > 0; j--) // for first j = 0 so nothing executed
            printf("%c ", 64 + j) ;
        printf("\n") ;
    }
    return 0;
}