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
    int inputArray[][4] = {{15, 15, 25, 35},
                           {10, 20, 30, 40},
                           {20, 25, 30, 40}};

    int n = sizeof(inputArray) / sizeof(inputArray[0][0]);
    int c[n],k=0;
    for(int i=0;i<n/4;i++)
    {
        for(int j=0;j<4;j++)
        {
            c[k++] = inputArray[i][j];
        }
    }
    int n1 = sizeof(c) / sizeof(c[0]);
    quickSort(c,0,n1-1);
    printf("\nsorted list of machine prices:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}


