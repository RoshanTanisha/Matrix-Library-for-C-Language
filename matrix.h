/*
 * @author Tanisha R. Bhayani
 * 24th November, 2018
 */

#include <stddef.h>
#include "types.c"

Matrix * create_matrix(int rows, int columns);
Matrix * add_matrix(Matrix * a, Matrix * b);
Matrix * sub_matrix(Matrix * a, Matrix * b);
Matrix * multiply_scalar_value(Matrix * a, float b);
Matrix * matalloc(int rows, int columns);
Matrix * get_new_matrix(Matrix * a);
Matrix * multiply_matrix(Matrix * a, Matrix * b);
Matrix * add_scalar_value(Matrix * a, float b);
float deteminant(Matrix * a);
bool check_square_matrix(Matrix * a);
void print_matrix(Matrix * a);