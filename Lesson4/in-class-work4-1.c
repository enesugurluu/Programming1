#include <stdio.h>

int main(void) {
     /* Compute class average: read count, read grades, compute average */

     int studentsNumber = 10; /* default, overwritten by input */
     int counter = 1;         /* loop counter from 1..studentsNumber */
     int currentStudentGrade; /* each student's grade (0-100 expected) */
     float classAverage = 0;  /* accumulator (float for fractional average) */

     printf("Enter the all student numbers...: ");
     scanf("%d", &studentsNumber);

     /* One-time validation: prompt again if non-positive (no loop) */
     if (studentsNumber <= 0) {
          printf("Enter the valid all student number..: ");
          scanf("%d", &studentsNumber);
     }

     while (studentsNumber >= counter) {
          printf("Please, enter the student grade value..:");
          scanf("%d", &currentStudentGrade);

          /* Note: condition below is always false; likely should use || */
          if (currentStudentGrade > 100 && currentStudentGrade < 0) {
               printf("Please, enter the valid grade value..:");
               scanf("%d", &currentStudentGrade);
          }

          classAverage = classAverage + currentStudentGrade;
          counter++;
     }

     /* Compute average (watch out for divide-by-zero if studentsNumber == 0) */
     classAverage = classAverage / studentsNumber;

     printf("The class average is %f", classAverage);

     return 0;
}