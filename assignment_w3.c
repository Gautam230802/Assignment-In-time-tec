#include <stdio.h>
#include<string.h>
int isvvowel(char c)
{
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'|| c=='A' || c=='E' || c=='I' || c=='O'|| c=='U');
}
int main()
{
    int row, col;
    scanf("%d %d",&row,&col);
    
    char nameInfo[row][col][50];
    
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            scanf("%s",nameInfo[i][j]);
        }
    }
    int max =-1;
    int row_ind =0;
    int col_ind =0;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            printf("%s ",nameInfo[i][j]);
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
    printf("Name with maximum length %s",nameInfo[row_ind][col_ind]);
}