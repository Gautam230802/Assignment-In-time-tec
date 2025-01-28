#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}
void sort012(int *arr,int n)
{
    int low =0;
    int high =n-1;
    int mid =0;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(&arr[mid],&arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==2)
        {
            swap(&arr[mid],&arr[high]);
            high--;

        }
        else{
            mid++;
        }
    }
}
int main()
{
    int n;
    printf("Enter size of element ");
    scanf("%d",&n);

    int arr[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   sort012(arr,n);

for(int i =0;i<n;i++)
{
    printf("%d ",arr[i]);
}
   
}