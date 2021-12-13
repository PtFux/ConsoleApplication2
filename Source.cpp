/*
	Имя файла - Source.cpp
	Последнее изменение 10.11.2021 02:17
	Описание:
		Этот файл содержит основные функции, 
			необходимые для отладки и правильного выполнения программы:
			rand_arr - заполнение массива случайными элементами
			print_arr - вывод массива
			bool_sort_arr - проверка на отсортированность
			reverse_arr - разворачивание массива
			copy_arr - копирование массива а в массив b
			sum - счет суммы элементов массива

	Автор - Тикунова Полина
	ИУ10-13
*/

#include <clocale>
#include <iostream>
#include <stdio.h>

void rand_arr(signed char a[], int n);
void print_arr(signed char a[], int left, int right);
short int bool_sort_arr(signed char a[], int n);
void reverse_arr(signed char a[], int n);
void copy_arr(signed char a[], int n, signed char b[]);
int sum(double a[], int n);


void rand_arr(signed char a[], int n) {
	/*
		заполнение массива случайными значениями
			используется неявное преобразование типовв
	*/

	for (int i = 0; i < n; ++i) {
		a[i] = rand();
	}
}

void print_arr(signed char a[], int left, int right) {
	/*
		вывод массива [left; right) 
			(для отладки используется явное преобразование типов)
	*/

	for (int i = left; i < right; ++i) {
		std::cout <<(int) a[i] << ' '; // для отладки используется приведение к типу int
	}
}

short int bool_sort_arr(signed char a[], int n) {
	/*
		проверка на отсортированность массива
		если массив отсортирован возвращает 1, иначе - 0
	*/

	short int f = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			f = 0;
			break;
		}
	}
	return f;
}

void reverse_arr(signed char a[], int n) {
	/*
		функция реверса массива
	*/

	signed char c;
	for (int i = 0; i < n/2; ++i) {
		c = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = c;
	}
}

void copy_arr(signed char a[], int n, signed char b[]) {
	/*
		функция копирования массива a в массив b
	*/

	for (int i = 0; i < n; i++){
		b[i] = a[i];
	}
}

int sum(double a[], int n) {
	/*
		функция возвращает сумму элементов массива a размером n
	*/

	double s = 0;
	for (int i = 0; i < n; i++) {
		s = s + a[i];
	}
	return s;
}