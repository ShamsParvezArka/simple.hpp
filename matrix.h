#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAT_PRINT(m) mat_print(m, #m)
#define MAT_AT(m, i, j) (m).es[(i) * (m).cols + (j)]

typedef struct mat {
    size_t rows;
    size_t cols;
    size_t *es;
} Mat;

Mat mat_alloc(size_t rows, size_t cols);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_fill(Mat m);
void mat_print(Mat m, const char *name);

#endif // MATRIX_H/

#ifndef MATRIX_H_IMPLEMENTATION_

Mat mat_alloc(size_t rows, size_t cols)
{
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.es = malloc(sizeof(*m.es) * rows * cols);
    assert(m.es != NULL);

    return m;
}

void mat_fill(Mat m)
{
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++)
            MAT_AT(m, i, j) = 0;
    }
}

void mat_print(Mat m, const char *name)
{
    printf("%s = [\n", name);
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++)
            printf("  %zu ", MAT_AT(m, i, j));
        printf("\n");
    }
    printf("]\n");
}

void mat_sum(Mat dst, Mat a)
{
    assert(dst.rows == a.rows);
    assert(dst.cols == a.cols);
    for (size_t i = 0; i < dst.rows; i++) {
        for (size_t j = 0; i < dst.cols; j++)
            MAT_AT(dst, i, j) += MAT_AT(a, i, j);
    }
}

void mat_dot(Mat dst, Mat a, Mat b)
{
    assert(a.cols == b.rows);
    size_t n = a.cols;
    assert(dst.rows == a.rows);
    assert(dst.cols == a.cols);

    for (size_t i = 0; i < dst.rows; i++) {
        for (size_t j = 0; j < dst.cols; j++) {
            for (size_t k = 0; k < n; k++)
                MAT_AT(dst, i, j) += MAT_AT(a, i, k) * MAT_AT(b, k, j);
        }
    }
}

#endif // MATRIX_H_IMPLEMENTATION



