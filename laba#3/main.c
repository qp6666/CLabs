#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ �1: ����� � ������� ����� ����� � 8 ��� ������ ���������, ��������� ��������� �����
void task1() {
    int num;
    printf("������� �����: ");
    scanf("%d", &num);
    printf("�����, ����������� � 8 ���: %d\n", num >> 3);
}

// ��������� ��� ���������� � �������
typedef struct {
    char date[11]; // ���� ������ (������������� ����� ������)
} Date;

typedef struct {
    int episodes;
    char* name;
    Date release_date;
    int seasons;
} Series;

// ������� ����� ������ � �������
void input_series(Series* s) {
    char buffer[100];
    printf("������� �������� �������: ");
    scanf("%99s", buffer);
    s->name = strdup(buffer);
    printf("������� ���������� �����: ");
    scanf("%d", &s->episodes);
    printf("������� ���� ������ (YYYY-MM-DD): ");
    scanf("%10s", s->release_date.date);
    printf("������� ���������� �������: ");
    scanf("%d", &s->seasons);
}

// ������� ������ ������ � �������
void print_series(const Series* s) {
    printf("��������: %s, �����: %d, ���� ������: %s, �������: %d\n",
        s->name, s->episodes, s->release_date.date, s->seasons);
}

// ������� ������ �������� � ����������� ����� ������ ���������
void find_series(Series* arr, int size, int max_episodes) {
    printf("������� � ����������� ����� ������ %d:\n", max_episodes);
    for (int i = 0; i < size; i++) {
        if (arr[i].episodes < max_episodes) {
            print_series(&arr[i]);
        }
    }
}

// ������� �������� ������� �� ��������
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

// ���� ��� ������ � �������� ��������
void menu() {
    int choice, size = 0;
    Series* series = NULL;
    while (1) {
        printf("\n1. �������� ������\n2. �������� �������\n3. ����� ������� �� ���������� �����\n4. ������� ������ �� ��������\n5. �����\n�����: ");
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
            printf("������� ������������ ���������� �����: ");
            scanf("%d", &max_episodes);
            find_series(series, size, max_episodes);
        }
        else if (choice == 4) {
            char name[100];
            printf("������� �������� ������� ��� ��������: ");
            scanf("%99s", name);
            if (delete_series(&series, &size, name))
                printf("������� �������!\n");
            else
                printf("������ �� ������!\n");
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("�������� ����!\n");
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
