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
    bubblesort(c,n);
    printf("\nsorted list of machine prices:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}

