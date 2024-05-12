#include <stdio.h>

#define MAX_JOBS 100

int profit[MAX_JOBS];

void print_schedule(int schedule[], int jobs)
{
    int counter = 0, sum = 0;
    printf("\n\nSelected Jobs: \n");
    for (int i = 0; i < jobs; i++)
    {
        if (schedule[i] != 0)
        {
            printf("J%d -> ", schedule[i]);
            counter++;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        sum += profit[i];
    }
    printf("\n\nTotal Profit: %d", sum);
}

void job_sequencing(int deadline[], int index[], int jobs)
{
    int schedule[MAX_JOBS];
    for (int i = 0; i < MAX_JOBS; i++)
        schedule[i] = 0;

    for (int i = 0; i < jobs; i++)
    {
        int j = deadline[i];
        while (j > 0 && schedule[j] != 0)
        {
            j--;
        }
        if (j > 0)
        {
            schedule[j] = index[i];
        }
    }
    printf("\nSchedule: ");
    for (int i = 0; i < jobs; i++)
        printf("%d ", schedule[i]);
    print_schedule(schedule, jobs);
}

int main()
{
    int jobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &jobs);

    int deadline[MAX_JOBS], index[MAX_JOBS];

    for (int i = 0; i < jobs; i++)
    {
        printf("Enter deadline and profit for J%d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
        index[i] = i + 1;
    }

    // Sort jobs by profit (descending order)
    for (int i = 0; i < jobs - 1; i++)
    {
        for (int j = 0; j < jobs - i - 1; j++)
        {
            if (profit[j] < profit[j + 1])
            {
                // Swap profit
                int temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                // Swap deadline
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;
                // Swap index
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    printf("\nIndex: ");
    for (int i = 0; i < jobs; i++)
        printf("%d ", index[i]);

    printf("\nProfits: ");
    for (int i = 0; i < jobs; i++)
        printf("%d ", profit[i]);

    printf("\nDeadline: ");
    for (int i = 0; i < jobs; i++)
        printf("%d ", deadline[i]);

    // Deadline: 2 2 1 3 1
    // Profits: 100 20 40 35 25
    // J3 -> J1 -> J4 ->

    job_sequencing(deadline, index, jobs);

    return 0;
}
