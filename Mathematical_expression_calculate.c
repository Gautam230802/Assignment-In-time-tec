#include<stdio.h>

int powerResult(int base, int power,int mod)
{base =base% mod;
    int ans =1;
    while(power>0)
    {
        if(power%2==1)
        {
            ans =(ans*base)%mod;
            power =power-1;
        }
        else{
            power =power/2;
            base =(base*base)%mod;
        }
    }
    return ans;
}
int main()
{
    int base,power,mod;
    printf("Enter the base, power and mod to be calculated");
    scanf("%d %d %d",&base,&power,&mod);
    if(base < 0 || power <0 || mod <=1 )
    {
        printf("Invalid input");
        return 0;
    }
    int exponentResult = powerResult(base,power,mod);
    printf("%d",exponentResult);
}