#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINE 256  // maximum length of a line
#define WORD 30
#define numOfLine 250
#define INPUTSIZE 1024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getLine(char s[]) {
    int i, c;

    // Read characters from the standard input until a new line is reached
    c = getchar();
    for (i = 0; i < LINE - 1 && c != '\n'; i++) {
        c = getchar();
        s[i] = c;
    }

    // Add a null character to mark the end of the string
    s[i] = '\0';

    // Return the number of characters read
    return i;
}

int getWord(char w[]) {
    int i, c;

    // Read characters from the standard input until a new word is reached
    c = getchar();
    for (i = 0; i < WORD - 1 && c != ' '; i++) {
        c = getchar();
        w[i] = c;
    }

    // Add a null character to mark the end of the string
    w[i] = '\0';

    // Return the number of characters read
    return i;
}


//int getLine(char s[])
//{
//    int info;
//    int countWords = 0;
//
//    while (scanf("%lc", &info) == 1)
//    {
//        s[countWords] = info;
//        countWords++;
//        printf("%lc", info);
//        // array[index] = info;
//        // index++;
//    }
//    return 0;
//}

//int getWord(char w[])
//{
//    int info;
//    int countWords = 0;
//
//    while (scanf("%lc", &info) == 1)
//    {
//        if (info == '\n' || info == '\r' || info == ' ' || info == '\t')
//        {
//            return countWords;
//        }
//        w[countWords] = info;
//        countWords++;
//    }
//    return countWords;
//}

int substring(char *str1, char *str2) {
    char *res = strstr(str1, str2);
    if (res != NULL) {
        return 0;
    }
    return 1;
}

int similar(char *s, char *t, int n) {
    // Compare the two strings up to the given number of characters
    return strncmp(s, t, n);
}

void print_lines(int line, char text[INPUTSIZE][LINE], char *to_find) {

    for (int i = 1; i < line; i++) {
        if (substring(text[i], to_find) == 0) {
            printf("%s", text[i]);
        }
    }
}

void print_similar_words(int line, char text[INPUTSIZE][LINE], char *to_find) {

    char store[INPUTSIZE][WORD];

    // Iterate over the lines in the text array
    int index = 0;
    for (int i = 1; i < INPUTSIZE; i++) {
        // Tokenize the current line
        char *token = strtok(text[i], " ");

        // Iterate over the words in the current line
        while (token != NULL) {
            // Check if the token is similar to the string to find up to one character difference
            if (strncmp(token, to_find, 1) == 0) {
                strcpy(store[index], token);
                index++;
            }

            // Get the next word in the current line
            token = strtok(NULL, " ");
        }
    }

    for(int i = 0; i< index; i++){
        printf("%s" , store[i]);
    }

//    char *token;
//    for (int i = 2; i < line; i++) {
//        token = strtok(text[i], " ");
//        while (token != NULL) {
//
//            // Check if the token is similar to the string to find up to one character difference
//            if (strncmp(token, to_find, 1) == 0) {
//                printf("%s", token);
//            }
//
//
//            // Get the next token
//            token = strtok(NULL, " ");
//        }
//    }
}

int main() {

    //read the input file
    FILE *fp = fopen("find_inputb.txt", "r");
    if (fp == NULL) {
        printf("input file is null");
    }

    char text[INPUTSIZE][LINE];

    int line = 0;
    while (!feof(fp) && !ferror(fp)) {
        if (fgets(text[line], LINE, fp) != NULL) {
            line++;
        }
    }

    // Close the file
    fclose(fp);

    char to_find[WORD];
    char clause[WORD];

    sscanf(text[0], "%s %s", to_find, clause);

    //print the lines containing the specified string
    if (strcmp(clause, "a") == 0) {
        print_lines(line, text, to_find);
    }

    //print the words similar to the specified string
    if (strcmp(clause, "b") == 0) {
        print_similar_words(line, text, to_find);
    }
    printf("\n%s", "finished\n");

    return 0;

}


//    int info;
//    char wordArray[word];
//    char *containAllLines[numOfLine];
//    char option;
// int inWord = 0;

// int index = 0;

// Get the word to search.
//    int countWords = getWord(wordArray);
//    printf("\n");
//    for (int i = 0; i < countWords; i++)
//    {
//        printf("%c-", wordArray[i]);
//    }
//    // Get the option.
//    scanf("%lc", &option);
//    // Get 2 lines.
//    scanf("%lc", &info);
//    scanf("%lc", &info);

// while (scanf("%lc", &info) == 1)
// {
//     printf("%lc", info);
//     // array[index] = info;
//     // index++;
// }