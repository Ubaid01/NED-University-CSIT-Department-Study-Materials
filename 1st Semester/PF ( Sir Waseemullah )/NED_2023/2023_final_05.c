#include<stdio.h>

void printMenu(void) {
    printf("\t\t  Operations Performer Menu :-\n");
    printf("\t\t================================\n") ;
    printf("\nEnter Options to proceed : \n") ;
    printf("1. Factorial Calculator :-\n") ;
    printf("2. Table Calculator :-\n") ;
    printf("3. Sentence Case Changer :-\n") ;
    printf("4. Star Pyramid Maker :-\n") ;
    printf("0. Exit :-\n") ;
}

long long fact(int n) {
    if (n == 0) 
        return 1 ;
    else        
        return n * fact(n - 1) ;
}

int main(){

    while( 1 ) {
        printMenu( );
        int choice ;
        printf("\nEnter your option : ") ;
        scanf("%d", &choice) ;
        switch(choice) {
            case 1 :
                printf("Enter your number : ") ;
                int num ;
                scanf("%d", &num) ;
                printf("\nFactorial of %d = %lld", num , fact(num) ) ;
                break ;
            
            case 2 :
                int start , end ;
                printf("Enter the start and end of the number you want to print table of : ") ;
                scanf("%d %d", &start, &end ) ;

                for( int i = start ; i <= end ; i++) {
                    printf("\nTable Of Number-%d : \n", i) ;
                    for(int j = 1 ; j <= 10 ; j++ ) {
                        printf("%d x %d = %d\n", i , j , i * j ) ;
                    }
                }
                break ;

            case 3 :
                while (getchar() != '\n');
                char sentence[100] ;
                printf("Enter your sentence : ") ;
                fgets( sentence, 100 , stdin ) ;  
                int i = 0 ;
                while( sentence[i] != '\0' ) {
                    if( sentence[i] >= 'a' && sentence[i] <= 'z' ) 
                        sentence[i] -= 32 ;
                    else if( sentence[i] >= 'A' && sentence[i] <= 'Z' ) 
                        sentence[i] += 32 ;

                    i++ ;
                }
                printf("\nChanged case sentence : %s", sentence ) ;
                break ;

            case 4 :
                int n ;
                printf("Enter the no.of rows of pyrmaid : ") ;
                scanf("%d", &n) ;

                for( int i = 0 ; i < n ; i++ ) {
                    for(int spaces = 0 ; spaces < n - i - 1; spaces++) {
                        printf("  ") ;
                    }

                    for(int stars = 0 ; stars < 2*i + 1 ; stars++) {
                        printf("* ") ;
                    }
                    printf("\n");
                }
                break ;

            case 0 :
                printf("\nThanks For using our product.\n") ;
                return 0 ;
        }
    }
    return 0;
}