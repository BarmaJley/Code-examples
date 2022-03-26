#include "func.h"
#include <iostream>

using namespace std;

/**
 * @brief ������� ��������� ������� �� ������ ������ �� �����.
 * @details ���� ������ ������� ������ �� ����� ���������� - true, ����� - false.
 * @version 1.0
 * @author Vadim Chaikin
 * 
 * @param [in] arr (int) - �������� ������.
 * @param [in] size (size_t) - ������ �������.
 * @return bool - �������� �� ������� �������.
 */
bool is_zero_matrix(int* arr, size_t size) {
	if (size <= 0)
		throw 0;
	for (unsigned int i = 0; i < size; ++i)
		if (arr[i] != 0)
			return false;
	return true;
}

/**
 * @brief ������� ��� �������� � ������� ���� ���������, ������������� �� ��������� ������������ ���������.
 * @version 1.0
 * @author Vadim Chaikin
 * 
 * @param [in] arr (int) - �������� ������.
 * @param [in, out] size (size_t) - ������ �������.
 */
void del_all_after_max(int* arr, size_t& size) {
	if (size <= 0)
		throw 0;
	int max = arr[0], ind_max = 0;

	for (unsigned int i = 1; i < size; ++i)
		if (arr[i] > max) {
			max = arr[i];
			ind_max = i;
		}

	size = ind_max + 1;
}

/**
 * @brief ����������� ������� ��� ���������� ������������ ������������� ��������� � �������. 
 * @warning ������ ���� ���� �� ���� ������������� �������.
 * @version 1.0
 * @author Vadim Chaikin
 * 
 * @param [in] arr (int) - �������� ������.
 * @param [in] size (size_t) - ������ �������.
 * @param i (int) - ����� �� ��������� ��� ����������� �������.
 * @return int - ������������ ������������� ���������.
 */
int mult_positive(int* arr, size_t size, int i) {
	if (size <= 0)
		throw 0;
	int result = 1;
	
	if (i == size - 1 && arr[size - 1] > 0) 
		return result * arr[size - 1];
	else if (i == size - 1) 
		return result;

	if (arr[i] > 0)
		result *= arr[i];
	i++;
	return result * mult_positive(arr, size, i);
	
}

/**
 * @brief ������� ��� ���������� ������������ �������������� �������� ���� ������� ��������� � ���� �������� ��� ������ ��������� �������.
 * @warning ����������� ����������, ���� ������� ������� ������. 
 * @version 1.0
 * @author Vadim Chaikin
 * 
 * @param [in] matr (int) - �������� ���������� �������.
 * @param [in] dim (size_t) - ����������� �������.
 * @return int - ����������� ������������� �������.
 */
int find_min_pos_left(int matr[][MAXSIZE], size_t dim) {
	if (dim <= 0)
		throw 0;
	int min_p = LONG_MAX;
	if (dim % 2 == 0)
		throw 1;

	for (unsigned int i = 0; i < dim; ++i)
		for (unsigned int j = 0; j < dim / 2 + 1; ++j) {
			if (j <= i && i < dim / 2 + 1)
				if (matr[i][j] < min_p && matr[i][j] > 0)
					min_p = matr[i][j];
			if (j < dim - i && i >= dim / 2 + 1)
				if (matr[i][j] < min_p && matr[i][j] > 0)
					min_p = matr[i][j];
		}
	return min_p;

}
/**
 * @brief �������, ������������ ������, �������� �������� - ������������ ������ ��������� ������ �������.
 * @warning ����������� ����������, ���� ������� ������� ������. 
 * @version 1.0
 * @author Vadim Chaikin
 * 
 * @param [in] arr (int) - �������� �������.
 * \param [in] rows (size_t) - ���������� ����� �������.
 * \param [in] cols (size_t) - ���������� �������� �������.
 * \return int* - ������.
 */
int* vect_of_mult_even(int** arr, size_t rows, size_t cols) {
	if (rows <= 0 || cols <= 0)
		throw 0;
	int* mas = new int[rows];
	int p = 1;

	for (int i = 0; i < rows; ++i) {
		p = 1;
		for (int j = 0; j < cols; ++j) {
			if (arr[i][j] % 2 == 0)
				p *= arr[i][j];
		}
		mas[i] = p;
	}

	return mas;
}

void read_new(int**& matr, size_t& rows, size_t& cols) {
	if (matr != nullptr)
		throw 3;
	cout << "Insert rows and cols: ";
	cin >> rows;
	cin >> cols;

	matr = new  int* [rows];
	for (int i = 0; i < rows; ++i)
		matr[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			cin >> matr[i][j];
		}
}