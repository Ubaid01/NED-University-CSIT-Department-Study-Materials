#include<stdio.h>

int main(){
    // int a = 8 , b = 13 , x = 0 , y = 10 ;
    // for( int k = --a ; k < b ; k++ ) { // 1st a will pe post-decremented to 7 and then k = 7
    //     x = x + k ; // here 0 + 7 = 7 => 
        // y = y - x-- ; // 10 - 7 = 3 but then x will pre-decremented to 6 , 3 till k = 13
    // }   
    // printf("x = %d, y = %d", x, y) ;

    // int x = 24 , y = 60 ;
    // while ( ( ( ( y - x ) ) ) % 5 != 0 ) { // It will continue doing will y - x is not a divisible of 5
    //     printf("x = %d, y = %d\n", x, y ) ;
    //     y = y - 7 ;
    // }

    int a = 0 ;
    printf("%u\n", &a ) ;
    char string[25] = "Programming Fundamentals" ;
    printf("%u\n", string) ;

    int nums[10] ;
    printf("%u  %u\n", &nums[0], &nums[3]) ;

    int num[7][50] ;
    for(int i = 0 ; i < 50 ; i++) {
        for(int j = 0 ; j < 7 ; j++) {
            num[j][i] = ( i * j ) + 1 ;
            // if(i == 36)
            //     printf("%d ", num[j][i]) ;
        }
    }
    // OR
    for(int i = 0 ; i < 7 ; i++) 
        printf("%d ", num[i][36] ) ;

    int A = 30 , B = 45 ;
    int *ptr = &A ;
    printf("\n%d ", (A < B) && !(A < B) ) ; // As here 1st condition is TRUE but second will always be FALSE as it is the reverse of it so AND will always result in FALSE (0)
    printf("Address of a = %u\n", ptr ) ;
    printf("Value of a = %d", *ptr ) ;


    return 0;
}