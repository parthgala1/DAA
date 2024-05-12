#include <stdio.h>

#define MAX_LENGTH 100
#define INF 10000

int min(int a, int b)
{
    return a > b ? b : a;
}

void print_solution(int matrix[MAX_LENGTH][MAX_LENGTH], int length)
{
    printf("\nSolution: \n");
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void floyd_algorithm(int matrix[MAX_LENGTH][MAX_LENGTH], int length)
{
    for (int k = 0; k < length; k++)
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    print_solution(matrix, length);
}

int main()
{
    int length;
    printf("Enter the length of the matrix: ");
    scanf("%d", &length);

    if (length > MAX_LENGTH)
    {
        printf("Matrix length exceeds maximum limit\n");
        return 1;
    }

    int matrix[MAX_LENGTH][MAX_LENGTH];

    printf("\nEnter the matrix: \n");
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == -1)
                matrix[i][j] = INF;
        }
    }

    floyd_algorithm(matrix, length);

    return 0;
}
