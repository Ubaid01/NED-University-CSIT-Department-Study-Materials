#include<stdio.h>

// #define CUBE(x) x * x * x 

int addmult(int a, int b) {
    int w , z ;
    w = a + b ;
    z = a * b ;
    return( w , z ) ; // return statement can only return single thing at a time but it will not show error as 1st thing from right will be returned and all other will be evaluated but not return as neglected by compiler. If want to retrun both use pointers instead
}

int main(){

    // int y[4] = { 6 , 7 , 8 , 9 } ;
    // int *ptr = y + 2 ;
    // printf("%d ", ptr[1] ) ; // This prints the value at the index 1 of the array starting from the address pointed by ptr. Since ptr is pointing to the third element of the array (y + 2), ptr[1] refers to the element at the index 1 of the array starting from the third element, which is the fourth element of the original array ( y[3] ).

    // int x = 5 , y = 10 ;
    // int const *p = &x ;
    // // *p = 1 ; // Since we have used constant integer to store pointer value so it can't be modified.
    // printf("%d ",*p ) ; 

    // float *b , *c ,a = 13.5 ;
    // b = &a , c = b ; // Assume thay &a = 9FE3
    // printf("\n%p %p %p", &a , b , c ) ; // %p represents address in hexa-decimal and since we have given the pointer 'b' address of a then the same 'b' value(not address) is given to c so both b and c will point to same address i.e. address of 'a' (9FE3)
    // printf("\n%f %f %f %f", a , *(&a) , *b , *c ) ; // Therefore there values will also be same

    // int sum ;
    // sum = 2 + 5 / 2 + 6 * 2 ; // Since operator precendence of * and / is greater so first they will be solved individually at the same time due to associativity(same precendence and from left to right)
    // printf("%d", sum ) ; // First 5 / 2 = 2.5 in int (2) and 6 * 2 = 12 Lastly 2 + 2 + 12 = 16

    // int ans ;
    // ans = 216 / CUBE( 3 ) ; // Since macros at the time of decoding are converted into their respective whole code and instruction are performed i.e. 216 / 3 * 3 * 3 => Now solve it from left to right associativity i.e. 72 * 9 = 648
    // printf("%d" , ans ) ;

    // int arri[] = { 1 , 2 , 3 } ;
    // int *ptri = arri ;
    // char arrc[] = { 1 , 2 , 3 } ;
    // char *ptrc = arrc ;
    // printf("sizeof arri[] = %d\n", sizeof(arri) ) ; // Since a single integer takes 4 bytes of memory in 64xbits so 4 * 3 = 12 will be printed
    // printf("sizeof ptri[] = %d\n", sizeof(ptri) ) ; // Since we have only given 1 address to ptri i.e. the base address of array ( arri[0] ) as a pointer so in 32-bit compiler pointer-size is 4 bytes while in 64-byte compiler it is 8 bytes so hence it will print 8
    // printf("sizeof arrc[] = %d\n", sizeof(arrc) ) ; // For single char storage 1 byte so 3 * 1 = 3 will be printed
    // printf("sizeof ptrc[] = %zu\n", sizeof(ptrc) ) ; // 1 character address stored as pointer which means as an address so will print 8 here and %zu operator is used to print the address using size_t structure mostly

    // // static int val ; // Since static is pre-initialized to 0 so will print 3 and if const used with val so will give error as unmodifiable variable
    // int val ; // Since nothing given so garbage collection
    // do { // do-while will run atleast one time irrespective of while condition so 3 will be added in it at the time of condition checking and since garabge is most like to be greater than 25 so infinite loop will run till range of integer i.e. -2147483645 is reached and will print this
    //     val++ ;
    //     ++val ;
    // }while( val++ > 25 ) ;
    // printf("%d ", val ) ;

    // int CONTINUE = 0;
    // if ( CONTINUE = 5 ) // Here assignment operator is used instead of comparison operator so condition will always be TRUE and Success will be printed
    //     printf("Success.") ;
    // else
    //     printf("Failure.") ;

    // int i = 3 , j = 4 , k , n ;
    // k = addmult( i , j ) ; // k will only have w so i * j = 12
    // n = addmult( j , k ) ; // n will have j * k i.e. 4 * 12 = 48
    // printf("%d  %d", k , n ) ;

    int array[10] = { 3 , 0 , 8 , 1 , 12 , 8 , 9 , 2 , 13 , 10 } ;
    int x , y , z ;
    x = ++array[2] ; // Here by uniary operator we are directly modifying the value of array[2] also and assigning at the same time to x so x = ++8 = 9 and array[2] will now equal to 9 also 
    y = array[2]++ ; // First 9 will be assigned to y then array[2] will increment to 10
    z = array[x++] ; // It will first use the value of x as index in array i.e. z = array[9] = 10 and at the same time now x will be post incremented to 10
    printf("%d  %d  %d", x , y , z ) ; // So it will print 10  9  10

    return 0;
}