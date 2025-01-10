#include<stdio.h>
#include<stdlib.h>

int printFrequency(int **arr,int row,int col)
{
    int freq[101]={0};
    int element;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            element =*(*(arr+i)+j);
            freq[element]++;
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        { if(freq[*(*(arr+i)+j)]==-1)
            continue;
            printf("%d -> %d times \n",*(*(arr+i)+j),freq[*(*(arr+i)+j)]);
            freq[*(*(arr+i)+j)] = -1;
        }
    }
    
}
int main()
{
    int row ,col;
    printf("enter row and column");
    scanf("%d %d",&row,&col);

    int **arr = (int**)malloc(row*sizeof(int*));
    for(int i =0;i<row;i++)
    {
        arr[i]=(int*)malloc(col*sizeof(int));
    }

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printFrequency(arr,row,col);
}