#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int m[][MAX], int rows, int cols);
void displayMatrix(int m[][MAX], int rows, int cols);
void addMatrix(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols);
void multiplyMatrix(int a[][MAX], int b[][MAX], int result[][MAX], int r1, int c1, int c2);
void transposeMatrix(int a[][MAX], int result[][MAX], int rows, int cols);

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("MATRIX OPERATIONS MENU\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n--- Matrix Addition ---\n");
            printf("Enter rows and columns (same for both matrices): ");
            scanf("%d %d", &r1, &c1);

            printf("\nEnter elements of first matrix:\n");
            inputMatrix(a, r1, c1);

            printf("\nEnter elements of second matrix:\n");
            inputMatrix(b, r1, c1);

            addMatrix(a, b, result, r1, c1);

            printf("\nFirst Matrix:\n");
            displayMatrix(a, r1, c1);
            printf("\nSecond Matrix:\n");
            displayMatrix(b, r1, c1);
            printf("\nSum Matrix:\n");
            displayMatrix(result, r1, c1);
            break;

        case 2:
            printf("\n--- Matrix Multiplication ---\n");
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("\nError! Multiplication not possible.\n");
                printf("Columns of first matrix must equal rows of second matrix.\n");
                break;
            }

            printf("\nEnter elements of first matrix:\n");
            inputMatrix(a, r1, c1);

            printf("\nEnter elements of second matrix:\n");
            inputMatrix(b, r2, c2);

            multiplyMatrix(a, b, result, r1, c1, c2);

            printf("\nFirst Matrix:\n");
            displayMatrix(a, r1, c1);
            printf("\nSecond Matrix:\n");
            displayMatrix(b, r2, c2);
            printf("\nProduct Matrix:\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            printf("\n--- Matrix Transpose ---\n");
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("\nEnter elements of matrix:\n");
            inputMatrix(a, r1, c1);

            transposeMatrix(a, result, r1, c1);

            printf("\nOriginal Matrix:\n");
            displayMatrix(a, r1, c1);
            printf("\nTranspose Matrix:\n");
            displayMatrix(result, c1, r1);
            break;

        default:
            printf("\nInvalid choice! Please select 1, 2, or 3.\n");
    }

    return 0;
}

// Reads elements into a matrix
void inputMatrix(int m[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Prints a matrix in row-column format
void displayMatrix(int m[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// Adds two matrices of the same dimensions
void addMatrix(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Multiplies matrix a (r1 x c1) with matrix b (c1 x c2)
void multiplyMatrix(int a[][MAX], int b[][MAX], int result[][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Transposes a matrix (rows x cols -> cols x rows)
void transposeMatrix(int a[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = a[i][j];
        }
    }
}
