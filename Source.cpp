/*
	��� ����� - Source.cpp
	��������� ��������� 10.11.2021 02:17
	��������:
		���� ���� �������� �������� �������, 
			����������� ��� ������� � ����������� ���������� ���������:
			rand_arr - ���������� ������� ���������� ����������
			print_arr - ����� �������
			bool_sort_arr - �������� �� �����������������
			reverse_arr - �������������� �������
			copy_arr - ����������� ������� � � ������ b
			sum - ���� ����� ��������� �������

	����� - �������� ������
	��10-13
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
		���������� ������� ���������� ����������
			������������ ������� �������������� ������
	*/

	for (int i = 0; i < n; ++i) {
		a[i] = rand();
	}
}

void print_arr(signed char a[], int left, int right) {
	/*
		����� ������� [left; right) 
			(��� ������� ������������ ����� �������������� �����)
	*/

	for (int i = left; i < right; ++i) {
		std::cout <<(int) a[i] << ' '; // ��� ������� ������������ ���������� � ���� int
	}
}

short int bool_sort_arr(signed char a[], int n) {
	/*
		�������� �� ����������������� �������
		���� ������ ������������ ���������� 1, ����� - 0
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
		������� ������� �������
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
		������� ����������� ������� a � ������ b
	*/

	for (int i = 0; i < n; i++){
		b[i] = a[i];
	}
}

int sum(double a[], int n) {
	/*
		������� ���������� ����� ��������� ������� a �������� n
	*/

	double s = 0;
	for (int i = 0; i < n; i++) {
		s = s + a[i];
	}
	return s;
}