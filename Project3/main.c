#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

void write_to_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    int n;
    printf("Введите количество чисел: ");
    scanf("%d", &n);

    printf("Введите числа:\n");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        fprintf(file, "%d ", num);
    }

    fclose(file);
}

void read_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    int num;
    printf("Данные из файла:\n");
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

void find_in_file(const char* filename, int target) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    int num;
    int found = 0;
    while (fscanf(file, "%d", &num) != EOF) {
        if (num == target) {
            printf("Найдено число: %d\n", num);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Число %d не найдено в файле.\n", target);
    }

    fclose(file);
}

int sum_in_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    int sum = 0;
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        sum += num;
    }

    fclose(file);
    return sum;
}

void swap_last_two(const char* filename) {
    int numbers[MAX_NUMBERS];
    int count = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    while (fscanf(file, "%d", &numbers[count]) != EOF) {
        count++;
    }
    fclose(file);

    if (count < 2) {
        printf("Недостаточно элементов для замены.\n");
        return;
    }

    int temp = numbers[count - 1];
    numbers[count - 1] = numbers[count - 2];
    numbers[count - 2] = temp;

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Ввести данные и записать в файл\n");
        printf("2. Вывести данные из файла\n");
        printf("3. Найти данные в файле\n");
        printf("4. Найти сумму чисел в файле\n");
        printf("5. Поменять местами два последних числа\n");
        printf("0. Выйти\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            write_to_file(filename);
            break;
        case 2:
            read_from_file(filename);
            break;
        case 3: {
            int target;
            printf("Введите число для поиска: ");
            scanf("%d", &target);
            find_in_file(filename, target);
            break;
        }
        case 4: {
            int sum = sum_in_file(filename);
            printf("Сумма чисел в файле: %d\n", sum);
            break;
        }
        case 5:
            swap_last_two(filename);
            printf("Два последних числа поменяны местами.\n");
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
