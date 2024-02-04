#include <stdio.h>  // Include the header for printf
#include <math.h>   // Include the header for sqrt

// function to print circle pattern 
void printPattern(int radius) { 
  // dist represents distance to the center 
  float dist; 
  
  // for horizontal movement 
  for (int i = 0; i <= 2 * radius; i++) { 
    // for vertical movement 
    for (int j = 0; j <= 2 * radius; j++) { 
      dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius)); 
  
      // dist should be in the range (radius - 0.5) 
      // and (radius + 0.5) to print stars(*) 
      if (dist > radius - 0.5 && dist < radius + 0.5)  
        printf("*"); 
      else 
        printf(" ");       
    } 
    printf("\n"); 
  } 
} 
  
// Driver Code 
int main() { 
    int radius = 6;
    printPattern(radius);
    return 0;
}
