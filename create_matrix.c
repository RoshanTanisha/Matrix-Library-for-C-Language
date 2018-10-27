#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

/*
** creating matrix requires dimensions (#rows, #columns).
** Data Type is casted when the function returns the memory chunk
*/

Matrix * matalloc(int rows, int columns){
    Matrix * mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = columns;
    mat->pointer = (float **)calloc(mat->rows, sizeof(float));
    unsigned int i, j;
    // matrix = calloc(rows, size);
    for(i = 0; i < mat->rows; i ++){
        mat->pointer[i] = (float *)calloc(mat->cols, sizeof(float));
        for (j = 0; j < mat->cols; j ++) {
            mat->pointer[i][j] = i+j;
        }
    }
    return mat; 
}

Matrix * add_matrix(Matrix * a, Matrix * b){
    printf("a rows = %d, a cols %d, b rows %d, b cols %d\n", a->rows, a->cols, b->rows, b->cols);
    if(a->rows != b->rows & a->cols != b->cols){
        printf("a rows = %d, a cols %d, b rows %d, b cols %d\n", a->rows, a->cols, b->rows, b->cols);
        printf("Columns are not same");
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
    Matrix * d = matalloc(a->rows, a->cols);
    Matrix * c;
    int i, j;
    for (i = 0; i < a->rows; i ++) {
        for (j = 0; j < a->cols; j ++) {
            d->pointer[i][j] = -b->pointer[i][j];
        }
    }
    c = add_matrix(a, d);
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
                c->pointer[i][j] = 0;
                for (k = 0; k < a->cols; k ++) {
                    c->pointer[i][j] += a->pointer[i][k]*b->pointer[k][j];
                }
            }
        }
        return c;
    }
}

int main(){
    int r, c;
    Matrix * mat, * mat1, * mat2, * mat3;
    float ** mat_value, ** mat_value1;
    int i, j;
    r = 3;
    c = 3;
    mat = (Matrix*)matalloc(r, c);
    mat1 = (Matrix *)matalloc(3,4);
    mat_value = mat->pointer;
    mat_value1 = mat1->pointer;
    for(i = 0; i < r; i ++){
        for(j = 0; j < c; j ++){
            printf("%f\t", mat_value[i][j]);
        }
        printf("\n");
    }
    mat2 = add_matrix(mat, mat1);
    if(mat2 == NULL){
        printf("Matrix2 value is NULL\n");
    }else{
        for(i = 0; i < mat2->rows; i ++){
            for(j = 0; j < mat2->cols; j ++){
                printf("[%d][%d] = %f\t", i, j, mat2->pointer[i][j]);
            }
            printf("\n");
        }
    }
    mat3 = multiply_matrix(mat, mat1);
    for (i = 0; i < mat3->rows; i ++) {
        for (j = 0; j < mat3->cols; j ++) {
            printf("[%d][%d] = %f\t", i, j, mat3->pointer[i][j]);
        }
        printf("\n");
    }
    return 0;
}