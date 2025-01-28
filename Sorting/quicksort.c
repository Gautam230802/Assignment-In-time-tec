#include<stdio.h>
#include<stdlib.h>
int findPivot(int *arr,int low,int high)
{
    int pivot =arr[low];
    int i =low;
    int j= high;
    while(i<j){
    while(arr[i]<= pivot && i<high)
    {
        i++;
    }

    while(arr[j]> pivot && j>low)
    {
        j--;
    }

    if(i<j)
    {
        int temp =arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    }

    int temp =arr[j];
    arr[j]=arr[low];
    arr[low]=temp;

    return j;

}

void quickSort(int *arr,int low,int high)
{
    if(low<high){
    int pivot = findPivot(arr,low,high);

    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);
    }
}
int main()
{
    int n;
    printf("Enter the number of elementws");
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}