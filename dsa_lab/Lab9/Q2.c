#include <stdio.h>
#include <stdlib.h>

int find(int arr[], int n, int i)
{
    int t = -1;
    for (int j = i; j < n; j++)
    {
        if (arr[i] < arr[j])
        {
            t = arr[j];
            printf("%d\n", t);
        }
    }
    return t;
}

void nextGreaterElement(int arr[], int n)
{
    int i = 0, temp, great;
    while (i < n)
    {
        temp = arr[i];
        great = find(arr, n, i);
        printf("%d --> %d\n", temp, great);
        i++;
    }
}

int main()
{
    int n;

    printf("Number of elements in array ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    nextGreaterElement(arr, n);
    return 0;
}