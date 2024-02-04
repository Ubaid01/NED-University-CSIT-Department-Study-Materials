// #include <stdio.h>

// int main() {
//     int height, width;
//     printf("Enter the height (in inches) of the bookcase: ");
//     scanf("%d", &height);
//     printf("Enter the width (in inches) of the bookcase: ");
//     scanf("%d", &width);

//     double widthInFeet = (double)width / 12.0;
//     double shelfMaterial = (2 * widthInFeet + 2 * height) * 12.0;
//    //feetNeeded = (2 * (height + width) + 24 * shelves) / 12.0;
//     double totalMaterial = shelfMaterial + (height * widthInFeet) * 12.0;

//     printf("Feet of 12-inch-wide boards needed: %.2f feet\n", totalMaterial);

//     return 0;
// }

#include <stdio.h>

int main() {
    // Constants
    const int boardWidth = 12;  // Width of each board in inches
    const int numShelves = 3;   // Number of shelves
    const int boardDepth = 12;  // Depth of the bookcase in inches

    // Input variables
    int heightInches, widthInches;

    // Prompt for user input
    printf("Enter the height of the bookcase in inches: ");
    scanf("%d", &heightInches);

    printf("Enter the width of the bookcase in inches: ");
    scanf("%d", &widthInches);

    // Calculate the number of boards needed for the back panel
    int backPanelHeight = heightInches - (2 * boardWidth); // Subtract the top and bottom panels
    int backPanelWidth = widthInches - (2 * boardWidth);   // Subtract the left and right panels

    // Calculate the area in square inches
    int backPanelArea = backPanelHeight * backPanelWidth;

    // Convert the area to square feet (12 inches = 1 foot)
    float backPanelSquareFeet = (float)backPanelArea / 144.0;

    // Calculate the number of boards for the shelves
    int shelfArea = numShelves * widthInches * boardDepth;

    // Convert the shelf area to square feet
    float shelfSquareFeet = (float)shelfArea / 144.0;

    // Calculate the total number of square feet of 12-inch-wide boards
    float totalSquareFeet = backPanelSquareFeet + shelfSquareFeet;

    // Print the result
    printf("Joe will need %.2f square feet of 12-inch-wide boards to complete the bookcase.\n", totalSquareFeet);

    return 0;
}