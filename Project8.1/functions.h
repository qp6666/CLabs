#include <stdio.h>
#include <stdlib.h>

void safeFseek(FILE* file, const long offset, const int origin);

void safeFread(void* buffer, const size_t elementSize, const size_t count, FILE* file);

void safeFwrite(const void* str, const size_t elementSize, const size_t count, FILE* file);

int calculateFileLength(FILE* file);

int inputInteger();

int inputIntegerInRange(const int min, const int max);

void fillFileManually(FILE* file);

void printFile(FILE* file);

int calculateCountOfSmallerNumbers(FILE* file);

int getNumber(FILE* file, const int index);

void deleteElements(FILE* file, int reference_value);

void sortFile(FILE* file);