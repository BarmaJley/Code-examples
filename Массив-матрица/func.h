#pragma once

const int MAXSIZE = 50;

bool is_zero_matrix(int* arr, size_t size);
void del_all_after_max(int* arr, size_t& size);
int mult_positive(int* arr, size_t size, int i = 0);
int find_min_pos_left(int matr[][MAXSIZE], size_t dim);
int* vect_of_mult_even(int** arr, size_t rows, size_t cols);
void read_new(int**& matr, size_t& rows, size_t& cols);