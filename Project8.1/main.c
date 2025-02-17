#include "tasks.h"
#include"functions.h"

#include <stdio.h>



void chooseTask(const int choice)
{
    switch (choice)
    {
    case 1:
        task1();
        break;

    case 2:
        task2();
        break;

    case 3:
        task3();
        break;

    case 4: 
        task4();
        break;

    default:;
    }
}


int main()
{
    //setlocale(LC_ALL, "Rus");

    while (1)
    {
        puts("\nEnter the task number (1-4) or 5 to exit.");

        const int choice = inputIntegerInRange(1, 5);

        if (choice != 5)
            chooseTask(choice);
        else
            return 0;
    }
}