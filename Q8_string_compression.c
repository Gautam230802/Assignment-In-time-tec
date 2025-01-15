#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *countFreq(char *str,int *arr)
{
    for(int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        arr[str[i] - 'a']++;
    }
    return arr;
}

void stringCompression(char *str,int *arr) {
    int n = strlen(str);
    int j = 0;
    char temp[100];
    for (int i = 0; i < n; i++) {
        if(arr[str[i]-'a']>1)
        {
            temp[j++]=str[i];
            temp[j++]=arr[str[i]-'a']+'0';
            while(str[i]==str[i+1] && i+1<strlen(str))
            {
                i++;
            }
        }
        else{
            temp[j++]=str[i];
        }
    }

    temp[j] = '\0';
    printf("output after compression: %s",temp);
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int arr[26];
    countFreq(str, arr);

    stringCompression(str,arr);

    return 0;
}
