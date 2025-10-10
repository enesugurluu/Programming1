#include <stdio.h>

int main() {
    
    int a = 5, b = 10, c = 15, d = 23, e = 50;
    int avg = (a + b + c + d + e) / 5;

    printf("Average: %d\n", avg);


    int number = 7;
    if (number % 2 == 0) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }

    int grade;
    printf("Enter your score (0-100): ");

    scanf("%d", &grade);
    
    if (grade >= 90) {
        printf("Grade: A\n");
    } else if (grade >= 80) {
        printf("Grade: B\n");
    } else if (grade >= 70) {
        printf("Grade: C\n");
    } else if (grade >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }


    return 0;
}