/*
	��� ����� - Header.h
	��������� ��������� 10.11.2021 01:17
	��������:
		������������ ����, �������� �������, ������������ � ����� ConsoleApp.cpp

	����� - �������� ������
	��10-13
*/

#pragma once

	// ������� ��� �������
void rand_arr(signed char a[], int n);
void print_arr(signed char a[], int left, int right);
short int bool_sort_arr(signed char a[], int n);
void reverse_arr(signed char a[], int n);

void copy_arr(signed char a[], int n, signed char b[]);
int sum(double a[], int n);

	// ������� ����������
void bubble_sort(signed char a[], int n);
void incert_sort(signed char a[], int n);
void quick_sort(signed char a[], int left, int right);
void quick_sort_lite(signed char a[], int n);
void shell_sort(signed char a[], int n);
void merge_sort(signed char a[], int n);
