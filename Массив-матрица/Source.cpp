#include "func.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	size_t size1 = 5;

	int arr[MAXSIZE] = { 1, 2, 3, 4, 5 };
	cout << "Является ли матрица нулевой: "<< is_zero_matrix(arr, size1) << endl;

	int arr2[MAXSIZE] = { 8, 9, 1, 4, 5 };

	del_all_after_max(arr2, size1);
	cout << "Массив после удаления элементов после максимального: ";
	for (int i = 0; i < size1; ++i)
		cout << arr2[i] << " ";
	cout << endl;

	int arr3[MAXSIZE] = { 8, -1, 4, -2, 5 };
	cout << "Произведение положительных элементов: " << mult_positive(arr, size1) << endl;

	int arr4[][MAXSIZE] = {
				{2, 3, 3, 5, 6},
				{5, 3, 6, 7, 6},
				{9, 5, 9, 0, 1},
				{1, 9, 2, 5, 7},
				{2, -7, 6, 8, 7},
				{3, 1, 9, 9, 9}
	};
	size_t dim = 5;
	cout << "Минимальный элемент в заданной области: " << find_min_pos_left(arr4, dim) << endl;

	size_t rows = 0, cols = 0;
	int** matr = nullptr;
	read_new(matr, rows, cols);

	int* arr5 = nullptr;
	arr5 = vect_of_mult_even(matr, rows, cols);

	cout << "Массив произведения четных элементов: ";
	for (int i = 0; i < rows; ++i) {
		cout << arr5[i] << " ";
	}
	
	
	
	return 0;
}