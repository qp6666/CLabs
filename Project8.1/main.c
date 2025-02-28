#include"functions.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error!\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "w+b");

    puts("\nEnter the task number (1-4) or 5 to exit.");
    int choice = inputIntegerInRange(1, 5);

    if (choice == 1) {
        fillFileManually(file);

        printFile(file);

        fclose(file);
    }
    else if (choice == 2) {
        fillFileManually(file);

        printFile(file);

        printf("\nThe quantity of numbers is less than the specified one = %d\n", calculateCountOfSmallerNumbers(file));
        
        fclose(file);
    }
    else if (choice == 3) {
        fillFileManually(file);

        printFile(file);

        printf("Enter reference const number: ");
        int reference_value = inputIntegerInRange(0, 100);
        
        deleteElements(file, reference_value);
    }
    else if (choice == 4) {
        fillFileManually(file);

        printFile(file);

        sortFile(file);

        printFile(file);
    }
    else if (choice == 5) {
        fclose(file);
        exit(1);
    }
}