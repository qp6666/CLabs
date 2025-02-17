#include <stdio.h>
#include <stdlib.h>


void safeFseek(FILE* file, const long offset, const int origin);

void safeFread(void* buffer, const size_t elementSize, const size_t count, FILE* file);

void safeFwrite(const void* str, const size_t elementSize, const size_t count, FILE* file);

int calculateFileLength(FILE* file);

int inputInteger();

int inputIntegerInRange(const int min, const int max);

char* inputString();

FILE* openFile(const char* mode);

int getNumber(FILE* file, const int index);

void insertNumber(FILE* file, const int number, const int index);

void swapNumbers(FILE* file, const int first_index, const int second_index);

void fillFileManually(FILE* file);

int generateRandomNumberInRange(const int max_value, const int min_value);

void fillFileRandomly(FILE* file);

void printFile(FILE* file);
