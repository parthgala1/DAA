#include <stdio.h>

int coin_change_dynamic(int *coins_value, int total_value, int coins)
{
    int result_matrix[total_value + 1];
    int solution_matrix[total_value + 1];

    result_matrix[0] = 0;
    solution_matrix[0] = 0;

    for (int j = 1; j <= total_value; j++)
    {
        int minimum = 10000; // Initializing with a large value
        int coin = 0;

        for (int i = 0; i < coins; i++)
        {
            if (j >= coins_value[i])
            {
                if ((1 + result_matrix[j - coins_value[i]]) < minimum)
                {
                    minimum = 1 + result_matrix[j - coins_value[i]];
                    coin = i;
                }
            }
        }
        result_matrix[j] = minimum;
        solution_matrix[j] = coin;
    }

    printf("Selected coins:\n");
    int value = total_value;
    while (value > 0)
    {
        printf("%d ", coins_value[solution_matrix[value]]);
        value -= coins_value[solution_matrix[value]];
    }

    return result_matrix[total_value];
}

int main()
{
    int coins, total_value;
    printf("Enter the number of coins: ");
    scanf("%d", &coins);

    int coins_value[coins];
    printf("Enter the value of coins:\n");
    for (int i = 0; i < coins; i++)
        scanf("%d", &coins_value[i]);

    printf("Enter the total value: ");
    scanf("%d", &total_value);

    int min_coins = coin_change_dynamic(coins_value, total_value, coins);
    printf("\nMinimum number of coins required: %d\n", min_coins);

    return 0;
}
