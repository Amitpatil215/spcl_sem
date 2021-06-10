#include<stdio.h>
#include<string.h>
void merge(int x[],int y[],int a[],int s,int e){
       int mid = (s+e)/2;
       int i=s;
       int j = mid+1;
       int k = s;
       while(i<=mid && j<=e){
           if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
           }else{
             a[k] = y[j];
             j++;
             k++;
           }
       }
       while(i<=mid){
        a[k] = x[i];
        k++;
        i++;
       }
       while(j<=e){
        a[k] = y[j];
        k++;
        j++;
       }
}

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    int x[100],y[100];
    for(int i=s;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    merge(x,y,a,s,e);
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
    mergeSort(a,0,n-1);
    printf("\nsorted list of machine prices:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nCheapest machine cost : %d lacs",a[0]);
    printf("\nExpensive machine cost: %d lacs",a[n-1]);
    return 0;
}

