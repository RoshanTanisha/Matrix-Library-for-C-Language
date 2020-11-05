/**
 * @author Tanisha R. Bhayani
 * 24th November, 2018
 * Main file where all the functions are defined.
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

/*
** creating matrix requires dimensions (#rows, #columns).
** Data Type is casted when the function returns the memory chunk
*/

void print_matrix(Matrix * a){
    if (a == NULL) {
        return;
    }
    unsigned int i, j;
    for (i = 0; i < a->rows; i ++) {
        for (j = 0; j < a->cols; j ++) {
            printf("%f\t", a->pointer[i][j]);
        }
        printf("\n");
    }
}

Matrix * matalloc(int rows, int columns){
    Matrix * mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = columns;
    mat->pointer = calloc(mat->rows, sizeof(mat));
    unsigned int i, j;
    // matrix = calloc(rows, size);
    for(i = 0; i < mat->rows; i ++){
        mat->pointer[i] = (float *)calloc(mat->cols, sizeof(float));
        if (mat->pointer[i] == NULL) {
            printf("Out of memory error.");
        }
    }
    return mat;
}

Matrix * initialize_matrix(Matrix * a) {
    int i, j;
    for (i = 0; i < a->rows; i ++) {
        for (j = 0; j < a->cols; j ++) {
            a->pointer[i][j] = rand() % a->rows;
        }
    }

    return a;
}

Matrix * multiply_scalar_value(Matrix * a, float b){
    int i, j;
    for (i = 0; i < a->rows; i ++) {
        for (j = 0; j < a->cols; j++){
            a->pointer[i][j] *= b;
        }
    }
    return a;
}

Matrix * get_new_matrix(Matrix * a){
    Matrix * d = matalloc(a->rows, a->cols);
    int i, j;
    for (i = 0; i < d->rows; i ++) {
        for (j = 0; j < d->cols; j ++) {
            d->pointer[i][j] = a->pointer[i][j];
        }
    }
    return d;
}

Matrix * add_matrix(Matrix * a, Matrix * b){
    if(a->rows != b->rows || a->cols != b->cols){
        printf("Either Columns or Rows are not same\n");
        return NULL;
    }
    Matrix * c = matalloc(a->rows, a->cols);
    int i, j;

    for(i = 0; i < a->rows; i ++){
        for (j = 0; j < a->cols; j++) {
            c->pointer[i][j] = a->pointer[i][j] + b->pointer[i][j];
        }
    }
    return c;
}

Matrix * sub_matrix(Matrix * a, Matrix * b){
    if (a->rows != b->rows & a->cols != b->cols){
        return NULL;
    }
    Matrix * c = matalloc(a->rows, a->cols);
    int i, j;

    for(i = 0; i < a->rows; i ++){
        for (j = 0; j < a->cols; j++) {
            c->pointer[i][j] = a->pointer[i][j] - b->pointer[i][j];
        }
    }
    return c;
}

Matrix * multiply_matrix(Matrix * a, Matrix * b){
    if (a->cols != b->rows) {
        return NULL;
    }else{
        Matrix * c = matalloc(a->rows, b->cols);
        int i, j, k;
        for (i = 0; i < c->rows; i ++) {
            for (j = 0; j < c->cols; j ++) {
                for (k = 0; k < a->cols; k ++) {
                    c->pointer[i][j] += (a->pointer[i][k])*(b->pointer[k][j]);
                }
            }
        }
        return c;
    }
}

Matrix * add_scalar_value(Matrix * a, float b){
    if (a == NULL) {
        return NULL;
    }
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->pointer[i][j] += b;
        }
    }
    return a;
}

float deteminant(Matrix * a) {
    if (a == NULL) {
        return INFINITY;
    }
    float det = 0;
    int i, j, k;
    Matrix * mat[a->cols];
    if(check_square_matrix(a)) {
        if (a->cols == 1) {
            return a->pointer[0][0];
        }
        for (i = 0; i < a->cols; i ++) {
            mat[i] = matalloc(a->cols - 1, a->rows - 1);
            for (j = 1; j <= mat[i]->cols; j ++) {
                for (k = 0; k < mat[i]->rows; k ++) {
                    if (k < i) {
                        mat[i]->pointer[j-1][k] = a->pointer[j][k];
                    }else{
                        mat[i]->pointer[j-1][k] = a->pointer[j][k+1];
                    }
                }
            }
            det += pow(-1, i+2)*a->pointer[0][i]*deteminant(mat[i]);
        }
        return det;
    }
    printf("Determinant of non-square matrix not possible\n");
    return INFINITY;
}

bool check_square_matrix(Matrix * a){
    return (a->cols == a->rows);
}

int main(){
    int r, c;
    Matrix * mat, * mat1, * mat2, * mat3;
    float ** mat_value, ** mat_value1;
    int i, j;
    r = 3;
    c = 3;
    mat = matalloc(r, c);
    mat1 = matalloc(3,4);

    mat = initialize_matrix(mat);
    mat1 = initialize_matrix(mat1);

    printf("mat\n");
    print_matrix(mat);
    printf("det(mat) = %f\n", deteminant(mat));

    mat_value1 = mat1->pointer;

    printf("Initial Matrix value\n");
    print_matrix(mat);
    
    printf("adding matrices\n");
    mat2 = add_matrix(mat, mat1);
    
    printf("multiplying matrices\n");
    mat3 = multiply_matrix(mat, mat1);
    printf("Matrix value after multiplication\n");
    print_matrix(mat3);
    
    mat3 = add_scalar_value(mat3, 4);
    printf("After adding scalar value\n");
    print_matrix(mat3);

    printf("After multiplying scalar value\n");
    mat3 = multiply_scalar_value(mat3, 2);
    print_matrix(mat3);

    return 0;
}