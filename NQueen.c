#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int N;

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check if there's a queen in the same row to the left
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nQueens(int board[N][N], int col)
{
    if (col >= N)
    {
        printBoard(board);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1; // Place queen
            nQueens(board, col + 1);
            board[i][col] = 0; // Backtrack
        }
    }
}

int main()
{
    int board[MAX][MAX];
    printf("Enter the number of Queens: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    printf("All solutions for 4 queens problem:\n");
    nQueens(board, 0);
    return 0;
}

// Time Comllexity: O(N!)