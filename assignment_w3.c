#include <stdio.h>
#include<string.h>
int isvvowel(char c)
{
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'|| c=='A' || c=='E' || c=='I' || c=='O'|| c=='U');
}
void printArray(int row,int col,char nameInfo[][col][50])
{
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            printf("%s ",nameInfo[i][j]);
        }
        printf("\n");
    }
}

void MaximumLength(int row,int col,char nameInfo[][col][50])
{
    int max =-1;
    int row_ind =0;
    int col_ind =0;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            int len =strlen(nameInfo[i][j]);
            if(max < len)
            {
              row_ind =i;
              col_ind =j;
              max = len;
            }
        }
        printf("\n");
    }
    printf("Name with maximum length %s\n",nameInfo[row_ind][col_ind]);
}

void isVowel(int row,int col,char nameInfo[][col][50])
{
    int count =0;
     for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            if(isvvowel(nameInfo[i][j][0]))
          {
            count++;
          }
       }
        
    }
    printf("Words starting with vowel %d \n",count);
}
int main()
{
    int row, col;
    printf("Enter row and col: ");
    scanf("%d %d",&row,&col);
    
    char nameInfo[row][col][50];
    
    printf("Enter names");
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            scanf("%s",nameInfo[i][j]);
        }
    }
    printArray(row,col,nameInfo);
    MaximumLength(row,col,nameInfo);
    isVowel(row,col,nameInfo);
    
}
