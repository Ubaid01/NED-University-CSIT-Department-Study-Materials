#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct address_t{
    int ww , xx , yy , zz ;
    char nickname[15] ;
} ;

void getData( struct address_t *address , int *totalIndices ) {
    int i ;
    char check[5] = "none" ;
    for(i = 0 ; i < 100 ; i++ ) {
        int checkIndex = 0 ; // Reinitialize for each loop 
        printf("Enter the four parts of the network address : ") ;
        scanf("%d %d %d %d", &address[i].ww, &address[i].xx, &address[i].yy, &address[i].zz ) ;
        if( address[i].ww == 0 || address[i].xx == 0 || address[i].yy == 0 || address[i].zz == 0 ) 
            checkIndex++ ;
        else if( address[i].ww < 0 || address[i].xx < 0 || address[i].yy < 0 || address[i].zz < 0 ) {
            printf("Invalid network address . Try Again!\n") ;
            i-- ;
            continue ;
        } 
        fflush(stdin) ;
        printf("Enter the nickname : ") ;
        scanf("%[^\n]s", address[i].nickname ) ;
        for(int j = 0 ; j < strlen( address[i].nickname ) ; j++ ) {
            if( address[i].nickname[j] == check[j] ) 
                checkIndex++ ;
            else 
                break ; // break only checking loop
        }

        if( checkIndex == ( strlen( address[i].nickname ) + 1 ) ) 
            break ;
    }
    *totalIndices = i + 1 ;
}

void printData( struct address_t Arr[] , int size ) {
    printf("Network Data stored is :\n") ;
    for(int i = 0 ; i < size ; i++) {
        printf("%d.%d.%d.%d", Arr[i].ww, Arr[i].xx, Arr[i].yy, Arr[i].zz ) ;
        printf("%15s\n", Arr[i].nickname ) ;
    }
}

void sameNetwork( struct address_t Arr[] , int size ) {
    for( int i = 0 ; i < size - 1; i++ ) {
        for( int j = i + 1 ; j < size ; j++ ) {
            if( Arr[i].ww == Arr[j].ww && Arr[i].xx == Arr[j].xx ) {
                printf("\n%s and %s are on the same network.", Arr[i].nickname, Arr[j].nickname ) ;
            }
        }
    }
}

int main(){
    struct address_t address[100] ;
    int totalIndices = 0 ;

    // // Precoded to check
    // address[0] = (struct address_t) { 111 , 22 , 3 , 44 , "greedy"} ;
    // address[1] = (struct address_t) { 555 , 66 , 7 , 88 , "bubblesort"} ;
    // address[2] = (struct address_t) { 111 , 22 , 5 , 66 , "bruteforce" } ;
    // address[3] = (struct address_t) { 0 , 0 , 0 , 0 , "none" } ;

    getData( address, &totalIndices ) ;
    // printf("%d\n\n", totalIndices ) ; // To check proper indices
    printData( address, totalIndices) ;
    sameNetwork( address , totalIndices ) ;
    return 0;
}