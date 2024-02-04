#include <stdio.h>

int main() {
    int scores[5];
    int passed = 0;
    int failed = 0;
    float totalScore = 0;
    float average = 0;

    for (int i = 0; i < 5; i++) {
        printf("Enter score for course %d: ", i + 1);
        scanf("%d", &scores[i]);
        totalScore += scores[i];

        if (scores[i] >= 50) {
            passed++;
        } else {
            failed++;
        }
    }

    average = totalScore / 5;

    printf("Number of Passed Courses: %d\n", passed);
    printf("Number of Failed Courses: %d\n", failed);
    printf("Average Score: %.2f\n", average);

    return 0;
}
