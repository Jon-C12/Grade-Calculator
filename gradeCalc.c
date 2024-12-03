#include <stdio.h>
#include <stdlib.h>

void gradeCalculation(int count, float *gradesArray, int customDivisor);

int main() {
    int numGrades;
    int customDivisor;

    // Prompt user to enter the number of grades
    printf("Enter the number of grades: ");
    scanf("%d", &numGrades);

    // Allocate memory for the grades array
    float *gradesArray = (float *)malloc(numGrades * sizeof(float));
    if (gradesArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input grades
    printf("Enter your grades in decimal value (e.g., 4.0, 5.5, etc):\n");
    for (int i = 0; i < numGrades; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%f", &gradesArray[i]);
    }

    // Input custom divisor
    printf("Enter the total potential points for average calculation: ");
    scanf("%d", &customDivisor);

    // Calculate and print results
    gradeCalculation(numGrades, gradesArray, customDivisor);

    // Free the allocated memory
    free(gradesArray);

    return 0;
}

void gradeCalculation(int count, float *gradesArray, int customDivisor) {
    float gradeTotal = 0.0;

    // Calculate the total of all grades
    for (int i = 0; i < count; i++) {
        gradeTotal += gradesArray[i];
    }

    // Calculate the average using the custom divisor
    float averageGrade = gradeTotal / customDivisor;

    // Print each grade with consistent formatting
    printf("Grades: ");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", gradesArray[i]);
    }
    printf("\n");

    // Print the total and average, ensuring precision consistency
    printf("The total is: %.2f\n", gradeTotal);
    printf("Your average (using divisor %d) is: %.2f\n", customDivisor, averageGrade);
}

