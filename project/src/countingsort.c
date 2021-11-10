#include "utils.h"

#define SIZE 100000000

int searchMax(int *a) { // поиск максимума в массиве
    int max = a[0];
    for (int i = 1; i < SIZE; i++) {
        if (a[i] > max) 
            max = a[i];
    }
    return max;
}

void methodOfCalculationCountingSort(int lenght, int *arr, int *supportArr) {
    for (int i = 0; i < SIZE; i++) { // заполнение вспомогатетльного массива и зануление значений изначального
        supportArr[arr[i]]++;
        arr[i] = 0;
    }

    int NumberInArray = 0;
    for (int i = 0; i < lenght + 1; i++) { // заполнение изначального массива
        while(supportArr[i]) {
            arr[NumberInArray] = i;
            NumberInArray++;
            supportArr[i]--;
        }
    }
}

int countingSort(void) {
    int *arr, *supportArr;

    arr = (int *) malloc (SIZE * sizeof(int));

    if (arr == NULL) {
        exit(2);
    }
    
    for (int i = 0; i < SIZE; i++) { // Заполнение массива случайными числами
        arr[i] = rand() % 1000000;
    }
    
    int lenght = searchMax(arr);
    supportArr = (int *) calloc (lenght, sizeof(int));

    if (supportArr == 0) {
        exit(3);
    }

    methodOfCalculationCountingSort(lenght, arr, supportArr); //сортировка методом подсчета

    // Вывод элементов массива после сортировки, использовать только для SIZE < 50
    // for (int i = 0; i<SIZE; i++) {
    //     printf("%d ", arr[i]);
    // }

    free(arr); //освобождение памяти
    free(supportArr);
    return 0;
}
