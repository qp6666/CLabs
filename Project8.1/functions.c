#include <stdio.h>
#include <stdlib.h>


void safeFseek(FILE* file, const long offset, const int origin) {
    if (fseek(file, offset, origin) != 0) {
        fprintf(stderr, "\nFile seek failed!\n");
        exit(EXIT_FAILURE);
    }
}


void safeFread(void* buffer, const size_t elementSize, const size_t count, FILE* file) {
    if (fread(buffer, elementSize, count, file) != count && feof(file) == 0) {
        fprintf(stderr, "\nFile reading failed!\n");
        exit(EXIT_FAILURE);
    }
}


void safeFwrite(const void* str, const size_t elementSize, const size_t count, FILE* file) {
    if (fwrite(str, elementSize, count, file) != count) {
        fprintf(stderr, "\nFile writing failed!\n");
        exit(EXIT_FAILURE);
    }
}


int calculateFileLength(FILE* file) {
    safeFseek(file, 0, SEEK_END);
    const long length = ftell(file);
    return length / sizeof(int);
}


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


void fillFileManually(FILE* file) {
    printf("Enter number of integers: ");
    int count = inputInteger();
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        int number = inputInteger();
        safeFwrite(&number, sizeof(int), 1, file);
    }
}


void printFile(FILE* file) {
    int number;
    fseek(file, 0, SEEK_SET);
    printf("\nYour numbers\n");
    while (fread(&number, sizeof(int), 1, file) == 1) {
        printf("%d\n ", number);
    }
}


int calculateCountOfSmallerNumbers(FILE* file) {
    puts("\nEnter reference const number:\n");
    const int reference_const = inputIntegerInRange(-100, 100);
    int count_of_numbers = 0;

    for (int i = 0; i < calculateFileLength(file); i++) {
        if (getNumber(file, i) < reference_const) {
            ++count_of_numbers;
        }
    }
    return count_of_numbers;
}


int getNumber(FILE* file, const int index) {
    safeFseek(file, sizeof(int) * index, SEEK_SET);

    int number = 0;
    safeFread(&number, sizeof(int), 1, file);

    return number;
}

void deleteElements(FILE* file, int reference_value) {
    FILE* tempFile = tmpfile();
    int number;

    fseek(file, 0, SEEK_SET);
    while (fread(&number, sizeof(int), 1, file) == 1) {
        if (number >= reference_value) {
            safeFwrite(&number, sizeof(int), 1, tempFile);
        }
    }

    fseek(tempFile, 0, SEEK_SET);
    fseek(file, 0, SEEK_SET);
    while (fread(&number, sizeof(int), 1, tempFile) == 1) {
        safeFwrite(&number, sizeof(int), 1, file);
    }
    fflush(file);
    fclose(tempFile);
}


void sortFile(FILE* file) {
    int n = calculateFileLength(file);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int a, b;
            fseek(file, sizeof(int) * j, SEEK_SET);
            fread(&a, sizeof(int), 1, file);
            fread(&b, sizeof(int), 1, file);

            if (a < b) {
                fseek(file, sizeof(int) * j, SEEK_SET);
                fwrite(&b, sizeof(int), 1, file);
                fseek(file, sizeof(int) * (j + 1), SEEK_SET);
                fwrite(&a, sizeof(int), 1, file);
            }
        }
    }
}