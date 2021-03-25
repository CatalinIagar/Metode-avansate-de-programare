#include <iostream>
#include <time.h>

void multiply_matrix(int matrix[][128], int matrix2[][128], int row, int power);
void multiply_matrix_recursive(int row, int matrix[][128], int matrix2[][128], int result[][128]);

int main()
{
    srand(time(NULL));
    int matrix[128][128];

    int row, power;
    std::cout << "Introduceti numarul de linii si de coloane: ";
    std::cin >> row;
    std::cout << "Introduceti puterea la care doriti sa ridicati matricea: ";
    std::cin >> power;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix[i][j] = rand() % 9;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int matrix2[128][128];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix2[i][j] = matrix[i][j];
        }
    }

    if (power <= 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        multiply_matrix(matrix, matrix2, row, power);
    }
    system("pause");
}

void multiply_matrix(int matrix[][128], int matrix2[][128], int row, int power)
{
    if (power == 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        int result[128][128];
        multiply_matrix_recursive(row, matrix, matrix2, result);
        power--;
        multiply_matrix(matrix, matrix2, row, power);
    }
}

void multiply_matrix_recursive(int row, int matrix[][128], int matrix2[][128], int result[][128])
{
    static int i = 0, j = 0, k = 0;

    if (i >= row)
    {
        for (int m = 0; m < row; m++)
        {
            for (int n = 0; n < row; n++)
            {
                matrix[n][j] = result[m][n];
            }
        }
        return;
    }

    if (j < row)
    {
        if (k < row)
        {
            result[i][j] += matrix[i][k] * matrix2[k][j];
            k++;

            multiply_matrix_recursive(row, matrix, matrix2, result);
        }

        k = 0;
        j++;
        multiply_matrix_recursive(row, matrix, matrix2, result);
    }

    j = 0;
    i++;
    multiply_matrix_recursive(row, matrix, matrix2, result);
}