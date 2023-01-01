#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256 // maximum length of a line
#define WORD 30
#define numOfLine 250
#define INPUTSIZE 1024
#define TRUE 1
#define FALSE 0

int getLine(char s[])
{
    int i = 0;
    char c;

    // Read characters from the standard input until a new line is reached
    s[0] = '\0';
    c = getchar();
    for (i = 0; i < LINE - 1 && c != '\n'; i++)
    {
        // printf("--");
        s[i] = c;
        c = getchar();
    }

    // Add a null character to mark the end of the string
    s[i] = '\0';

    // Return the number of characters read
    return i;
}

int getWord(char w[])
{
    int i, c;

    // Read characters from the standard input until a new word is reached
    c = getchar();
    for (i = 0; i < WORD - 1 && c != ' ' && c != '\n' && c != '\0' && c != '\t'; i++)
    {
        w[i] = c;
        c = getchar();
    }

    // Add a null character to mark the end of the string
    w[i] = '\0';

    // Return the number of characters read
    return i;
}

// int getWord(char w[])
//{
//     int info;
//     int countWords = 0;
//
//     while (scanf("%lc", &info) == 1)
//     {
//         if (info == '\n' || info == '\r' || info == ' ' || info == '\t')
//         {
//             return countWords;
//         }
//         w[countWords] = info;
//         countWords++;
//     }
//     return countWords;
// }

int substring(char *str1, char *str2)
{
    char *res = strstr(str1, str2);
    if (res != NULL)
    {
        return TRUE;
    }
    return FALSE;
}

int similar(char *s, char *t, int n)
{
    // printf("*s: %s,  t: %s  ", s, t);
    int omitted = 0;
    int indexS = 0;
    int indexT = 0;
    // Iterate through both strings
    while (*s && *t)
    {
        // If the characters are different, increment the omitted count
        if (*s != *t)
        {
            omitted++;
            s++;

            // If we have omitted more than n characters, return false
            if (omitted > n)
            {
                return FALSE;
            }
            continue;
        }

        // Move to the next character in both strings
        s++;
        t++;
    }
    for (int i = omitted; i < n; i++)
    {
        s++;
    }

    // If we have reached the end of both strings, return true
    // If we have reached the end of only one of the strings, return false
    return !*s && !*t;
}

void print_lines(char *str)
{
    char containAllLines[numOfLine] = {0};

    for (int i = 0; i < 5; i++)
    {
        int countLine = getLine(containAllLines);

        // printf("%c    %d\n", containAllLines[0], countLine);
        // if (containAllLines[0] == "\0" || containAllLines[0] == " " || containAllLines[0] == "\n" || containAllLines[0] == "\t")
        // {
        //     printf("\nhello");
        // }
        if (substring(containAllLines, str) == TRUE)
        {
            printf("%s\n", containAllLines);
        }
    }
}

void print_similar_words(char *str)
{
    char info;

    char containAllLines[numOfLine] = {0};
    char word[WORD];

    while (scanf("%c", &info) == 1)
    {
        word[0] = info;
        int lines = getWord(word + 1);
        if (similar(word, str, 1) == 1)
        {
            printf("%s\n", word);
        }
    }
}

int main()
{
    int info;
    char wordArray[WORD];
    char containAllLines[numOfLine];
    char option;
    int inWord = 0;

    int index = 0;

    // Get the word to search.
    int countWords = getWord(wordArray);

    // Get the option.
    scanf("%c", &option);
    // Get 2 lines.
    scanf("%lc", &info);
    scanf("%lc", &info);

    // getLine(containAllLines);
    index++;
    if (option == 'a')
    {
        print_lines(wordArray);
    }

    else if (option == 'b')
    {
        print_similar_words(wordArray);
    }
    return 0;
}