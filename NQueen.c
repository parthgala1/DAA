#include <stdio.h>
#include <stdbool.h>

bool isSafe(int board[][8], int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool nQueens(int board[][8], int col, int n)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            if (nQueens(board, col + 1, n))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int board[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    if (nQueens(board, 0, n))
    {
        printf("Solution exists\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Solution does not exist\n");
    }
    return 0;
}