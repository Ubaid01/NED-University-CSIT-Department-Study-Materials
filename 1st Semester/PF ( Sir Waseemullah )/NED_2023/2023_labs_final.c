// #include<stdio.h>

// int main() {
//     int arr[5][3] = { { 2, 0, 2 } ,
//                       { 4, 5, 6 } ,   
//                       { 2, 0, 2 } ,   
//                       { 4, 5, 6 } ,   
//                       { 1, 0, 3 }  } ;

//     printf("Same Row Numbers are : ") ;
    
//     int total_count = 0 ;
//     for(int i = 0 ; i < 4 ; i++) {   // This loop run till one row less
//         int checks = 0 , j = 0, row_iterate = i + 1 ;
//         while( j < 3 && row_iterate < 5 ) {  // This loop runs both rows and columns to check all the same rows.
//             if( arr[i][j] == arr[ row_iterate ][ j ] ) {  // If equal to check
//                 checks++ ;
//             }
//             else {   // Else start column loop and check from 0 but increment row_iterate.
//                 j = checks =  0 ;
//                 row_iterate++ ;
//             }
//             j++ ;  // Then increase the column number.
//         }
//         if( checks >= 2 ) {
//             printf("%d and %d ,", i + 1, row_iterate + 1 ) ;
//             total_count++ ;
//         }
//     }

//     printf("\n%d Rows are same.", total_count ) ;
//     return 0;
// }

#include<stdio.h>

int main(){
    int arr[4][5] = { { 2, 3, 5, 3, 2 }, 
                      { 2, 0, 0, 2, 1 } ,
                      { 4, 3, 6, 0, 2 } ,
                      { 1, 0, 5, 3, 0 } , } ;

    int total_count = 0 ;
    for(int i = 0 ; i < 4 ; i ++ ) {
        int count = 0 ;
        for(int j = 0 ; j < 5 ; j ++ ) { 
            if( arr[i][j] == 0 )
                count++ ;
        }
        if( count == 2 ){
            printf("%d ", i + 1 ) ;
            total_count++ ;
        }
    }

    printf("Rows Numbers contain two zeros.\nTotal = %d", total_count ) ;
    return 0;
}