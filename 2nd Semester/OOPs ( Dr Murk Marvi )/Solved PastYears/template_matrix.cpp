#include<iostream>
#include<vector>
#include<exception>
using namespace std ;

template<class T = int>
class Matrix {
    private:
    int row ;
    int col ;
    vector< vector<T> > arr ;

    public:
        Matrix( ) : row( 1 ) , col( 1 ) , arr( row , vector<T>( col ) ) { arr[0][0] = 0 ; }
        Matrix( int r , int c ) : row( r ) , col( c ) , arr( row , vector<T>( col ) ) { }

        void setMatrixElements( ) {
            T temp ;
            cout << "\nEnter matrix elements for :\nElement " ;
            for( int i = 0 ; i < arr.size() ; i++ ) {
                for( int j = 0 ; j < arr[i].size() ; j++ ) {
                    cout << "[" << i << "][" << j << "] : " ;
                    cin >> temp ;
                    arr[i][j] = temp ;
                }
            }
        }

        void display( ) {
            cout << "\n" ;
            for( int i = 0 ; i < arr.size() ; i++ ) {
                for( int j = 0 ; j < arr[i].size() ; j++ ) {
                    cout << "|" << arr[i][j] << "| " ;
                }
                cout << endl ;
            }
        }

        Matrix<T> operator*( const Matrix<T>& mat ) {
            if( col != mat.row ) 
            {
                throw runtime_error("Matrix multiplication failed.\n1st Matrix Columns and 2nd Matrix Rows must be same.") ;
            }
            Matrix<T> result( row , mat.col ) ;
            for( int i = 0 ; i < row ; i++ ) {
                for( int j = 0 ; j < mat.col ; j++ ) { 
                    result.arr[i][j] = 0 ;
                    for( int k = 0 ; k < col ; k++ ) {
                        result.arr[i][j] += arr[i][k] * mat.arr[k][j] ;
                    }
                }
            }
            return result ;
        }

        Matrix<T>& operator/=( const T& scalar ) {
            if( scalar == 0 )
                throw invalid_argument( "Division by zero leads to infinity!" );

            for( int i = 0 ; i < arr.size( ) ; i++ ) {
                for( int j = 0 ; j < arr[i].size( ) ; j++ ) {
                    this -> arr[i][j] /= scalar ;
                }
            }
            return *this ;
        }

        int determinant( ) {
            if( row != 2 || col != 2 )
                throw out_of_range( "Only 2x2 matrix determinants are supported." );

            int det = ( arr[0][0] * arr[1][1] ) - ( arr[0][1] * arr[1][0] ) ;
            return det ;
        }

        // ~Matrix() { 
        //     for( size_t i = 0 ; i < arr.size() ; i++ )
        //         arr[i].clear( ) ;
            
        //     arr.clear( ) ;
        // }
        ~Matrix( ) = default; // Can use default constructor here as vector will automatically handle its memory.

} ;

int main(){
    Matrix<> mat1( 2 , 2 ) , mat2( 2 , 1 );
    mat1.setMatrixElements( ) ;
    mat2.setMatrixElements( ) ;

    try {
        Matrix<> mat3 = mat1 * mat2 ; 
        mat3.display( ) ;
        Matrix< double > mat4( 2 , 2 ) ;
        mat4.setMatrixElements( ) ;
        mat4 /= 2 ;
        mat4.display( ) ;

        cout << "Determinant of mat4 = " << mat4.determinant( ) << endl ;
        
    }
    catch( const exception& e ) 
    {
        cout << e.what() << endl ;
    }
    return 0;
}