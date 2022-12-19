#ifndef ARRAY_SIZE
#define ARRAY_SIZE 50
#endif

int shift_element(int *arr, int i)
{
    for (int index = 0; index < i; index++)
    {
        // int *temp = *(arr + index + 1);
        // int *arr
    }
}

int insertion_sort(int *arr, int len)
{
}

int main()
{
    char info = '0';
    int array[ARRAY_SIZE];
    int index = 0;
    int min_dist_matrix_not_full = 0;
    int number = -1;
    int bool;
    while (scanf("%c", &info) == 1)
    {

        // Transform char number to int
        if (isdigit(info))
        {
            if (number == -1)
            {
                number = (info - '0');
            }
            else
            {
                number = number * 10 + (info - '0');
            }
        }

        else if (isspace(info))
        {

            if (number != -1)
            {
                array[index] = number;
            }
            number = -1;
        }
    }
    int i;

    shift_element(array, i);

    return 0;
}