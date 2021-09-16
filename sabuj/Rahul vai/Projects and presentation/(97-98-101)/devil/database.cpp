#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct student_database
{
    char name[32];
    char term[12];
    char adds[50];
    char  blood[6];
    char gender[15];
    char student_id[15];
    char departmentName[15];
}db[50];
int main()
{
    FILE *fp;
    char s[100];
    fp=fopen("akeedo.txt","r");
    for(int i=0;i<20;i++)
        fscanf(fp,"%s%s%s%s%s%s%s",&db[i].name,&db[i].term,&db[i].adds,&db[i].blood,&db[i].gender,&db[i].student_id,&db[i].departmentName);
   while(1){
        int flag=0;
        printf("ID:");
       scanf("%s",&s);
       for(int i=0;i<20;i++)
       {
           if(strcmp(db[i].student_id,s)==0)
           {
               flag=1;
               cout<<"NAME:";
               puts(db[i].name);
               cout<<"GENDER:";
               puts(db[i].gender);
               cout<<"TERM:";
               puts(db[i].term);
               cout<<"CITY:";
               puts(db[i].adds);
               cout<<"BLOOD:";
               puts(db[i].blood);
               cout<<"ID:";
               puts(db[i].student_id);
               cout<<"DEPARTMENT:";
               puts(db[i].departmentName);
           }
       }
        if(flag == 0)
            cout<<"Sorry there is no student in this ID"<<endl;

    }
    return 0;

}
