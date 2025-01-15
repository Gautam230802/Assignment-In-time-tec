#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void inputStr(int *sizeStr,char **str, int capacity)
{
    *sizeStr=0;
    char c;
    while(scanf("%c",&c) && c!='\n')
    {
        if(*sizeStr >  capacity)
        {
            capacity=2*capacity;
            *str =(char*)realloc(*str,sizeof(char)*capacity);
        }
        (*str)[(*sizeStr)++]=c;
    }
    (*str)[*sizeStr]='\0';
    printf("Output string: %s \n",*str);
}

int main()
{
    int sizeStr;
    int capacity =5;
    char *str =(char*)malloc(capacity*sizeof(char));
    printf("Enter input string: ");
    inputStr(&sizeStr,&str,capacity);
    int cnt =0;
    for(int i =0;str[i]!='\0';i++)
    {   char c =str[i];
        if(c==' ')
        {
            continue;
        }
        else if((c>=65 && c<=90) || (c>=97 && c<=122))
        {
            while((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
            {
                i++;
            }
            cnt++;
            i--;
        }
    }

    printf("Number of words: %d",cnt);
}