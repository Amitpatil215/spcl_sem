#include <stdio.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int a[20], i, x, n;
    printf("Enter the number of ITEM_ID?");
    scanf("%d", &n);

    printf("Enter the ITEM_ID one by one: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the ITEM_ID to be searched:");
    scanf("%d", &x);

    qsort(a, 5, sizeof(int), cmpfunc);

    int first = 0;
    int last = n - 1;
    int middle = (first + last) / 2;

    while (first <= last)
    {
        if (a[middle] < x)
            first = middle + 1;
        else if (a[middle] == x)
        {
            printf("ITEM_ID is present in the array at position %d", middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", x);

    return 0;
}