// C program to implement interpolation search
// with recursion
#include <stdio.h>

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

// Driver Code
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

    int x; // Element to be searched
    printf("Enter the PRODUCT_ID to be searched");
    scanf("%d", &x);
    int index = interpolationSearch(arr, 0, n - 1, x);

    // If element was found
    if (index != -1)
        printf("PRODUCT_ID is present in the array at position %d", index + 1);
    else
        printf("PRODUCT_ID not found.");
    return 0;
}