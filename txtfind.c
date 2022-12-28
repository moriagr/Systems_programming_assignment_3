#include <stdio.h>
#include <ctype.h>

#define line 256
#define word 30
#define numOfLine 250

int getLine(char s[])
{
    int info;
    int countWords = 0;

    while (scanf("%lc", &info) == 1)
    {
        s[countWords] = info;
        countWords++;
        printf("%lc", info);
        // array[index] = info;
        // index++;
    }
    return 0;
}

int getword(char w[])
{
    int info;
    int countWords = 0;

    while (scanf("%lc", &info) == 1)
    {
        if (info == '\n' || info == '\r' || info == ' ' || info == '\t')
        {
            return countWords;
        }
        w[countWords] = info;
        countWords++;
    }
    return countWords;
}

int substring(char *str1, char *str2)
{
    return 0;
}

int similar(char *s, char *t, int n)
{
    return 0;
}

void print_lines(char *str)
{
}

void print_similar_words(char *str)
{
}

int main()
{
    int info;
    char wordArray[word];
    char *containAllLines[numOfLine];
    char option;
    // int inWord = 0;

    // int index = 0;

    // Get the word to search.
    int countWords = getword(wordArray);
    printf("\n");
    for (int i = 0; i < countWords; i++)
    {
        printf("%c-", wordArray[i]);
    }
    // Get the option.
    scanf("%lc", &option);
    // Get 2 lines.
    scanf("%lc", &info);
    scanf("%lc", &info);

    // while (scanf("%lc", &info) == 1)
    // {
    //     printf("%lc", info);
    //     // array[index] = info;
    //     // index++;
    // }

    return 0;
}