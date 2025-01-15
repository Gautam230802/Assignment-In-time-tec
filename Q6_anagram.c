#include<stdio.h>

int checkAnagram(char *str,char *str1)
{
    int freqStr[26]={0};
    int freqStr2[26]={0};
    for(int i=0;str[i]!=0;i++)
    {
        freqStr[str[i]-'a']++;
    }

    for(int i=0;str1[i]!=0;i++)
    {
        freqStr2[str1[i]-'a']++;
    }

    for(int i =0;i<26;i++)
    {
        if(freqStr[i]!=freqStr2[i])
        {
            return 1;
        }
    }
return 0;
}
int main()
{
   char str[100];
   char str1[100];
    printf("Enter the first string : ");
    fgets(str,100,stdin);
    printf("Enter the first string : ");
    fgets(str1,100,stdin);
    int check =checkAnagram(str,str1);

    if(check)
    {
        printf("false");
    }
    else{
        printf("true");
    }
}