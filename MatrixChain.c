// See the Cormen book for details of the following
// algorithm
#include <limits.h>
#include <stdio.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            m[i][j] = 0;

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    // Print the matrix m[][]
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    return m[1][n - 1];
}

// Driver code
int main()
{
    int arr[] = {4, 5, 3, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("SIze of the array: %d\n", size);

    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(arr, size));

    getchar();
    return 0;
}
