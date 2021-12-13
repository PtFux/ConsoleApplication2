/*
	Имя файла - Func_sort.cpp
	Последнее изменение 10.11.2021 05:17
	Описание:
		Этот файл содержит основные функции сортировки

	Автор - Тикунова Полина
	ИУ10-13
*/

#include <clocale>
#include <iostream>
#include <stdio.h>

void bubble_sort(signed char a[], int n);
void incert_sort(signed char a[], int n);
void quick_sort(signed char a[], int left, int right);
void quick_sort_lite(signed char a[], int n);
void shell_sort(signed char a[], int n);
void merge_sort(signed char a[], int n);

int bin(signed char a[], int left, int right, signed char ch);
int index(signed char a[], int d, int left, int right);
int index_shell(signed char a[], int i, int d);

void print_arr(signed char a[], int left, int right);

void bubble_sort(signed char a[], int n) {
	/*
		Сортировка пузырьком. квадратное прохождение по массиву
		при ситуации эл1, эл2 // при этом эл2 меньше эл1
		они меняются местами
	*/

	signed char c;
	for (int j = 0; j < n; ++j) {
		for (int i = 1; i < n - j; ++i) {
			if (a[i] < a[i - 1]) {
				c = a[i];
				a[i] = a[i - 1];
				a[i - 1] = c;
			}
		}
	}
}

void incert_sort(signed char a[], int n) {
	/*
		сортировка вставками
	*/

	for (int i = 1; i < n; ++i) {
		int k = bin(a, 0, i, a[i]);
		int c = a[k];
		a[k] = a[i];
		for (int j = k + 1; j <= i; j++) {
			int p = a[j];
			a[j] = c;
			c = p;
		}
	}
}

int bin(signed char a[], int left, int right, signed char ch) {
	/*
			реализация бин поиска элемента ch в массиве а[left..right)
	*/

	int c = (left + right) / 2;
	if (right - left <= 1) {
		if (a[left] > ch) {
			return left;
		}
		else return ++left;
	}
	if (a[c] > ch) {
		right = c;
	}
	else if (a[c] < ch) {
		left = c;
	}
	else return c;
	return bin(a, left, right, ch);

}

void shell_sort(signed char a[], int n) {
	/*
		сортировка шелла
	*/

	for (int d = n / 2; d > 0; d = d / 2) {
		for (int j = 0; j < d; j++) {
			for (int i = j; i < n; i = i + d) {
				int k = index_shell(a, i, d);
				int c = a[k];
				a[k] = a[i];
				for (int p = k + d; p < i + 1; p = p + d) {
					int v = a[p];
					a[p] = c;
					c = v;
				}
			}
		}
	}
}

int index_shell(signed char a[], int i, int d) {
	/*
		функция поиска индекса, на место которого должен встать элемент a[i]
		рассматриваются элементы с шагом индекса d
	*/

	int k = 0;
	for (int j = i - d; j >= 0; j -= d) {
		if (a[i] >= a[j]) {
			k = j + d;
			break;
		}
		if (k < 0) k = 0;
	}
	return k;
}

void quick_sort(signed char a[], int left, int right) {
	/*
		быстрая сортировка
	*/

	if ((left > right) | (left == right)) {
		return;
	}
	else if (right - left == 1) {
		if (a[right] < a[left]) {
			int cc = a[left];
			a[left] = a[right];
			a[right] = cc;
		}
		return;
	}

	int c = (right + left) / 2;

	int i = left;
	int j = right;
	int d = a[c];

	while (i < j) {
		while ((a[i] < d)) i++;
		while ((a[j] > d)) j--; 

		if (i < j) {
			int cc = a[i];
			a[i] = a[j];
			a[j] = cc;
			if (a[i] == d) j--; else i++;
		}
	}
	// i = index(a, d, left, right);

	quick_sort(a, left, i-1);
	quick_sort(a, i+1, right);
}

void quick_sort_lite(signed char a[], int n) {
	/*
		Функция нужна, чтобы запускать функцию быстрой сортировки также как и другие
			(аргументы)
	*/

	quick_sort(a, 0, n);
}

int index(signed char a[], int d, int left, int right) {
	/*
		функция находит индекс элемента, по которому разделять массивы в быстрой сортировке
		но в ней нет необходимости
	*/

	for (int i = left; i <= right; i++) {
		if (a[i] == d) {
			return i;
		}
	}
	return -1;
}

void merge_sort(signed char a[], int n) {
	/*
		Функция реализует сортировку слиянием
	*/

	if (n <= 1) {
		return;
	}
	else if (n == 2) {
		if (a[1] < a[0]) {
			int c = a[1];
			a[1] = a[0];
			a[0] = c;
		}
	}
	signed char* left_a;
	left_a = (signed char*)malloc((n/2) * sizeof(signed char));	
	signed char* right_a;
	right_a = (signed char*)malloc((n-n/2) * sizeof(signed char));

	int i;
	for (i = 0; i < n/2; i++) {
		left_a[i] = a[i];
	}
	for (int j = i; j < n; j++) {
		right_a[j - i] = a[j];
	}

	merge_sort(left_a, n / 2);
	merge_sort(right_a, n - n / 2);

	i = 0;
	int j = 0;
	int k = 0;
	while ((i < n / 2) | (j < n - n / 2)) {
		if (i == n / 2) {
			a[k++] = right_a[j++];
		}
		else if (j == n - n / 2) {
			a[k++] = left_a[i++];
		}
		else if (left_a[i] < right_a[j]) {
			a[k++] = left_a[i++];
		}
		else a[k++] = right_a[j++];
	}
}
