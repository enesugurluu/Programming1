#include <stdio.h>

int main(void) {

    int day;
    printf("Enter day (1-7): ");
    scanf("%d", &day);

    switch (day)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid day\n");
        break;
    }



    char choice;
    printf("Enter your choose (Y/N): ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'Y':
        printf("You chose Yes\n");
        break;
    case 'N':
        printf("You chose No\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }


    if (choice == "Y" || choice == "y")
    {
        printf("You confirmed Yes\n");
    }else if (choice == "N" || choice == "n")
    {
        printf("You confirmed No\n");
    }

    int num1 = 10, num2 = 3, num3 = 100;
    int max;
    
    

    if (num1 > num2 && num1 > num3)
        max = num1;
    else if (num2 > num1 && num2 > num3)
        max = num2;
    else
        max = num3;
    

    printf("Max: %d\n", max);




    return 0;
}