#include<stdio.h>

int main(){
//     printf( "*\n**\n***\n****\n*****\n" );
//    for(int i=1; i<=4; i++){
//     for(int j=1; j<=i; j++){
//         printf("*");
//     }
//     printf("\n");
//    }

    // printf("*          \n");
    // printf("*    *     \n");
    // printf("*    *     *\n");
    // printf("*    *     \n");
    // printf("*          \n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(j==0 || j==8 || i==0 || i==8){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    // printf("*********\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*       *\n");
    // printf("*********\n");

    // printf("   ***    \n");
    // printf(" *     *  \n");
    // printf("*       * \n");
    // printf("*       * \n");
    // printf("*       * \n");
    // printf("*       * \n");
    // printf("*       * \n");
    // printf(" *     *  \n");
    // printf("   ***    \n");

    // printf("  *  \n");
    // printf(" ***  \n");
    // printf("*****\n");
    // printf("  *  \n");
    // printf("  *  \n");
    // printf("  *  \n");
    // printf("  *  \n");
    // printf("  *  \n");
    // printf("  *  \n");

    // printf("    *    \n");
    // printf("   * *   \n");
    // printf("  *   *  \n");
    // printf(" *     * \n");
    // printf("*       *\n");
    // printf(" *     * \n");
    // printf("  *   *  \n");
    // printf("   * *   \n");
    // printf("    *    \n");


    return 0;
}