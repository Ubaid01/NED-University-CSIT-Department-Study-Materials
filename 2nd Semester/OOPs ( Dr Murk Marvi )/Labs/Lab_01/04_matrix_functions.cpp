#include<iostream>
using namespace std ;

void addMatrices( int rows , int cols , double **arr1, double **arr2 , double **temp ) { 
    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            temp[i][j] = 0 ; // 1st initialize individual elements with 0 then add to avoid any garbage return.
            temp[i][j] += arr1[i][j] + arr2[i][j] ;
        }
    }
}

void multiplyMatrices( int rows1 , int cols2 , double **arr1 , double **arr2 , double **temp ) {
    for( int i = 0 ; i < rows1 ; i++ ) {
        for( int j = 0 ; j < cols2 ; j++ ) {
            temp[i][j] = 0 ;

            for( int k = 0 ; k < rows1 ; k++ ) {
                temp[i][j] += arr1[i][k] * arr2[k][j] ;
            }
        }
    }
}

int main(){
    int r1 , c1 , r2 , c2 ;
    cout << "Enter no.of rows and columns of Matrix 1 : " ;
    cin >> r1 >> c1 ;
    cout << "Enter no.of rows and columns of Matrix 2 : " ;
    cin >> r2 >> c2 ;

    // Dynamically allocate memory for both matrices
    double **mat1 = new double *[r1] ; // Allocate memory for all rows
    double **mat2 = new double *[r2] ; 

    for ( int i = 0 ; i < r1 ; i++ ) {
        mat1[i] = new double[c1] ; // For columns in ech row
    }

    for ( int i = 0 ; i < r2 ; i++ ) {
        mat2[i] = new double[c2] ;
    }

    cout << "Enter elements of matrix 1:\n";
    for ( int i = 0 ; i < r1 ; i++ ) {
        for ( int j = 0 ; j < c1 ; j++ ) {
            cout << "Element[" << i + 1 << "][" << j + 1 << "] : " ;
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of matrix 2:\n";
    for ( int i = 0 ; i < r2 ; i++ ) {
        for  (int j = 0 ; j < c2 ; j++ ) {
            cout << "Element[" << i + 1 << "][" << j + 1 << "] : " ;
            cin >> mat2[i][j];
        }
    }

    if( r1 != r2 || c1 != c2 )
        cout << "Addition not possible as matrices are not of same order." << endl ;
    else {
        double **addMat = new double *[r1] ;

        for( int i = 0 ; i < r1 ; i++ ) {
            addMat[i] = new double [c1] ;
        }

        addMatrices( r1 , c1 , mat1 , mat2 , addMat ) ;

        cout << "\nAddition of matrices :\n" ;
        for( int i = 0 ; i < r1 ; i++ ) {
            for( int j = 0 ; j < c1 ; j++ ) {
                cout << "| "<< addMat[i][j] << " |" ; 
            }
            cout << endl ;
        }

        for( int i = 0 ; i < r1 ; i++ ) {
            delete[] addMat[i] ;
        }
        delete[] addMat ;
    }

    if( c1 != r2 ) 
        cout << "Multiplication not possible as column of 1st matrix is not equal to row of 2nd matrix.";
    else {
        // Now the order of multiplication matrix will be equal to the remaining order i.e. 1st matrix rows x 2nd matrix columns
        double **mulMat = new double *[r1] ;

        for( int i = 0 ; i < r1 ; i++ ) {
            mulMat[i] = new double [c2] ;
        }

        multiplyMatrices( r1 , c2 , mat1 , mat2 , mulMat ) ;

        cout << "\nMultiplication of matrices :\n" ;
        for( int i = 0 ; i < r1 ; i++ ) {
            for( int j = 0 ; j < c2 ; j++ ) {
                cout << "| " << mulMat[i][j] << " |" ; 
            }
            cout << endl ;
        }

        for( int i = 0 ; i < r1 ; i++ ) {
            delete[] mulMat[i] ;
        }
        delete[] mulMat ;
    }

    for ( int i = 0 ; i < r1 ; i++ ) {
        delete[] mat1[i] ;
    }
    for ( int i = 0 ; i < r2 ; i++ ) {
        delete[] mat2[i] ;
    }
    delete[] mat1 ; 
    delete[] mat2 ; 

    return 0;
}