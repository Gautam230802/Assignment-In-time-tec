#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *removeDesire(char c,char*str)
{int j =0;
    for(int i =0;str[i]!='\0';i++)
    {
        if(str[i]!=c )
        {
            str[j++]=str[i];
        }
        
    }
    str[j]='\0';
    return str;
}

int main()
{
    char c;
    printf("Enter character to be removed ");
    scanf("%c",&c);
    getchar();
    char *str =(char*)malloc(sizeof(char)*100);
    printf("Enter string ");
    fgets(str,100,stdin);
   
    removeDesire(c,str);

    printf("Output after removal of %c: %s",c,str);
}