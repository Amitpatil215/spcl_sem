#include<stdio.h>
#include<string.h>
void bubblesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp= a[j];
                a[j]=a[j+1];
                a[j+1]= temp;
            }
        }
    }
}
int main()
{
    int a[10000],n,i;
    printf("Enter no. of inputs");
    scanf("%d",&n);
    printf("Array denoting pricing:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("\nsorted list of machine prices:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nCheapest machine cost : %d lacs",a[0]);
    printf("\nExpensive machine cost: %d lacs",a[n-1]);
    return 0;
}
