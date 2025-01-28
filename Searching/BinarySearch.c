// First occurence of a element in an array by binary search

#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int low,int high,int element)
{   int start =low;
    int end =high;
    int first =-1;
    int mid;
    while(start<=end)
    {
        mid =start +(end-start)/2;

        if(arr[mid]==element)
        {
            first =mid; 
            end =mid-1;
        }
        else if(arr[mid]<element)
        {
            start =mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(first)
    {
        return first;
    }
    else{
    return -1;
    }
}
int main()
{
    int n;
    printf("Enter size of element ");
    scanf("%d",&n);

    int element;
    printf("enter the element to search");
    scanf("%d",&element);
    int arr[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   int index= binarySearch(arr,0,n-1,element);

    printf("Element at index %d: ",index);
}