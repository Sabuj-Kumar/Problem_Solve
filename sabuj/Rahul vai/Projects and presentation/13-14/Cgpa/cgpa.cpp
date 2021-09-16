#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct info{
       char name[100];
       int level;
       int term;
       int age;
       int batch;
       char sec[100];
       char department[100];
       char bgrp[100];
       char cnmbr[100];
       char id[10];
       float cgpa;
}s[100];

int main()
{
    FILE *fp1;
    system("color Fd");
    fp1=fopen("cgpa.txt","r");
    int name_flag=0,level_flag=0,term_flag=0;
    int age_flag=0,batch_flag=0,sec_flag=0;
    int department_flag=0,bgrp_flag=0,cnmbr_flag=0;
    int id_flag=0,cgpa_flag=0;
    int i=0,j=0;
    char ch;
    char str[100];

    while((ch=fgetc(fp1))!=EOF)
    {
        if(ch=='\n' && name_flag==1)
        {
            str[i]='\0';
            i=0;

            name_flag=0;
            strcpy(s[j].name,str);
        }
        if(ch=='\n' && level_flag==1)
        {
            str[i]='\0';
            i=0;
            level_flag=0;
            s[j].level=atoi(str);
        }
        if(ch=='\n' && term_flag==1)
        {
            str[i]='\0';
            i=0;

            term_flag=0;
            s[j].term=atoi(str);
        }
         if(ch=='\n' && age_flag==1)
        {
            str[i]='\0';
            i=0;

            age_flag=0;
            s[j].age=atoi(str);
        }
         if(ch=='\n' && batch_flag==1)
        {
            str[i]='\0';
            i=0;

            batch_flag=0;
            s[j].batch=atoi(str);
        }
        if(ch=='\n' && sec_flag==1)
        {
            str[i]='\0';
            i=0;

            sec_flag=0;
            strcpy(s[j].sec,str);
        }
         if(ch=='\n' && department_flag==1)
        {
            str[i]='\0';
            i=0;

            department_flag=0;
            strcpy(s[j].department,str);
        }
        if(ch=='\n' && bgrp_flag==1)
        {
            str[i]='\0';
            i=0;

            bgrp_flag=0;
            strcpy(s[j].bgrp,str);
        }
        if(ch=='\n' && cnmbr_flag==1)
        {
            str[i]='\0';
            i=0;

            cnmbr_flag=0;
            strcpy(s[j].cnmbr,str);
        }
        if(ch=='\n' && id_flag==1)
        {
             str[i]='\0';
             i=0;
             id_flag=0;
            // s[j].id=atoi(str);
             strcpy(s[j].id,str);
        }
        if(ch=='\n' && cgpa_flag==1)
        {
            str[i]='\0';
            i=0;
            cgpa_flag=0;
            s[j].cgpa=atof(str);
            j++;
        }
        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"name")==0)
            {
                name_flag=1;
            }
            if(strcmp(str,"level")==0)
            {
                level_flag=1;
            }
            if(strcmp(str,"term")==0)
            {
                term_flag=1;
            }
            if(strcmp(str,"age")==0)
            {
                age_flag=1;
            }
            if(strcmp(str,"batch")==0)
            {
                batch_flag=1;
            }
            if(strcmp(str,"sec")==0)
            {
                sec_flag=1;
            }
            if(strcmp(str,"department")==0)
            {
                department_flag=1;
            }
            if(strcmp(str,"bgrp")==0)
            {
                bgrp_flag=1;
            }
            if(strcmp(str,"cnmbr")==0)
            {
                cnmbr_flag=1;
            }
            if(strcmp(str,"id")==0)
            {
                id_flag=1;
            }
            if(strcmp(str,"cgpa")==0)
            {
                cgpa_flag=1;
            }

        }
        else
        {
            if(ch!='\n')
            {
            str[i]=ch;
            i++;
            }
        }

     }
     if(level_flag==1)
        {
            str[i]='\0';
            i=0;
            level_flag=0;
            s[j].level=atoi(str);
        }
        if(term_flag==1)
        {
            str[i]='\0';
            i=0;
            term_flag=0;
            s[j].term=atoi(str);
        }
        if(age_flag==1)
        {
            str[i]='\0';
            i=0;
            age_flag=0;
            s[j].age=atoi(str);
        }
        if(batch_flag==1)
        {
            str[i]='\0';
            i=0;
            batch_flag=0;
           s[j].batch=atoi(str);
        }
        if(sec_flag==1)
        {
            str[i]='\0';
            i=0;
            sec_flag=0;
            strcpy(s[j].sec,str);
        }
        if(department_flag==1)
        {
            str[i]='\0';
            i=0;
            department_flag=0;
            strcpy(s[j].department,str);
        }
        if(bgrp_flag==1)
        {
            str[i]='\0';
            i=0;
            bgrp_flag=0;
            strcpy(s[j].bgrp,str);
        }
        if(cnmbr_flag==1)
        {
            str[i]='\0';
            i=0;
            cnmbr_flag=0;
            strcpy(s[j].cnmbr,str);
        }
     if(id_flag==1)
        {
            str[i]='\0';
            i=0;
            id_flag=0;
            strcpy(s[j].id,str);
        }
        if(cgpa_flag==1)
        {
            str[i]='\0';
            i=0;
            cgpa_flag=0;
            s[j].cgpa=atoi(str);
            j++;
        }
  fclose(fp1);
    printf("******************######################********************\n");
    printf("*                   CGPA MANAGEMENT SYSTEM                    *\n");
    printf("*                        DONE BY                                               *\n");
    printf("*                      *Raju && *Yead                         *\n");
    printf("*****                13101013 && 13101014                                       ****\n");
    printf("***                TO FIND ANY STUDENT CGPA DETAILS                *\n");
    printf("*                    JUST TAKE HIS/HER ID:                                           *\n");
    printf("*                 THEN PRESS ENTER :)" );
    printf("                              $$$$$$$$$$                    \n\n");
    int n,p;

        /*int at;
        printf("give me id :");
        scanf("%d",&at);
        for(i=0;i<1;i++)
       {
           if(at==atoi(s[i].id))
        {
         printf("yes");

        }
        }*/
    char r[100];
    gets(r);
    for(i=0;i<100;i++)
    {
        if(strcmp(s[i].id,r)==0){
        puts(s[i].name);
        printf("level is=%d\n",s[i].level);
        printf("term is=%d\n",s[i].term);
        printf("age is=%d\n",s[i].age);
        printf("batch is=%d\n",s[i].batch);
        printf("sec is=%s\n",s[i].sec);
        printf("department is=%s\n",s[i].department);
        printf("bgrp is=%s\n",s[i].bgrp);
        printf("cnmbr is=%s\n",s[i].cnmbr);
        printf("id is=%s\n",s[i].id);
        printf("cgpa is=%.2f\n",s[i].cgpa);
        }
    }

/*
    fp1=fopen("cgpa1.txt","w");
    for(i=0;i<100;i++)
    {
        char p[20];
        fputs("name:",fp1);
        fputs(s[i].name,fp1);
        fputc('\n',fp1);
        fputs("id:",fp1);
        //fputs(s[i].id,fp1);
       //itoa(s[i].id,p,10);
        fputs(p,fp1);
        fputc('\n',fp1);
        fputs("cgpa:",fp1);
       // itoa(s[i].cgpa,p,10);
        fputs(p,fp1);
        fputc('\n\n',fp1);
    }
    fclose(fp1);
    */
    getch();
    return 0;
}

