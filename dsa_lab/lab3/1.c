#include<stdio.h>

int main()
{
    int n, a[1000],i,j,position,temp;
    printf("Enter the Number of Subjects:");
    scanf("%d",&n);
    printf("Enter 5 Subject Marks:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        position =i;
        for(j=i+1;j<n;j++)
        {
            if(a[position]>a[j])
            {
                position =j;
            }
        }
        if(position!= i)
        {
            temp = a[i];
            a[i]=a[position];
            a[position]=temp;
        }
    }
    printf("\nThe Sorted array in ascending order:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nMinimum marks scored is:%d",a[0]);
    printf("\nMaximum marks scored is:%d",a[n-1]);
    return 0;
}
