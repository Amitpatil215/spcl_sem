#include <stdio.h>
// Function to swap position of elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high)
{
    // Select the pivot element
    int pivot = array[high];
    int i = (low - 1);
    // Put the elements smaller than pivot on the left
    // and greater than pivot on the right of pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // Select pivot position and put all the elements smaller
        // than pivot on left and greater than pivot on right
        int pi = partition(array, low, high);
        // Sort the elements on the left of pivot
        quickSort(array, low, pi - 1);
        // Sort the elements on the right of pivot
        quickSort(array, pi + 1, high);
    }
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
    quickSort(arr, 0, n1 - 1);
    printf("Output: \n");
    printArray(arr, n1);
}