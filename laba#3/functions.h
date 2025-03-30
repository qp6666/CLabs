#include <stdio.h>
#include <stdlib.h>
#include "structure.c"
#include <string.h>

int inputInteger();

int inputIntegerInRange(const int min, const int max);

void findingNumberLessThanGivenOne();

void chooseTask();

void inputSeries(struct Series* s);

void printSeries(const struct Series* s);

void findByEpisodes(struct Series* arr, int size, int max_episodes);

int removeSeriesByTitle(struct Series* arr, int size, const char* title);

void freeMemory(struct Series* arr, int size);

void inputSeriesData(struct Series* series, int n);

void displayAllSeries(struct Series* series, int n);

void processMaxEpisodes(struct Series* series, int n);

void processSeriesDeletion(struct Series* series, int* n);

int workWithSeries();