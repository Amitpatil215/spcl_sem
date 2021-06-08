

#include <stdio.h>

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {

        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter product id one by one in ascending order:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the PRODUCT_ID to be searched");
    scanf("%d", &x);
    int index = interpolationSearch(arr, 0, n - 1, x);

    if (index != -1)
        printf("PRODUCT_ID is present in the array at position %d", index + 1);
    else
        printf("PRODUCT_ID not found.");
    return 0;
}