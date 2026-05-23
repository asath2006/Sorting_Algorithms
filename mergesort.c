#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int temp[100];
    while(i<=mid&&j<=high)
    {
      if(a[i]<a[j])
      {
        temp[k]=a[i];
        i++;
        }
       else
       {
         temp[k]=a[j];
         j++;
       }
       k++;
      }
      while(i<=mid)
      {
         temp[k]=a[i];
         k++;
         i++;
     }
     while(j<=high)
     {
        temp[k]=a[j];
        k++;
        j++;
     }
     for(int i=low;i<=high;i++)
     {
       a[i]=temp[i];
     }
     }
     

void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
    int mid=(low+high)/2;
      mergesort(a,low,mid);
      mergesort(a,mid+1,high);
      merge(a,low,mid,high);
    }
    }
int main()
{
   int n;
   printf("Enter the number");
   scanf("%d",&n);
   int low=0;
   int high=n-1;
   int a[n];
   printf("Enter the element:");
   for(int i=0;i<n;i++)
   {  
     scanf("%d",&a[i]);
    }
    mergesort(a,low,high);
    for(int i=0;i<n;i++)
    {
    printf("%d",a[i]);
    }
    return 0;
    }
    
    
   
