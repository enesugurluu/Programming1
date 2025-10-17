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
    
    
    return 0;
}