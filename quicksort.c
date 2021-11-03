#include "utils.h"

#define SIZE 100
// Функция быстрой сортировки
void methodOfCalculationQuickSort(long int *numbers, long int left, long int right) {
    long int supportElement; // разрешающий элемент
    long int l_hold = left; //левая граница
    long int r_hold = right; // правая граница
    
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
    long int *arr = malloc (SIZE * sizeof(long int));
    
    // Заполнение массива случайными числами
    for (long int i = 0; i<SIZE; i++) {
        arr[i] = rand() % 201 - 100;
    }
    
    methodOfCalculationQuickSort(arr, 0, SIZE-1); // вызов функции сортировки
    // Вывод элементов массива после сортировки (использовать только для SIZE <50)
    
    // for (int i = 0; i<SIZE; i++) {
    //     printf("%ld ", arr[i]);
    // }
    
    //освобождение памяти
    printf("\n");
    free(arr);
    return 0;
}
