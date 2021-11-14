#include "utils.h"

int main(void) {
    printf("Введите цифру для выбора сортировки:\n 1: Соритровка подсчётом\n 2: Быстрая соритировка\n");
    int choice = 0;
    scanf("%d", &choice);
    clock_t begin = clock();
    switch (choice) {
        case 1:
            countingSort();
            break;
        case 2:
            quickSort();
            break;
        default:
            printf("invalid value\n");
            exit(1);
    }
    clock_t end = clock();
    printf("Время сортировки: %lu мкс\n", end - begin);
    return 0;
}
