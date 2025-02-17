#include <stdio.h>
#include <stdlib.h>


void safeFseek(FILE* file, const long offset, const int origin){
    if (fseek(file, offset, origin) != 0)
    {
        fprintf(stderr, "\nFile writing failed!\n");
        exit(EXIT_FAILURE);
    }
}


void safeFread(void* buffer, const size_t elementSize, const size_t count, FILE* file){
    if (fread(buffer, elementSize, count, file) != count && feof(file) == 0)
    {
        fprintf(stderr, "\nFile reading failed!\n");
        exit(EXIT_FAILURE);
    }
}


void safeFwrite(const void* str, const size_t elementSize, const size_t count, FILE* file){
    if (fwrite(str, elementSize, count, file) != count)
    {
        fprintf(stderr, "\nFile writing failed!\n");
        exit(EXIT_FAILURE);
    }
}


long safeFtell(FILE* file){
    const long temp = ftell(file);
    if (temp == -1)
    {
        fprintf(stderr, "\nFile writing failed!\n");
        exit(EXIT_FAILURE);
    }
    return temp;
}


int calculateFileLength(FILE* file)
{
    safeFseek(file, 0, SEEK_END);

    const int file_length = safeFtell(file) / sizeof(int);

    return file_length;
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


char* inputString() {
    char c;
    int size = 0;
    int capacity = 10;

    char* str = (char*)malloc(capacity * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter name of file: ");

    while ((c = getchar()) != '\n' && c != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            str = (char*)realloc(str, capacity * sizeof(char));
            if (str == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }
        str[size++] = c;
    }

    str[size] = '\0';
    return str;
}

FILE* openFile(const char* mode) {
    const char* file_name = inputString();
    FILE* file = fopen(file_name, mode);

    free(file_name);

    if (file == NULL) {
        fprintf(stderr, "Error!\n Fuck uuuuu!");
        exit(EXIT_FAILURE);
    }

    return file;
}


int getNumber(FILE* file, const int index){
    safeFseek(file, sizeof(int) * index, SEEK_SET);

    int number = 0;
    safeFread(&number, sizeof(int), 1, file);

    return number;
}


void insertNumber(FILE* file, const int number, const int index){
    safeFseek(file, sizeof(int) * index, SEEK_SET);

    safeFwrite(&number, sizeof(int), 1, file);
}


void swapNumbers(FILE* file, const int first_index, const int second_index)
{
    const int temp = getNumber(file, first_index);

    insertNumber(file, getNumber(file, second_index), first_index);

    insertNumber(file, temp, second_index);
}


void fillFileManually(FILE* file) {
    puts("\nEnter count of numbers in your file :\n");
    int number_count = inputIntegerInRange(1, 100);
    for (int i = 0; i < number_count; i++) {
        printf("Enter %d number", i + 1);
        insertNumber(file, inputIntegerInRange(-100, 100), i);
    }
}


int generateRandomNumberInRange(const int max_value, const int min_value) {
    return rand() % (max_value - min_value + 1) + min_value;
}


void fillFileRandomly(FILE* file) {
    puts("\nEnter count of number in your file:\n");
    for (int i = 0; i < inputIntegerInRange(1, 100); i++) {
        insertNumber(file, generateRandomNumberInRange(-100, 100), i);
    }
}


void printFile(FILE* file) {
    for (int i = 0; i < calculateFileLength(file); i++) {
        printf("\n%d number in file = %d\n", i + 1, getNumber(file, i));
    }
}


