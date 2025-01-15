#include <stdio.h>

void toLowercase(char *c)
{
    *c = *c - 'A' + 'a';
}

char* removeRepeated(char *str, int *freq, char *res)
{
    int j = 0;
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (freq[str[i] - 'a'] == 0)
        {
            res[j] = str[i];
            j++;
            freq[str[i] - 'a']++;
        }
        else if (freq[str[i] - 'a'] != 0)
        {
            continue;
        }
    }
    return res;
}
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int freq[26] = {0};
    char res[100];
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c >= 65 && c <= 90)
        {
            toLowercase(&str[i]);
        }
    }

    removeRepeated(str, freq, res);

    printf("String after removing duplicates %s", res);
}