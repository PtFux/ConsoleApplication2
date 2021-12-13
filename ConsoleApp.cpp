/*
	ДАТА ИЗМЕНЕНИЯ _ :,) 6.08 (я всё это время делал)
*/
/*
	Имя файла - ConsoleApp.cpp
	Последнее изменение 10.11.2021 06:08
	Описание:
		Этот файл основную функцию main, которая реализует 
			запуск нескольких сортировок и сравнение скорости их работы.
		Файл содержит функцию test, которая реализует тест функции сортировки и замер времени её работы
					функцию sw_sort, которая выводит наименования функций

	Автор - Тикунова Полина
	ИУ10-13
*/

#include <clocale>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include "Header.h"


#include <time.h>

using namespace std;

int main();
double test(signed char a[], int n, void (*f)(signed char*, int));
void sw_sort(int n);

void sw_sort(int n) {
	/*
		функция выводит название функции в зависимости от её номера
	*/

	switch (n)
	{
	case 0:
		cout << "Сортировка пузырьком" << endl;
		break;
	case 1:
		cout << "Сортировка вставками" << endl;
		break;
	case 2:
		cout << "Быстрая сортировка" << endl;
		break;
	case 3:
		cout << "Сортировка Шелла" << endl;
		break;
	case 4:
		cout << "Сортировка слиянием" << endl;
		break;
	}
}

double test(signed char a[], int n, void (*f)(signed char*, int)) {
	/*
		функция реализует тестирование функции сортировки f, 
			замеряет время её работы, выводит размер массива, время выполнения и истинность отсортированности массива
	*/

	time_t start2 = time(NULL);
	f(a, n);
	time_t end2 = time(NULL);
	double t = (double)difftime(end2, start2);
	cout << "Размер массива: " << n << endl;
	cout << "Время выполнения: " << t << endl;
	if (bool_sort_arr(a, n) == 1) {
		cout << "Массив отсортирован" << endl;
	} else cout << "Массив не отсортирован" << endl;
	return t;
}

int main() {
	/*
		функция сравнивает разные функции сортировки на разных размерах массивов
			выводит размер массива, время выполнения и проверку на отсортированность
			выводит самую быструю и самую медленную функцию
	*/

	setlocale(LC_ALL, "Russian");
	signed char* array;
	int n = 50000;				// n для медленных сортировок
	array = (signed char*)malloc(n * sizeof(signed char));
	rand_arr(array, n);
	// print_arr(array, 0, n); // отладка
	cout << endl;

	signed char* array2;
	array2 = (signed char*)malloc(n * sizeof(signed char));


	
	double arr_sort[5];

	cout << "Сортировка пузырьком: " << endl;
	copy_arr(array, n, array2);
	arr_sort[0] = test(array2, n, bubble_sort);
	cout << "Сортировка вставками: " << endl;
	copy_arr(array, n, array2);
	arr_sort[1] = test(array2, n, incert_sort);


	n = 100000;							// размер массива для быстрых сортировок
	array = (signed char*)malloc(n * sizeof(signed char));
	rand_arr(array, n);
	array2 = (signed char*)malloc(n * sizeof(signed char));
	cout << "Быстрая сортировка: " << endl;
	copy_arr(array, n, array2);
	arr_sort[2] = test(array2, n, quick_sort_lite);
	copy_arr(array, n, array2);
	cout << "Сортировка Шелла: " << endl;
	arr_sort[3] = test(array2, n, shell_sort);
	copy_arr(array, n, array2);
	cout << "Сортировка слиянием: " << endl;
	arr_sort[4] = test(array2, n, merge_sort);
	cout << endl;

	cout << "Сортировка пузырьком: " << arr_sort[0] <<endl;

	cout << "Сортировка вставками: " << arr_sort[1] << endl;

	cout << "Быстрая сортировка: " << arr_sort[2] << endl;

	cout << "Сортировка Шелла: " << arr_sort[3] << endl;
	
	cout << "Сортировка слиянием: " << arr_sort[4] << endl;

	cout << "Итоговое время: " << sum(arr_sort, 5) << endl;

	int ind_min_d = 0;
	for (int i = 0; i < 5; i++) {
		if (arr_sort[i] < arr_sort[ind_min_d]) {
			ind_min_d = i;
		}
	}

	int ind_max_d = 0;
	for (int i = 0; i < 5; i++) {
		if (arr_sort[i] > arr_sort[ind_max_d]) {
			ind_max_d = i;
		}
	}

	cout << "Самая быстрая сортировка: ";
	sw_sort(ind_min_d);
	cout << endl;
	cout << "Самая медленная сортировка: ";
	sw_sort(ind_max_d);
	cout << endl;

	// освобождение памяти
	free(array);
	free(array2);
}
