#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    char ch ;
    printf("Enter the type of matrix (I , S) : ") ;
    scanf("%c", &ch ) ;

    if( ch == 'I' || ch == 'i' ) {
        int n ;
        printf("Enter the size of the matrix n x n : ") ;
        scanf("%d", &n ) ;
        int arr[n][n] ;

        printf("The generated Identity matrix is displayed below : \n") ; 
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++) {
                if( i == j ) // Same row and column will have 1
                    arr[i][j] = 1 ;
                else
                    arr[i][j] = 0 ;
                printf("%d  ", arr[i][j] ) ;
            }
            printf("\n") ;
        }
    }
    else if ( ch == 'S' || ch == 's' ) {
        int m , n ;
        printf("Enter the size of the matrix m x n : ") ;
        scanf("%d %d", &m , &n ) ;
        int sparseMatrix[m][n];

    // Seed for random number generation
        srand(time(NULL));

        // Density factor: Adjust this to control the density of non-zero elements
        double density = 0.32;  // As 67% or above should be 0

        // Initialize the sparse matrix with zeros
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sparseMatrix[i][j] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rand() < RAND_MAX * density) {
                    // Assign a random non-zero value by gaining generating random number and comparing it with RAND_MAX * probability 
                    sparseMatrix[i][j] = rand() % 20 ;  
                }
            }
        }
        printf("Generated Sparse Matrix:\n");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d  ", sparseMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else 
        printf("Invalid Entry No Feature exists here\n") ;
    return 0;
}