#include <stdio.h>
#include <string.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Person
{
    char Name[50];
    int age;
    struct Date birthday;
};


int main(int argc, char const *argv[])
{
    struct Person Ahmet;

    Ahmet.age = 15;
    strcpy(Ahmet.Name, "Ahmet");
    Ahmet.birthday.year = 2003;
    Ahmet.birthday.month = 06;
    Ahmet.birthday.day = 23;


    return 0;
}
