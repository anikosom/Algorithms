#pragma once
#ifndef FUNCT_H
#define FUNCT_H

bool is_equal(int **array1, const size_t rows1, const size_t columns1, int **array2, const size_t rows2, const size_t columns2);
int fill_array(int **array, const size_t rows, const size_t columns, const int init_value);
int print_array(int **array, const size_t rows, const size_t columns);

#endif