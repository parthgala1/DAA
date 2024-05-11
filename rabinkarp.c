#include <stdio.h>
#include <string.h>
#include <math.h>

int hash(char pattern[])
{
    int hash = 0;
    for (int i = 0; i < strlen(pattern); i++)
    {
        hash += (pattern[i] - 0);
    }
    return hash;
}

int checkPattern(char text[], char pattern[], int index)
{
    int patternLen = strlen(pattern);
    for (int i = 0; i < patternLen; i++)
    {
        if (text[index + i] != pattern[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int count = 0;

    int hashedPattern = hash(pattern);
    printf("Hashed Pattern is: %d\n", hashedPattern);

    for (int i = 0; i <= textLen - patternLen; i++)
    {
        char subString[patternLen];
        for (int j = 0; j < patternLen; j++)
        {
            subString[j] = text[i + j];
        }
        subString[patternLen] = '\0';
        int hashedSubString = hash(subString);
        // checkPattern(text, pattern, i);
        if (hashedSubString == hashedPattern)
        {
            printf("\n");
            printf("Substring: %s\n", subString);
            printf("Hashed Substring: %d\n", hashedSubString);
            count++;
            if (checkPattern(text, pattern, i))
            {
                printf("Pattern found at index: %d\n", i);
                count--;
            }
            else
            {
                printf("Spurious Hit\n");
            }
        }
    }
    printf("\n");
    printf("Total Spurious Hits: %d\n", count);

    return 0;
}