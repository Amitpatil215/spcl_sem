#include <stdio.h>
#include <string.h>

int main()
{

    int n;
    char x[50][50];
    printf("Enter number of elements of an array PROTEIN:");
    scanf("%d", &n);

    printf("Enter protein elements:: ");

    for (int i = 0; i < n; ++i)
        scanf("%s", &x[i]);

    char s[100];
    printf("Enter ELEMENT to search::");
    scanf("%s", &s);

    int len = n;
    int j;

    for (j = 0; j < len ; j++)
    {
        if (!strcmp(x[j], s))
        {
            printf("Protein element found at location %d", j+1);
            break;
        }
    }
    return 0;
}