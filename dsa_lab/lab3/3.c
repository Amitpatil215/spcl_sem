#include<stdio.h>

int main()
{
    int n, a[1000],i,j,key,sum=0;
    printf("Enter number of candidates:");
    scanf("%d",&n);
    printf("Enter age of each candidate:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        key =a[i];
        j= i-1;
        while(j>=0 && a[j] >key)
        {
           a[j+1]=a[j];
           j=j-1;
        }
        a[j+1]= key;
    }
    printf("\nSorted list of candidate age:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<n;i++)
    {
        sum = sum+a[i];
    }
    int av= sum/n;
    printf("\nMinimum Aged Candidate:%d",a[0]);
    printf("\nMaximum Aged Candidate:%d",a[n-1]);
    printf("\nAverage age of the candidates: %d",av);
    return 0;
}

