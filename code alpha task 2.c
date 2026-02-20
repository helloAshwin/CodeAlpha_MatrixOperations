#include <stdio.h>

#define MAX 10

// Function to read a matrix
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX],
                    int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX],
                     int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], transpose[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    readMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    readMatrix(B, r2, c2);

    // Matrix Addition
    if(r1 == r2 && c1 == c2) {
        addMatrix(A, B, result, r1, c1);
        printf("\nMatrix Addition Result:\n");
        printMatrix(result, r1, c1);
    } else {
        printf("\nMatrix Addition not possible (dimension mismatch)\n");
    }

    // Matrix Multiplication
    if(c1 == r2) {
        multiplyMatrix(A, B, result, r1, c1, c2);
        printf("\nMatrix Multiplication Result:\n");
        printMatrix(result, r1, c2);
    } else {
        printf("\nMatrix Multiplication not possible (c1 != r2)\n");
    }

    // Transpose of Matrix A
    transposeMatrix(A, transpose, r1, c1);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(transpose, c1, r1);

    return 0;
}
