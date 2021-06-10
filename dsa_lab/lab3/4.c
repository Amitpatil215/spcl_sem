#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

 void selectionSort(char a[][MAX_LEN],int n)
 {
     int i, item;
     char ele[MAX_LEN];
     for(item =1;item<n;item++)
     {
         strcpy(ele,a[item]);
         i= item-1;
         while(i>=0 && strcmp(a[i],ele)>0)
         {
             strcpy(a[i+1],a[i]);
             i--;
         }
         strcpy(a[i+1],ele);
     }
 }
  int main()
  {
      char arr[1000][MAX_LEN];
      int n,i,j;
      printf("Enter no. of Name of Car Brands");
      scanf("%d",&n);
      printf("Given array is\n");
      for(i=0;i<n;i++)
      {
          printf("%d:",i);
          scanf("%s",arr[i]);
      }
      selectionSort(arr,n);
      printf("\nSorted array is\n");
      for(i=0;i<n;i++)
      {
          printf("%d %s\n",i,arr[i]);
      }
      char ch;
      printf("Find the Car brand starting with specific alphabet:");
      getchar();
      scanf("%c",&ch);
      for(i=0;i<n;i++)
      {
          if(arr[i][0]==ch)
          {
              printf("Car brand is: %s", arr[i]);
          }
      }
      return 0;
  }

