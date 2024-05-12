#include <stdio.h>
int start[100], end[100];

void Activity(int s[], int e[], int n)
{
    int i, j, counter = 1;
    printf("The selected Activities are: \n");

    i = 0;
    printf("%d\t", i);

    for (j = 1; j < n; j++)
    {
        counter++;
        if (s[j] >= e[i])
        {
            printf("%d\t", j);
            i = j;
        }
    }
    printf("\nCounter: %d", counter);
}

void main()
{
    int i, j, k = 0, n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    printf("Enter the start time: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }
    printf("Enter the end time: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &end[i]);
    }

    // start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
    // The selected Activities are:
    // 0       1       3       4
    // Counter: 6
    Activity(start, end, n);
}

// Time Comlexity: O(N)