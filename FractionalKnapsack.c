#include <stdio.h>
#define MAX 100

void sort(int profit[], int weight[], float ratio[], int n)
{
    int i, j, temp;
    float fl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                fl = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = fl;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, profit[MAX], weight[MAX], capacity, n;
    float select[MAX], total_profit = 0.0, ratio[MAX];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the Profit and its respective Weights: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
        scanf("%d", &weight[i]);
    }

    // Profit (P): 5 10 15 7 8 9 4

    // Weight(w):  1 3 5 4 1 3 2

    // W (Weight of the knapsack): 15

    // Answer:
    // Profit: 8       5       10      15      9       4       7
    // Weight: 1       1       3       5       3       2       4
    // Ratio:  8.00    5.00    3.33    3.00    3.00    2.00    1.75
    // Capacity 14      13      10      5       2
    // Select: 1.00    1.00    1.00    1.00    1.00    1.00    0.00
    // Total Profit in fractional Knapsack problem is: 51.0000

    printf("Enter the Capacity of the bag: ");
    scanf("%d", &capacity);

    for (i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    sort(profit, weight, ratio, n);

    // Profits
    for (i = 0; i < n; i++)
    {
        select[i] = 0;
        printf("%d\t", profit[i]);
    }
    printf("\n");

    // Weights
    for (i = 0; i < n; i++)
        printf("%d\t", weight[i]);
    printf("\n");

    // Ratio = Profit/Weight
    for (i = 0; i < n; i++)
        printf("%.2f\t", ratio[i]);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (capacity > weight[i])
        {
            select[i] = 1;
            capacity -= weight[i];
        }
        else
        {
            select[i] = (float)capacity / weight[i];
            break;
        }
        // Capacity
        printf("%d\t", capacity);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        total_profit += select[i] * profit[i];
        // Select
        printf("%.2f\t", select[i]);
    }

    printf("\nTotal Profit in fractional Knapsack problem is: %.4f", total_profit);
}