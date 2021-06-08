#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function for calculating mean
double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return (double)sum / (double)n;
}

// Function for calculating median
double findMedian(int a[], int n)
{
    // First we sort the array
    qsort(a, 5, sizeof(int), cmpfunc);

    // check for even case
    if (n % 2 != 0)
        return (double)a[n / 2];

    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

// Driver code
int main()
{
    int a[100],n;
    printf("Enter the number N");
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    // Function call
    printf("Mean %f", findMean(a, n));
    printf("\n");
    printf("Median %f", findMedian(a, n));

    return 0;
}
