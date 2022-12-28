#include <stdio.h>
#include <ctype.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE 50
#endif

void shift_element(int *arr, int i)
{
    for (int index = i; index > 0; index--)
    {
        *(arr + index) = *(arr + index - 1);
    }
}

void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; ++i)
    {
        int key = *(arr + i);
        int j = i - 1;
        int k = 0;
        while (j >= 0 && *(arr + j) > key)
        {
            j = j - 1;
            k++;
        }

        shift_element(arr + j + 1, k);

        *(arr + i - k) = key;
        k = 0;
    }
}

int main()
{
    int info;
    int array[ARRAY_SIZE];
    int index = 0;

    while (scanf("%d", &info) == 1)
    {
        array[index] = info;
        index++;
    }

    insertion_sort(array, index);

    printf("%d", *(array));

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        printf(",%d", *(array + i));
    }
    return 0;
}