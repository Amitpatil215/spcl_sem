#include <stdio.h>

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

    for (i = 0; i < n; ++i)
    {
        if (a[i] == x)
            break;
    }

    if (i < n)
        printf("ITEM_ID is present in the array at position %d", i + 1);
    else
        printf("Element not found");

    return 0;
}