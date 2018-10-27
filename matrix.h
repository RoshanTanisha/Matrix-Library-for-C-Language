#include <stddef.h>

typedef struct matrix{
    int rows, cols;
    float ** pointer;
}Matrix;

Matrix * create_matrix(int rows, int columns);
Matrix * add_matrix(Matrix * a, Matrix * b);
Matrix * sub_matrix(Matrix * a, Matrix * b);