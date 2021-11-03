#include "utils.h"

#define SIZE 100

int searchMax(long int a[]) {
    int max = a[0];
    for (size_t i = 1; i < SIZE; i++) {
        if (a[i] > max) 
            max = a[i];
    }
    return max;
}

void methodOfCalculationCountingSort(long int lenght, long int arr[], long int helpArr[]) {
    for (size_t i = 0; i < SIZE; i++) {
        helpArr[arr[i]]++;
        arr[i] = 0;
    }

    int NumberInArray = 0;
    for (size_t i = 0; i < lenght + 1; i++) {
        while(helpArr[i]) {
            arr[NumberInArray] = i;
            NumberInArray++;
            helpArr[i]--;
        }
    }
}

int countingSort(void) {
    //выделение памяти под массив
    long int *arr, *helpArr;
    
    arr = (long int *)malloc(SIZE * sizeof(long int));
    
    for (long int i = 0; i < SIZE; i++) { // Заполнение массива случайными числами
        arr[i] = rand() % 201;
    }
    
    int lenght = searchMax(arr); // поиск максимального значения в изначальном массиве
    helpArr = (long int *)calloc(lenght, sizeof(long int));

    methodOfCalculationCountingSort(lenght, arr, helpArr); //сортировка методом подсчета

    free(arr); //освобождение памяти
    free(helpArr);
    return 0;
}
