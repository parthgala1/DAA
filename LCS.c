#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b)
{
    return a > b ? a : b;
}

int longest_common_subsequence(char *str1, char *str2, char *lcs)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int LCS[MAX + 1][MAX + 1];

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    int index = LCS[len1][len2];
    lcs[index] = '\0';

    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[--index] = str1[i - 1];
            i--;
            j--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    return strlen(lcs);
}

int main()
{
    char str1[MAX], str2[MAX], lcs[MAX];

    printf("Enter string 1: ");
    scanf("%99s", str1);

    printf("Enter string 2: ");
    scanf("%99s", str2);

    // str1: AGGTAB
    // str2: GXTXAYB
    // LCS: GTAB
    // Length: 4

    int lcs_length = longest_common_subsequence(str1, str2, lcs);
    printf("Length of longest common subsequence: %d\n", lcs_length);
    printf("Longest common subsequence: %s\n", lcs);

    return 0;
}
