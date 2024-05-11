#include <stdio.h>
void maxmin(int a[], int lb, int ub, int *max, int *min)
{
    if (lb = ub)
    {
        *max = *min = a[lb];
        return;
    }
    else if (ub - lb == 1)
    {
        if (a[lb] > a[ub])
        {
            *max = a[lb];
            *min = a[ub];
        }
        else
        {
            *max = a[ub];
            *min = a[lb];
        }
        return;
    }
    int mid = (lb + ub) / 2;
    int left_max, left_min, right_max, right_min;
    maxmin(a, lb, mid, &left_max, &left_min);
    maxmin(a, mid + 1, ub, &right_max, &right_min);
    *max = (left_max > right_max) ? left_max : right_max;
    *min = (left_min < right_min) ? left_min : right_min;
}
int main()
{
    int length;
    printf("Enter length of array: ");
    scanf("%d", &length);
    int a[length];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    int max, min;
    maxmin(a, 0, length - 1, &max, &min);
    printf("Max is: %d\n", max);
    printf("Min is: %d\n", min);
    return 0;
}