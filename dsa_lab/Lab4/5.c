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
    mergeSort(c,0,n1-1);
    printf("\nsorted list of machine prices:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}


