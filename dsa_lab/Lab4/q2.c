#include <stdio.h>
// Function to swap position of elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
// Function to print elements of an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
// Driver code
int main()
{
    int inputArray[][4] = {{15, 15, 25, 35},
                           {10, 20, 30, 40},
                           {20, 25, 30, 40}};

    int n = sizeof(inputArray) / sizeof(inputArray[0][0]);

    int arr[n], k = 0;

    for (int i = 0; i < n / 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[k++] = inputArray[i][j];
        }
    }
    int n1 = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,n1);
    printf("Output: \n");
    printArray(arr, n1);
}