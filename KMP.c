#include <stdio.h>
#include <string.h>
#define MAX 100
// ababa
// 0 0 1 2 3 
// Function to compute the prefix array for the pattern
void computePrefix(char *pattern, int patternLength, int *prefixArray)
{
    int length = 0;
    prefixArray[0] = 0;

    for (int i = 1; i < patternLength; i++)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            prefixArray[i] = length;
        }
        else
        {
            if (length != 0)
            {
                length = prefixArray[length - 1];
                i--; // Decrement i to recheck current character
            }
            else
            {
                prefixArray[i] = 0;
            }
        }
    }
}

// Function to perform pattern matching using KMP algorithm
void searchPattern(char *pattern, char *text)
{
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int prefixArray[patternLength];

    computePrefix(pattern, patternLength, prefixArray);

    int i = 0, j = 0;
    while (i < textLength)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == patternLength)
        {
            printf("Pattern found at index %d\n", i - j);
            j = prefixArray[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = prefixArray[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    printf("Pattern search ended\n");
}

int main()
{
    char text[MAX], pattern[MAX];

    printf("Enter the text: ");
    scanf("%s", &text);

    printf("Enter the pattern: ");
    scanf("%s", &pattern);

    // text: ABABDABACDABABCABAB
    // pattern: AB
    searchPattern(pattern, text);

    return 0;
}

// Time Comlexity: O(N + M)
// N: Pattern and M: Text