#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void longestWord(char *str)
{int max =0;

char word[50];
    for(int i =0;str[i]!='\0';i++)
    {   int len =0;
        int start =i;
        while(str[i]!=' ' && str[i]!='\0')
        {
            len++;
            i++;
        }
        
        if(len>=max)
        {
            max =len;
            int ind =0;
            for(int j =start;j<=i;j++)
            {
                word[ind]=str[j];
                ind++;
            }
            word[ind]='\0';
        }
    }
    printf("longest word is: %s",word);
}
int main()
{
    char *str =(char*)malloc(100*sizeof(char));
    printf("Enter the string: ");
    fgets(str,100,stdin);
    str[strcspn(str, "\n")] = '\0'; 
    longestWord(str);
}