#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Check if a string and a filename were provided
    if (argc < 3) {
        printf("Error: No string or filename provided\n");
        return 1;
    }

    // Get the string and the filename from the command line arguments
    char *string = argv[1];
    char *filename = argv[2];

    // Open the file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // File could not be opened
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read the lines from the file and print the ones that contain the string
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((getline(&line, &len, fp)) != -1) {
        // Check if the line contains the string
        if (strstr(line, string) != NULL) {
            // Print the line
            printf("%s", line);
        }
    }

    // Close the file
    fclose(fp);

    // Free the memory allocated by getline()
    free(line);

    return 0;
}




// #include "main.h"
// #include "isort.c"
// #include "txtfind.c"
// #include <stdio.h>
// #include <ctype.h>
// #ifndef MATRIX_SIZE
// #define MATRIX_SIZE 10
// #endif

// #ifndef PATH_SIZE
// #define PATH_SIZE 2
// #endif

// int main()
// {
//     char info = '0';
//     char current_letter;
//     int matrix[MATRIX_SIZE][MATRIX_SIZE];
//     int min_dist_matrix[MATRIX_SIZE][MATRIX_SIZE];
//     int exist_path[PATH_SIZE];
//     int current_i = 0;
//     int current_j = 0;
//     int min_dist_matrix_not_full = 0;
//     int number = -1;
//     int bool;
//     while (scanf("%c", &info) == 1)
//     {
//         if (isalpha(info))
//         {
//             if (info == 'A')
//             {
//                 min_dist_matrix_not_full = 0;
//             }
//             current_letter = info;
//             current_i = 0;
//             current_j = 0;
//         }

//         // Transform char number to int
//         else if (isdigit(info))
//         {
//             if (number == -1)
//             {
//                 number = (info - '0');
//             }
//             else
//             {
//                 number = number * 10 + (info - '0');
//             }
//         }

//         else if (isspace(info))
//         {
//             if (current_letter == 'A')
//             {
//                 if (number != -1)

//                 // Get matrices from user
//                 {
//                     matrix[current_i][current_j] = number;
//                     if (current_j >= 9)
//                     {
//                         current_j = 0;
//                         current_i++;
//                     }
//                     else
//                     {
//                         current_j++;
//                     }
//                 }
//             }
//             else if (current_letter == 'B')
//             {
//                 if (number != -1)
//                 {
//                     // Get i, j to check if there ia a path between i and j
//                     if (current_i < 2)
//                     {
//                         exist_path[current_i] = number;
//                         current_i++;
//                     }
//                     if (current_i == 2)
//                     {
//                         bool = existingPath(exist_path[0], exist_path[1], matrix, min_dist_matrix, min_dist_matrix_not_full);
//                         min_dist_matrix_not_full = 1;
//                         if (bool == 0)
//                         {
//                             printf("False\n");
//                         }
//                         else if (bool == 1)
//                         {
//                             printf("True\n");
//                         }
//                     }
//                 }
//             }

//             else if (current_letter == 'C')
//             {
//                 if (number != -1)
//                 {
//                     // Get i, j to receive the shortest course between them, else return -1
//                     if (current_i < 2)
//                     {
//                         exist_path[current_i] = (int)(number);
//                         current_i++;
//                     }
//                     if (current_i == 2)
//                     {
//                         int num = shortestCourse(exist_path[0], exist_path[1], matrix, min_dist_matrix, min_dist_matrix_not_full);
//                         min_dist_matrix_not_full = 1;
//                         if (num == 0)
//                         {
//                             printf("-1\n");
//                         }
//                         else
//                         {
//                             printf("%d\n", num);
//                         }
//                     }
//                 }
//             }
//             else if (current_letter == 'D')
//             {
//                 return 0;
//             }
//             number = -1;
//         }
//     }
//     return 0;
// }