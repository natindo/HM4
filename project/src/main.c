#include "utils.h"

int main(void) {
    printf("Введите цифру для выбора сортировки:\n 1: Соритровка подсчётом\n 2: Быстрая соритировка\n");
    int a;
    scanf("%d", &a);
    clock_t begin = clock();
    switch (a) {
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
    int time_spend = end - begin;
    printf("%d\n", time_spend);
    return 0;
}
