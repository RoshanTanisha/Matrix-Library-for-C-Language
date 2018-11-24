#include <stddef.h>

typedef struct matrix{
    int rows, cols;
    float ** pointer;
}Matrix;

Matrix * create_matrix(int rows, int columns);
Matrix * add_matrix(Matrix * a, Matrix * b);
Matrix * sub_matrix(Matrix * a, Matrix * b);
Matrix * multiply_scalar_value(Matrix * a, float b);
Matrix * matalloc(int rows, int columns);
Matrix * get_new_matrix(Matrix * a);
Matrix * multiply_matrix(Matrix * a, Matrix * b);
Matrix * add_scalar_value(Matrix * a, float b);
void print_matrix(Matrix * a);