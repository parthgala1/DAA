#include<stdio.h>

void multiply(int A[2][2], int B[2][2], int C[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Matrix C is: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
}

void strassen(int A[2][2],int B[2][2],int C[2][2])
{
    int p1, p2, p3, p4, p5, p6, p7;
    p1 = A[0][0] * (B[0][1] - B[1][1]);
    p2 = B[1][1] * (A[0][0] + A[0][1]);
    p3 = B[0][0] * (A[1][0] + A[1][1]);
    p4 = A[1][1] * (B[1][0] - B[0][0]);
    p5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    p6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    p7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);
    
    //Calculating C11,C12,C21 and C22
    C[0][0]=p4 + p5 + p6 - p2;
    C[0][1]=p1 + p2;
    C[1][0]=p3 + p4;
    C[1][1]=p1 - p3 + p5 - p7;

    printf("Strassen's Multiplication C: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d", C[i][j]);
        }
        printf("\n");

    }
}

int main(){
    int A[2][2], B[2][2], C[2][2];
    printf("Enter the first Matrix: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the second Matrix: \n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    multiply(A, B, C);
    strassen(A, B, C);
    return 0;
}