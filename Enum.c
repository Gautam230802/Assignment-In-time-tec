#include<stdio.h>
#include<stdlib.h>
 
typedef enum{
    high =0,
    mid=1,
    low=2,
}condition;
 
typedef struct{
int id;
condition critical;
}Patient;
 
void sort(Patient *p,int n)
{
 
    for(int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].critical>p[j+1].critical)
            {
                Patient temp =p[j];
                p[j]=p[j+1];
                p[j+1] =temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Number of patient: ");
    scanf("%d",&n);
 
    Patient* p=(Patient*)malloc(n*sizeof(Patient));
    char str[50];
    for(int i =0;i<n;i++)
    {
        printf("patient id: ");
        scanf("%d",&p[i].id);
 
        printf("seriousness:");
        scanf("%s",str);
 
        if(strcmp(str,"high")==0)
        {
            p[i].critical=high;
        }
        else if(strcmp(str,"mid")==0)
        {
            p[i].critical=mid;
        }
        else if(strcmp(str,"low")==0)
        {
            p[i].critical=low;
        }
        else{
            printf("Invalid input");
            i--;
            continue;
        }
    }
    sort(p,n);
 
    for(int i =0;i<n;i++)
    {
        printf("id : %d  seriousness:%s ",p[i].id, (p[i].critical==high)?"high":(p[i].critical==mid)?"mid":"low");
        printf("\n");}
}