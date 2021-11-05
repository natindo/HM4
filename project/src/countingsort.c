#include "utils.h"

#define SIZE 100000000

int searchMax(int a[]) {
    int max = a[0];
    for (int i = 1; i < SIZE; i++) {
        if (a[i] > max) 
            max = a[i];
    }
    return max;
}

void methodOfCalculationCountingSort(int lenght, int *arr, int *helpArr) {
    for (int i = 0; i < SIZE; i++) { // заполнение вспомогатетльного массива и зануление значений изначального
        helpArr[arr[i]]++;
        arr[i] = 0;
    }

    int NumberInArray = 0;
    for (int i = 0; i < lenght + 1; i++) { // заполнение изначального массива
        while(helpArr[i]) {
            arr[NumberInArray] = i;
            NumberInArray++;
            helpArr[i]--;
        }
    }
}

int countingSort(void) {
    //выделение памяти под массив
    int *arr, *helpArr;

    arr = (int *) malloc (SIZE * sizeof(int));

    if (arr == NULL) {
        exit(1);
    }
    
    for (int i = 0; i < SIZE; i++) { // Заполнение массива случайными числами
        arr[i] = rand() % 1000000;
    }
    
    int lenght = searchMax(arr); // поиск максимального значения в изначальном массиве
    helpArr = (int *)calloc(lenght, sizeof(int));

    if (helpArr == 0) {
        exit(1);
    }

    methodOfCalculationCountingSort(lenght, arr, helpArr); //сортировка методом подсчета

    free(arr); //освобождение памяти
    free(helpArr);
    return 0;
}
