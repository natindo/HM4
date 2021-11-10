# Homework_4
<h1 align="center">Описание программы</h1>
Программа выводит время(в микросекундах) сортировки массива данных. Предоставляется выбор сортировки: сортировка подсчётом и быстрая. Для выбора сортировки, после запуска программы, введите 1 или 2 соответственно.
<h1 align="center">Инструкция по использованию</h1>
Для компиляции программы напишите в терминале, находясь в папке, где лежит этот (readme) файл:
```bash
$ make
```
Чтобы запустить программу введите в консоль:
```bash
$ ./main.out
```
<br>
В поле ввода, не используйте числа, кроме 1 и 2, не вводите буквы или любые специальные символы.<br>
Для измениения количества сортируемых данных, перепишите число у макроса <i>SIZE</i> соответствующего файла сортировки

```c
#define SIZE 100000000
```

Для изменения максимального числа в соритруемых данных, перепишите число после знака <i>%</i> в cоответстующем файле сортировки

```c
for (int i = 0; i<SIZE; i++) {
    arr[i] = rand() % 1000000;
}
```

Для вывода отсортированных данных раскомментируйте участок кода в соответствующем файле

```c
//Вывод элементов массива после сортировки, использовать только для SIZE < 50
for (int i = 0; i<SIZE; i++) {
    printf("%d ", arr[i]);
}
```

<h1 align="center">Коды возврата ошибок</h1>
1 - введено неверное значение<br>
2 - при выборе соритровки подсчётом не удалось выделить память под изначальный массив<br>
3 - при выборе соритровки подсчётом не удалось выделить память под вспомогательный массив<br>
4 - при выборе быстрой сортировки не удалось выделить память под массив<br>
PS Код ошибки выводится сразу после завершения работы программы