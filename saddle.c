#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int findSaddle(int **arr,int row,int col)
{
    int row_min[row];
    int col_max[col];

    int rowConst=0;
    while(rowConst<row)
    {   int mini =arr[rowConst][0];
        for(int i =0;i<col;i++)
        {
            if(mini >arr[rowConst][i])
            {
                mini =arr[rowConst][i];
            }
        }
        row_min[rowConst] =mini;
        rowConst++;
    }

    int colConst=0;
    while(colConst<col)
    {   int maxi =arr[0][colConst];
        for(int i =0;i<row;i++)
        {
            if(maxi < arr[i][colConst])
            {
                maxi =arr[i][colConst];
            }
        }
        col_max[colConst] =maxi;
        colConst++;
    }
int saddle =-1;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            if(arr[i][j]==row_min[i] && arr[i][j]==col_max[j])
            {
                saddle=arr[i][j];
            }
        }
    }
    return saddle;
}
int main()
{
    int row,col;
    printf("Enter no. of rows and cols");
    scanf("%d %d",&row,&col);

    int **arr =(int**)malloc(row*sizeof(int*));
    for(int i =0;i<row;i++)
    {
        arr[i] =(int*)malloc(col*sizeof(int));
    }

    for(int i =0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int saddlePoint = findSaddle(arr,row,col);
    printf("saddle point %d",saddlePoint);
}