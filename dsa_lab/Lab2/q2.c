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

int main()
{
    int a[100], b[100], n, m;
    printf("Enter the number in A1");

    scanf("%d", &n);
    printf("Enter the elements in A1");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    /// for array a2
    printf("Enter the number in A2");

    scanf("%d", &m);
    printf("Enter the elements in A2");
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &b[i]);
    }

    /// merging two arrays
    for (int i = 0; i < m; i++)
    {
        a[n + i] = b[i];
    }

    // printing merged array
    // for (int i = 0; i< m+n; i++)
    // {
    //     printf("%d",a[i]);
    // }

    // Function call
    printf("Mean %f", findMean(a, m+n));
    printf("\n");
    printf("Median %f", findMedian(a, m+n));

    return 0;
}
