#include<stdio.h>
#include<string.h>
int stringLen(char* ip)
{
   int count =0;
   int i =0;
   while(ip[i]!='\0')
   {
    count++;
    i++;
   }
   return count;

}
int isDigit(char c)
{
    return (c>='0' && c<='9');
}

int isDot(char c)
{
    return(c=='.');
}


int main()
{
    char ip[16];
    printf("Enter Ip Address");
    scanf("%s",ip);

    int flag =1;
    int len =stringLen(ip);
    int dotCount =0;

    for(int i =0;i<len;i++)
    {char c =ip[i];

        if(!isDigit(c) &&!isDot(c))
        {  
            flag =0;
            break;
        }

        else{
            if(isDigit(c))
            {
                if(c=='0' && ip[i-1]=='.' && isDigit(ip[i+1]) && (i>0 && i< len -1))
                {   
                    flag =0;
                }

                int num =0;
                while(ip[i]!='.' && i<len)
                {
                    num = num*10 +(ip[i]-'0');
                    i++;
                }
                i--;
               
                if(num > 255)
                {   
                    flag =0;
                    break;
                }
                
            }
            
            if(isDot(c))
            {
                if(i ==0 || i==(len -1))
                {
                    flag =0;
                    break;
                }
                if(isDot(ip[i-1]))
                {
                    flag =0;
                    break;
                }
                dotCount++;
            }
        }
    }

    if(dotCount !=3)
    {
        flag =0;
    }

    if(flag)
    {
        printf("valid");
    }
    else{
        printf("not valid");
    }
}