#include <stdio.h>

/* lesson5.c
   Count how many students passed and failed (10 students total).
*/

int main(void) {
    
    int passes = 0;        // number of passes
    int failures = 0;      // number of failures
    int studentCounter = 1; // current student number (1..10)
    int pass_or_fail;      // input: 1 = pass, 0 = fail

    /* loop over 10 students and collect results */
    while (studentCounter <= 10)
    {
        printf("Enter result (1=pass, 0=fail): ");
        scanf("%d", &pass_or_fail);

        if (pass_or_fail == 1)
            passes++;        // increment pass count
        else if (pass_or_fail == 0)
            failures++;      // increment failure count
        else
        {
            printf("Invalid input. Please enter 1 for pass or 0 for fail.\n");
            continue; // do not advance studentCounter on invalid input
        }
        
        studentCounter++; // move to next student
    }
    
    /* summary output */
    printf("Passed: %d\n", passes);
    printf("Failed: %d\n", failures);

    return 0;
}