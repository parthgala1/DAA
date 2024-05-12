#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char text[MAX], pattern[MAX];
    int text_len, pattern_len, i, j, counter = 0;

    printf("Enter the text: ");
    scanf("%s", &text);

    printf("Enter the pattern: ");
    scanf("%s", &pattern);

    pattern_len = strlen(pattern);
    text_len = strlen(text);

    for (i = 0; i < text_len; i++)
    {
        counter = 0;
        for (j = 0; j < pattern_len; j++)
        {
            if (pattern[j] == text[i + j])
            {
                counter++;
            }
            else
                break;
        }
        if (counter == pattern_len)
            printf("\nPattern found at %d index", i);
    }
}