#include "utils.h"

#define SIZE 100000000

void methodOfCalculationQuickSort(int *numbers, int left, int right) {
    int supportElement; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    
    supportElement = numbers[left];
    
    while (left < right) { // пока границы не сомкнутся
        while ((numbers[right] >= supportElement) && (left < right)) {
            right--;// сдвигаем правую границу пока элемент [right] больше [supportElement]
        }
        
        if (left != right) { // если границы не сомкнулись
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        
        while ((numbers[left] <= supportElement) && (left < right)) {
            left++; // сдвигаем левую границу пока элемент [left] меньше [supportElement]
        }

        if (left != right) { // если границы не сомкнулись
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }

    numbers[left] = supportElement; // ставим разрешающий элемент на место
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
    int *arr;

    arr = (int *) malloc (SIZE * sizeof(int));

    if (arr == 0) {
        exit(1);
    }
    
    // Заполнение массива случайными числами
    for (int i = 0; i<SIZE; i++) {
        arr[i] = rand() % 1000000;
    }
    
    methodOfCalculationQuickSort(arr, 0, SIZE-1); // вызов функции сортировки
    // Вывод элементов массива после сортировки (использовать только для SIZE <50)
    

    // for (int i = 0; i<SIZE; i++) {
    //     printf("%ld ", arr[i]);
    // }

    free(arr); //освобождение памяти
    return 0;
}
