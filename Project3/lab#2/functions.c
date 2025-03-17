#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS


int inputInteger() {
    int var;
    int c;

    while (1)
    {
        while (scanf_s("%d", &var) != 1) {
            printf("Incorrect input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF);
        }
        if ((c = getchar()) != '\n' && c != EOF && c != ' ') {
            printf("Incorrect input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else
            return var;
    }
}


int inputIntegerInRange(const int min, const int max)
{
    while (1)
    {
        const int number = inputInteger();
        if (number >= min && number <= max)
            return number;
        printf("The number must be between %d and %d.\n", min, max);
    }
}


void writeFile(FILE* file, const int size) {
    for (int i = 0; i < size; i++) {
        int number = inputIntegerInRange(0, 100);
        fprintf(file, "%d ", number);
    }
    fclose(file);
}


void readFromFile(FILE* file) {
    int number;
    printf("Your elements:\n");
    int i = 1;
    while (fscanf_s(file, "%d", &number) != EOF) {
        printf("%d element is %d\n ", i, number);
        ++i;
    }
    rewind(file);
}


void findSumInFile(FILE* file) {
    int number, sum = 0;

    while (fscanf_s(file, "%d", &number) != EOF) {
        sum += number;
    }
    printf("\nYour resalt is %d", sum);
    fclose(file);
}


void swapLastTwoNumbersInFile(const char* filename) {
    FILE* file = fopen(filename, "r");

    int numbers[100];
    int count = 0;

    while (fscanf_s(file, "%d", &numbers[count]) != EOF) {
        count++;
    }
    fclose(file);

    if (count < 2) {
        printf("Error! There aren't two or more numbers!\n");
        return;
    }

    int temp = numbers[count - 1];
    numbers[count - 1] = numbers[count - 2];
    numbers[count - 2] = temp;

    if (fopen_s(&file, filename, "w") != 0) {
        printf("Error!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf_s(file, "%d ", numbers[i]);
    }
    fclose(file);
}
