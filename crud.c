#include<stdio.h>
#include<stdlib.h>

struct info
{
    int id;
    char name[50];
    int age;
}user;

void createFileIfNot(char* filename)
{   
    FILE* fp;
    fp=fopen(filename,"a");
    if(!fp)
    {
        printf("Error in creating a file");
        exit(1);
    }
    fclose(fp);
}
void display(char* filename)
{
    FILE* fp;
    char data[50];
    fp = fopen(filename,"r");
    if(fp ==NULL)
    {
        printf("Error in opening a file\n");
        exit(1);
    }

    while(fgets(data,50,fp)!=NULL)
    {
        printf("%s",data);
    }

fclose(fp);
}
int findId(int requireId,char* filename)
{
    FILE*fp;
    fp =fopen(filename,"r");
    char info[50];
    if(fp==NULL)
    {
        return -1;
        
    }
    int id;
    int age;
    char name[50];
    int found =0;
    while(fscanf(fp,"%d %s %d",&id,name,&age)==3)
    {
        if(id == requireId)
        {
            found =1;
        }
    }
    fclose(fp);
    return found;
}
void addUser(char* filename)
{
    FILE* fp;

    printf("Enter ID");
    scanf("%d",&user.id);
    getchar();
    printf("Enter name");
    gets(user.name);
    printf("Enter age");
    scanf("%d",&user.age);
    getchar();
    fp =fopen(filename,"a");
    if(fp==NULL)
    {
        printf("error in file\n");
        exit(1);
    }
    if(findId(user.id,filename)){
        printf("enter unique id");
        exit(1);
    }
    else{
    fprintf(fp,"%d %s %d\n",user.id,user.name,user.age);
    }
    fclose(fp);
}


void deleteId(int del,char* filename)
{
    FILE*fp;
    fp =fopen(filename,"r");
    if(fp==NULL)
    {
        printf("ERROR IN FILE");
        exit(1);
    }
    struct info data[100];
    int count =0;
    int idFound =0;
    while (fscanf(fp,"%d %s %d",&data[count].id,data[count].name,&data[count].age)==3) 
    {
        count++;
    }

    fclose(fp);

    FILE* file;
    file =fopen("temp.txt","w");
    for(int i =0;i<count;i++)
    {
        if(data[i].id == del)
        {   idFound=1;
            continue;
            
        }
        fprintf(file,"%d %s %d\n",data[i].id,data[i].name,data[i].age);
    }
    if(!idFound){
        printf("Id not available\n");
    }
    fclose(file);
    remove(filename);
    rename("temp.txt",filename);
    
}
void updateUser(int userId,char* filename)
{
    FILE*fp;
    fp =fopen(filename,"r");
    if(fp==NULL)
    {
        printf("ERROR IN FILE");
        exit(1);
    }
    struct info data[100];
    int count =0;
    
    while (fscanf(fp,"%d %s %d",&data[count].id,data[count].name,&data[count].age)==3)
    {
        count++;
    }

    fclose(fp);

    FILE* file;
    file =fopen("temp.txt","w");
    for(int i =0;i<count;i++)
    {
        if(data[i].id==userId)
        {
             printf("Enter new name: ");
            getchar(); 
            gets(data[i].name);

            printf("Enter new age: ");
            scanf("%d", &data[i].age);
        }
        fprintf(file,"%d %s %d\n",data[i].id,data[i].name,data[i].age);
    }

    fclose(file);
    remove(filename);
    rename("temp.txt",filename);
    
}
int main()
{   char filename[20];
    printf("Please Enter filename");
    scanf("%s", filename);
    

    createFileIfNot(filename);
    display(filename);

    printf("\n");

    addUser(filename);
    display(filename);

    printf("\n");

    int del;
    printf("enter id to delete");
    scanf("%d",&del);
    deleteId(del,filename);
    display(filename);

    printf("\n");

    int userId;
    printf("enter user id to be updated ");
    scanf("%d",& userId);
    updateUser(userId,filename);
    display(filename);
   
return 0;
}