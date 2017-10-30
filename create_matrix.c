#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

/*
** creating matrix requires dimensions (#rows, #columns) and data-type.
** Data Type is casted when the function returns the memory chunk
*/

void ** matalloc(int rows, int columns, size_t size){
    void ** matrix;
    unsigned int i;
    matrix = calloc(rows, size);
    for(i = 0; i < rows; i ++){
        matrix[i] = calloc(columns, size);
        printf("sizeof matrix[%d] : %d\n", i, sizeof(matrix[i]));
    }
    printf("sizeof matrix: %d\n", sizeof(matrix));
    return matrix;
}

int main(){
    int ** int_mat = (int **)matalloc(3,3, sizeof(int));
    int i, j;
    for(i = 0; i < 3; i ++){
        // int_mat[i] = (int *)int_mat[i];
        for(j = 0; j < 3; j ++){
            scanf("%d", &int_mat[i][j]);
        }
        // printf("%s", int_mat[i]);
    }

    for(i = 0; i < 3; i ++){
        for(j = 0; j < 3; j ++){
            printf("int_mat[%d][%d] = %d\n", i, j, int_mat[i][j]);
        }
    }
    printf("Sizeof int_mat: %d\n", sizeof(int_mat[0][0]));
    printf("sizeof(int): %d  sizeof(void): %d\n", sizeof(int), sizeof(void));
    return (0);
}
