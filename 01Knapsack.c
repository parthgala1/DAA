#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int total_weight, n;
    printf("Enter the total elements: ");
    scanf("%d", &n);

    printf("Enter the total weight: ");
    scanf("%d", &total_weight);

    int weight[n], profit[n];

    printf("Enter the weight matrix:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the profit matrix:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    // Profit: 3 4 5 6
    // Weight: 2 3 1 4
    // Answer: Maximum 5

    int result_matrix[n + 1][total_weight + 1];

    for (int w = 0; w <= total_weight; w++)
        result_matrix[0][w] = 0;

    for (int i = 0; i <= n; i++)
        result_matrix[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total_weight; j++)
        {
            if (weight[i - 1] <= j)
                result_matrix[i][j] = max(result_matrix[i - 1][j], profit[i - 1] + result_matrix[i - 1][j - weight[i - 1]]);
            else
                result_matrix[i][j] = result_matrix[i - 1][j];
        }
    }

    printf("Maximum Value: %d\n", result_matrix[n][total_weight]);

    return 0;
}
