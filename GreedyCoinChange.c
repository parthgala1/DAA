#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost, total_cost, coins, index = 0, counter = 0;
    printf("Enter the number of coins: ");
    scanf("%d", &coins);

    int coins_value[coins]; // Using a simple array instead of dynamic memory allocation

    printf("Enter the coin values:\n");
    for (int i = 0; i < coins; i++)
        scanf("%d", &coins_value[i]);

    printf("Enter the total value: ");
    scanf("%d", &cost);
    total_cost = cost;
    int coins_list[cost]; // Since the maximum number of coins can be equal to the cost

    for (int i = coins - 1; i >= 0; i--)
    {
        while (cost >= coins_value[i])
        {
            cost -= coins_value[i];
            coins_list[index++] = coins_value[i];
            counter++;
        }
    }

    printf("The selected coins for cost %d are: \n", total_cost);
    for (int i = 0; i < index; i++)
        printf("%d ", coins_list[i]);
    printf("\nMinimum number of coins required: %d\n", counter);

    return 0;
}
