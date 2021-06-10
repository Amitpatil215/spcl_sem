#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

 void selectionSort(char a[][MAX_LEN],int n)
 {
     int i,j,min_i;
     char min_str[MAX_LEN],temp[MAX_LEN];
     for(i=0;i<n-1;i++)
     {
         int min_i= i;
         strcpy(min_str,a[i]);
         for(j=i+1;j<n;j++)
         {
             if(strcmp(min_str,a[j])>0)
             {
                 strcpy(min_str,a[j]);
                 min_i = j;
             }
         }
         if(min_i!=i)
         {
            strcpy(temp,a[i]);
            strcpy(a[i],a[min_i]);
            strcpy(a[min_i],temp);
         }
     }
 }
 void search(char a[][MAX_LEN],int n)
 {
    char ch;
    int i;
      printf("Find the Car brand starting with specific alphabet:");
      getchar();
      scanf("%c",&ch);
      for(i=0;i<n;i++)
      {
          if(a[i][0]==ch)
          {
              printf("Car brand is: %s", a[i]);
              break;
          }
      }
 }
  int main()
  {
      char arr[1000][MAX_LEN];
      int n =3,i,j;
      //printf("Enter no. of Name of Car Brands");
      //scanf("%d",&n);
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
      search(arr,n);
      return 0;
  }
