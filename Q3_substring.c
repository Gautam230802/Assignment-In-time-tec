#include<stdio.h>
#include<string.h>
int checkSubstring(char* str,char*str1)
{
    int indexStr=0;
    int indexStr1 =0;
    int cnt =0;
    int start =0;
    while(str[indexStr]!='\0' && str1[indexStr1]!='\0')
    {
        if(cnt==0){
        start =indexStr;
        }
        if(str[indexStr]==str1[indexStr1])
        {
            indexStr1++;
            indexStr++;
            cnt++;
        }
        else
        {
            indexStr++;
            cnt =0;
            indexStr1 = 0;
        }
    }
    if(cnt == strlen(str1))
    {
        return start;
    }
    return 0;
}
int main()
{
   char str[100];
   char str1[100];
    printf("Enter the first string : ");
    fgets(str,100,stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter the second string : ");
    fgets(str1,100,stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    int ind =checkSubstring(str,str1);
    if(ind>0)
    {
        printf("%d",ind);
    }
    else{
        printf("%d",-1);
    }
   
}