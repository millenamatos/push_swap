#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int array[] = {5, 8, 1, 2, 10, 21, 0};
    int size = sizeof(array) / sizeof(array[0]);
    int i = 0;

    bubbleSort(array, size);

    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    return (0);
}