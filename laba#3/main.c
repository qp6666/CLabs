#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Задача №1: Найти и вывести целое число в 8 раз меньше заданного, используя побитовый сдвиг
void task1() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    printf("Число, уменьшенное в 8 раз: %d\n", num >> 3);
}

// Структура для информации о сериале
typedef struct {
    char date[11]; // Дата выхода (фиксированная длина строки)
} Date;

typedef struct {
    int episodes;
    char* name;
    Date release_date;
    int seasons;
} Series;

// Функция ввода данных о сериале
void input_series(Series* s) {
    char buffer[100];
    printf("Введите название сериала: ");
    scanf("%99s", buffer);
    s->name = strdup(buffer);
    printf("Введите количество серий: ");
    scanf("%d", &s->episodes);
    printf("Введите дату выхода (YYYY-MM-DD): ");
    scanf("%10s", s->release_date.date);
    printf("Введите количество сезонов: ");
    scanf("%d", &s->seasons);
}

// Функция вывода данных о сериале
void print_series(const Series* s) {
    printf("Название: %s, Серий: %d, Дата выхода: %s, Сезонов: %d\n",
        s->name, s->episodes, s->release_date.date, s->seasons);
}

// Функция поиска сериалов с количеством серий меньше заданного
void find_series(Series* arr, int size, int max_episodes) {
    printf("Сериалы с количеством серий меньше %d:\n", max_episodes);
    for (int i = 0; i < size; i++) {
        if (arr[i].episodes < max_episodes) {
            print_series(&arr[i]);
        }
    }
}

// Функция удаления сериала по названию
int delete_series(Series** arr, int* size, const char* name) {
    int count = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp((*arr)[i].name, name) == 0) {
            free((*arr)[i].name);
            for (int j = i; j < *size - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*size)--;
            (*arr) = realloc(*arr, (*size) * sizeof(Series));
            count++;
            i--;
        }
    }
    return count;
}

// Меню для работы с массивом структур
void menu() {
    int choice, size = 0;
    Series* series = NULL;
    while (1) {
        printf("\n1. Добавить сериал\n2. Показать сериалы\n3. Найти сериалы по количеству серий\n4. Удалить сериал по названию\n5. Выйти\nВыбор: ");
        scanf("%d", &choice);
        if (choice == 1) {
            series = realloc(series, (size + 1) * sizeof(Series));
            input_series(&series[size]);
            size++;
        }
        else if (choice == 2) {
            for (int i = 0; i < size; i++) print_series(&series[i]);
        }
        else if (choice == 3) {
            int max_episodes;
            printf("Введите максимальное количество серий: ");
            scanf("%d", &max_episodes);
            find_series(series, size, max_episodes);
        }
        else if (choice == 4) {
            char name[100];
            printf("Введите название сериала для удаления: ");
            scanf("%99s", name);
            if (delete_series(&series, &size, name))
                printf("Удалено успешно!\n");
            else
                printf("Сериал не найден!\n");
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Неверный ввод!\n");
        }
    }
    for (int i = 0; i < size; i++) free(series[i].name);
    free(series);
}

int main() {
    task1();
    menu();
    return 0;
}
