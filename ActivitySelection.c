#include <stdio.h>
int start[100], end[100];

// void Sort(int s[], int n)
// {
//     int i, j;
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (s[j] > s[j + 1])
//             {
//                 // Swap the elements
//                 int temp = s[j];
//                 s[j] = s[i];
//                 s[i] = temp;
//             }
//         }
//     }
// }

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
    // Sort(start, n);
    // Sort(end, n);
    Activity(start, end, n);
}