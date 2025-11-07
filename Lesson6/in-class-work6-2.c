#include <stdio.h>

int main() {
    int entered_second;
    printf("Enter a second for converting  : ");
    scanf("%d", &entered_second);

    while(entered_second < 0)
    {
        printf("Please enter valid second for converting  : ");
        scanf("%d", &entered_second);
    }
    

    int sec_per_min = 60;
    int min_per_hour = 60;
    int sec_per_hour = min_per_hour * sec_per_min;


    int hour = entered_second / sec_per_hour;

    int minute = (entered_second - (hour * sec_per_hour)) / sec_per_min;

    int seconds = (entered_second - (hour * sec_per_hour) - (minute * sec_per_min))  % sec_per_min;

    printf("%d Hours %d Minutes %d Seconds\n", hour,minute,seconds);
    
    

    return 0;
}