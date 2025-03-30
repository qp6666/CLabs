#include "structure.c"
#include <string.h>


int inputInteger() {
int var;
int c;
while (1) {
    while (scanf_s("%d", &var) != 1) {
        printf("Incorrect input, try again: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if ((c = getchar()) != '\n' && c != EOF && c != ' ') {
        printf("Incorrect input, try again: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else {
        return var;
    }
}
}

int inputIntegerInRange(const int min, const int max) {
    while (1) {
        const int number = inputInteger();
        if (number >= min && number <= max) {
            return number;
        }
        printf("The number must be between %d and %d.\n", min, max);
    }
}

void findingNumberLessThanGivenOne() {
    struct bitField num;
    unsigned int temp;

    printf("Enter an integer number: ");
    temp = inputInteger();
    num.value = temp;

    unsigned int result = num.value >> 3;
    printf("New divided number: %u\n", result);
}

void chooseTask() {
    puts("Choose number of task (1-2) or exit (3):");
    int choice = inputIntegerInRange(1, 3);

    if (choice == 1) {
        findingNumberLessThanGivenOne();
    }
    else if (choice == 2) {
        workWithSeries();
    }
    else {
        exit(1);
    }
}

void inputSeries(struct Series* s) {
    char buffer[100];
    printf("Enter the series title: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    s->title = (char*)malloc(strlen(buffer) + 1);
    if (s->title == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    strcpy_s(s->title, strlen(buffer) + 1, buffer);

    printf("Enter the number of episodes: ");
    if (scanf_s("%d", &s->episodes) != 1) {
        printf("Input error! Please enter a valid number.\n");
        exit(1);
    }
    getchar();

    printf("Enter the release date (dd.mm.yyyy): ");
    fgets(s->date.release_date, sizeof(s->date.release_date), stdin);
    s->date.release_date[strcspn(s->date.release_date, "\n")] = '\0';

    printf("Enter the number of seasons: ");
    if (scanf_s("%d", &s->seasons) != 1) {
        printf("Input error! Please enter a valid number.\n");
        exit(1);
    }
    getchar();
}


void printSeries(const struct Series* s) {
    printf("Title: %s\n", s->title);
    printf("Number of episodes: %d\n", s->episodes);
    printf("Release date: %s\n", s->date.release_date);
    printf("Number of seasons: %d\n", s->seasons);
}

void findByEpisodes(struct Series* arr, int size, int max_episodes) {
    printf("Series with fewer than %d episodes:\n", max_episodes);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].episodes < max_episodes) {
            printSeries(&arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No series found!\n");
    }
}

int removeSeriesByTitle(struct Series* arr, int size, const char* title) {
    int newSize = size;
    int found = 0;
    for (int i = 0; i < newSize;) {
        if (strcmp(arr[i].title, title) == 0) {
            free(arr[i].title);
            for (int j = i; j < newSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            newSize--;
            found = 1;
        }
        else {
            i++;
        }
    }
    if (!found) {
        printf("Series not found.\n");
    }
    return newSize;
}

void freeMemory(struct Series* arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i].title);
    }
    free(arr);
}

void inputSeriesData(struct Series* series, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nSeries %d:\n", i + 1);
        inputSeries(&series[i]);
    }
}

void displayAllSeries(struct Series* series, int n) {
    printf("\nAll series:\n");
    for (int i = 0; i < n; i++) {
        printSeries(&series[i]);
    }
}

void processMaxEpisodes(struct Series* series, int n) {
    int maxEpisodes;
    printf("\nEnter the maximum number of episodes to search for: ");
    maxEpisodes = inputInteger();
    findByEpisodes(series, n, maxEpisodes);
}

void processSeriesDeletion(struct Series* series, int* n) {
    char deleteTitle[100];
    printf("\nEnter the title of the series to delete: ");
    scanf_s(" %[^\n]", deleteTitle);
    *n = removeSeriesByTitle(series, *n, deleteTitle);
}

int workWithSeries() {
    int n;
    printf("Enter the number of series: ");
    n = inputInteger();

    struct Series* series = (struct Series*)malloc(n * sizeof(struct Series));
    if (series == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    inputSeriesData(series, n);
    displayAllSeries(series, n);
    processMaxEpisodes(series, n);
    processSeriesDeletion(series, &n);
    displayAllSeries(series, n);

    freeMemory(series, n);
    return 0;
}