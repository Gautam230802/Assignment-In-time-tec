#include<stdio.h>
#include<stdlib.h>

int findMax(int arr[],int ind)
{
    int maxi =-1;
    for(int i =0;i<ind;i++)
    {
        if(arr[i]>maxi)
        {
            maxi =arr[i];
        }
    }
    return maxi;
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

    int max =findMax(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Maximum element is:%d ",max);
}