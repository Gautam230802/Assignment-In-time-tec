#include<stdio.h>
#include<stdlib.h>
int diagonalAdd(int row ,int col,int **arr )
{int sum =0;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            if(i ==j ||(i+j)==(row -1))
            {
                
                sum+=arr[i][j];
            }
        }
    }
    if(row%2==1)
    {
        int ind =row/2;
        sum = sum -arr[ind][ind];
    }
    return sum;
}
int main()
{
    int row,col;
    printf("Enter Rowand Col \n");
    scanf("%d %d",&row,&col);

    int *arr[row];
    for(int i =0;i<row;i++)
    {
        arr[i] =(int*)malloc(col*sizeof(int));
    }

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    int diagonalSum = diagonalAdd(row,col,arr);
    printf("sum of diagonal elements is: %d",diagonalSum);
    for(int i =0;i<row;i++)
    {
        free(arr[i]);
    }
}