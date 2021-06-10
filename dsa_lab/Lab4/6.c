#include<stdio.h>
#include<string.h>
int partition(int a[],int s, int e)
{
    int i=s,temp;
    int pivot = a[e];
    for(int j=s;j<=e-1;j++)
    {
        if(a[j]<pivot)
        {
           temp= a[i];
           a[i] = a[j];
           a[j]=temp;
           i++;
        }
    }
    temp = a[i];
    a[i]=a[e];
    a[e]=temp;
    return i;
}
void quickSort(int a[], int s, int e)
{
    if(s>=e)
        return ;
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
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
    quickSort(a,0,n-1);
    printf("\nsorted list of machine prices:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nCheapest machine cost : %d lacs",a[0]);
    printf("\nExpensive machine cost: %d lacs",a[n-1]);
    return 0;
}


