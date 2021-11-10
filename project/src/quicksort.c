#include "utils.h"

#define SIZE 100000000

void methodOfCalculationQuickSort(int *numbers, int left, int right) {
    int supportElement; // опорный элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    
    supportElement = numbers[left];
    
    while (left < right) { // пока границы не сомкнутся
        while ((numbers[right] >= supportElement) && (left < right)) {
            right--;
        }
        
        if (left != right) {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место опорного
            left++;
        }
        
        while ((numbers[left] <= supportElement) && (left < right)) {
            left++;
        }

        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }

    numbers[left] = supportElement; // ставим опорный элемент на место
    supportElement = left;
    left = l_hold;
    right = r_hold;

    if (left < supportElement) { // Рекурсивно вызываем сортировку для левой и правой части массива
        methodOfCalculationQuickSort(numbers, left, supportElement - 1);
    }

    if (right > supportElement) {
        methodOfCalculationQuickSort(numbers, supportElement + 1, right);
    }
}

int quickSort(void) {
    int *arr = (int *) malloc (SIZE * sizeof(int));;

    if (arr == 0) {
        exit(4);
    }
    
    // Заполнение массива случайными числами
    for (int i = 0; i<SIZE; i++) {
        arr[i] = rand() % 1000000;
    }
    
    methodOfCalculationQuickSort(arr, 0, SIZE-1); // вызов функции сортировки

    // Вывод элементов массива после сортировки, использовать только для SIZE < 50
    // for (int i = 0; i<SIZE; i++) {
    //     printf("%d ", arr[i]);
    // }

    free(arr); //освобождение памяти
    return 0;
}
