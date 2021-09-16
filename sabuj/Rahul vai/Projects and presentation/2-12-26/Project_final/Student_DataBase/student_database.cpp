#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

#define MAX 100
#define MIN 2


struct student{
    int stu_level;
    int stu_term;
    int stu_batch;
    char stu_id[20];
    char stu_name[100];
    char stu_dprtmnt[100];
    char stu_sec[100];
    float stu_cgpa11;
    float stu_cgpa12;
    float stu_cgpa21;
    float stu_cgpa22;
    float stu_cgpa31;
    float stu_cgpa32;
    float stu_cgpa41;
    float stu_cgpa42;
    char stu_gender[100];
    int stu_age;
    char stu_bdate[100];
    char stu_bgrp[100];
    char stu_cnmbr[100];
};
    int name_flag=0,id_flag=0,age_flag=0;
    int level_flag=0,term_flag=0,batch_flag=0;
    int dprtmnt_flag=0,sec_flag=0;
    int cgpa_flag_11=0,cgpa_flag_12=0,cgpa_flag_21=0,cgpa_flag_22=0;
    int cgpa_flag_31=0,cgpa_flag_32=0,cgpa_flag_41=0,cgpa_flag_42=0;
    int gender_flag=0,bdate_flag=0,bgrp_flag=0;
    int cnmbr_flag=0;
    int count_students=0;

   char given_id[1000],SeachName[1000];
    int given_term,SearchNameCount=0,SerachAge,SerachAgeCount=0,SearchSem,SerachCgpaCount=0;
    float given_cgpa,SerachCgpa;




    int i=0,j=0,k=0,c,choice;
    char s[1000],ch;
    student a[MAX];
    FILE *readFile;

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

void LoadData(void);
void ShowData(void);
void EditData(void);
void AddData(void);
void NameBasedSearch(void);
void AgeBasedSearch(void);
void CgpaBasedSearch(void);


int main()
{

    SetConsoleTitle("Student DataBase Management");

    system("color 20");
    printf("\t\t WELCOME TO STUDENT DATABASE MANAGEMENT SYSTEM\n");
    printf("\n\t\tCreated By Ashiq, Sagar & Tasnia\n\n");
    printf("\n\npress any key to continue....\n");
    getch();
    system("cls");

    printf("GIVE CHOICE--\n");
     printf("   1 TO LOAD ALL DATA FROM FILE.\n");
     printf("   2 TO EXIT\n\n--");
     scanf("%d",&c);
     if(c==2)
        {
            system("cls");
            system("color 1f");
            printf("\nExiting the Programme....\n\n");
            return 0;
        }
    else if(c==1)
    {
        system("color 0f");
        system("cls");
        printf("Loading all data....");
        LoadData();
        printf("\n\nLoad Complete!!!\n Press any key to Continue..\n");
        getch();
        system("cls");

    }
     printf("GIVE CHOICE--\n");
     printf("   1 TO SEE ALL STUDENT INFO.\n");
     printf("   2 TO EDIT THE CGPA OF A CURRENT STUDENT.\n");
     printf("   3 TO ENTER NEW STUDENT INFO.\n");
     printf("   4 TO SEARCH STUDENT INFO.\n");
     printf("   5 TO EXIT\n\n--");

     scanf("%d",&c);
     if(c==5)
     {
         system("cls");
         printf("\nExiting the Programme....\n\n");
         return 0;
     }
     if(c==1)
     {
         system("cls");
         system("color 1f");
         ShowData();

     }


    if(c==2)
    {
        fflush(stdin);
        EditData();



    printf("\n\nData Editing Successful!\n");
    printf("\nPress any key to continue");
    getch();
    LoadData();
    system("cls");
    system("color 1f");
    printf("\nshowing all data...\n\n");
    ShowData();
    return 0;

    }


    if(c==3)
    {
        fflush(stdin);
        AddData();



    printf("\n\nData Adding Successful!\n");
    printf("\nPress any key to continue");
    getch();
    LoadData();
    system("cls");
    system("color 1f");
    printf("\nshowing all data...\n\n");
    ShowData();
    return 0;

    }
    if(c==4)
    {
        system("cls");
        system("color 1f");
        printf("GIVE CHOICE--\n");
     printf("   1 TO SEARCH BASED ON NAME.\n");
     printf("   2 TO SEARCH BASED ON AGE.\n");
     printf("   3 TO SEARCH BASED ON CGPA.\n");
     scanf("%d",&choice);

     if(choice == 1){
            system("cls");
        system("color 1f");
        NameBasedSearch();

     }
     if(choice == 2){
            system("cls");
        system("color 1f");
        AgeBasedSearch();
     }
     if(choice == 3){
            system("cls");
        system("color 1f");
        CgpaBasedSearch();

     }

        return 0;

    }

}


void LoadData(void)
{
    readFile = fopen("x.txt","r");
    if(readFile==NULL)
    {
        printf("\nERROR!!\nMissing Data File\n");
        exit(1);
    }
    else
    {
        while((ch=fgetc(readFile))!=EOF)
        {
            if(ch=='\n' && (level_flag==1))
        {
           s[i]='\0';
           a[j].stu_level=atoi(s);
           i=0;
           level_flag=0;
           continue;
        }
        if(ch=='\n' && (term_flag==1))
        {
           s[i]='\0';
           a[j].stu_term=atoi(s);
           i=0;
           term_flag=0;s[i]='\0';
           continue;
        }
        if(ch=='\n' && batch_flag==1)
        {
           s[i]='\0';
           a[j].stu_batch=atoi(s);
           i=0;
           batch_flag=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && id_flag==1)
        {
           s[i]='\0';
           strcpy(a[j].stu_id,s);
           i=0;
           id_flag=0;
           continue;
        }
        if(ch=='\n' && name_flag==1)
        {
           s[i]='\0';
           strcpy(a[j].stu_name,s);
           name_flag=0;
           i=0;
           s[i]='\0';

           continue;
        }
        if(ch=='\n' && dprtmnt_flag==1)
        {
           s[i]='\0';
           strcpy(a[j].stu_dprtmnt,s);
           dprtmnt_flag=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && sec_flag==1)
        {
           s[i]='\0';
           strcpy(a[j].stu_sec,s);
           sec_flag=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_11==1)
        {
           s[i]='\0';
           a[j].stu_cgpa11=atof(s);
           cgpa_flag_11=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_12==1)
        {
           s[i]='\0';
           a[j].stu_cgpa12=atof(s);
           cgpa_flag_12=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_21==1)
        {
           s[i]='\0';
           a[j].stu_cgpa21=atof(s);
           cgpa_flag_21=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_22==1)
        {
           s[i]='\0';
           a[j].stu_cgpa22=atof(s);
           cgpa_flag_22=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_31==1)
        {
           s[i]='\0';
           a[j].stu_cgpa31=atof(s);
           cgpa_flag_31=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_32==1)
        {
           s[i]='\0';
           a[j].stu_cgpa32=atof(s);
           cgpa_flag_32=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_41==1)
        {
           s[i]='\0';
           a[j].stu_cgpa41=atof(s);
           cgpa_flag_41=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cgpa_flag_42==1)
        {
           s[i]='\0';
           a[j].stu_cgpa42=atof(s);
           cgpa_flag_42=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && gender_flag==1)
        {
           s[i]='\0';
           strcpy(a[j].stu_gender,s);
           gender_flag=0;
           i=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && age_flag==1)
        {
           s[i]='\0';
           i=0;
           a[j].stu_age=atoi(s);
           age_flag=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && bdate_flag==1)
        {
           s[i]='\0';
           i=0;
           strcpy(a[j].stu_bdate,s);
           bdate_flag=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && bgrp_flag==1)
        {
           s[i]='\0';
           i=0;
           strcpy(a[j].stu_bgrp,s);
           bgrp_flag=0;
           s[i]='\0';
           continue;
        }
        if(ch=='\n' && cnmbr_flag==1)
        {
           s[i]='\0';
           i=0;
           strcpy(a[j].stu_cnmbr,s);
           cnmbr_flag=0;
           s[i]='\0';
           continue;
        }
        if(ch==':')
        {
            s[i]='\0';
            i=0;
        if(strcmp(s,"stu_level")==0)
        {
            s[i]='\0';level_flag=1;
        }
        if(strcmp(s,"stu_term")==0)
        {
            s[i]='\0';term_flag=1;
        }
        if(strcmp(s,"stu_batch")==0)
        {
           s[i]='\0'; batch_flag=1;
        }
        if(strcmp(s,"stu_id")==0)
        {
           s[i]='\0'; id_flag=1;
        }
        if(strcmp(s,"stu_name")==0)
        {
           s[i]='\0'; name_flag=1;
        }
        if(strcmp(s,"stu_dprtmnt")==0)
        {
          s[i]='\0';  dprtmnt_flag=1;
        }
        if(strcmp(s,"stu_sec")==0)
        {
          s[i]='\0';  sec_flag=1;
        }
        if(strcmp(s,"stu_cgpa1/1")==0)
        {
           s[i]='\0'; cgpa_flag_11=1;
        }
        if(strcmp(s,"stu_cgpa1/2")==0)
        {
           s[i]='\0'; cgpa_flag_12=1;
        }
        if(strcmp(s,"stu_cgpa2/1")==0)
        {
           s[i]='\0'; cgpa_flag_21=1;
        }
        if(strcmp(s,"stu_cgpa2/2")==0)
        {
           s[i]='\0'; cgpa_flag_22=1;
        }
        if(strcmp(s,"stu_cgpa3/1")==0)
        {
           s[i]='\0'; cgpa_flag_31=1;
        }
        if(strcmp(s,"stu_cgpa3/2")==0)
        {
           s[i]='\0'; cgpa_flag_32=1;
        }
        if(strcmp(s,"stu_cgpa4/1")==0)
        {
           s[i]='\0'; cgpa_flag_41=1;
        }
        if(strcmp(s,"stu_cgpa4/2")==0)
        {
           s[i]='\0'; cgpa_flag_42=1;
        }
        if(strcmp(s,"stu_gender")==0)
        {
           s[i]='\0'; gender_flag=1;
        }
        if(strcmp(s,"stu_age")==0)
        {
           s[i]='\0'; age_flag=1;
        }
        if(strcmp(s,"stu_bdate")==0)
        {
          s[i]='\0';  bdate_flag=1;
        }
        if(strcmp(s,"stu_bgrp")==0)
        {
          s[i]='\0';  bgrp_flag=1;
        }
        if(strcmp(s,"stu_cnmbr")==0)
        {
          s[i]='\0';  cnmbr_flag=1;
        }
        continue;
        }

    else if(ch == ';')
    {
        s[i]='\0';
        i=0;
        strcpy(a[j].stu_cnmbr,s);
        j++;
    }
    else if(ch=='\n')
    {
        count_students++;
        continue;
    }
    s[i]=ch;
    i++;

    }

    fflush(STDIN_FILENO);
    fclose(readFile);
}

}
void ShowData(void)
{

    for(int k=0;k<j;k++)
    {
       printf("Level:\n%d\n",a[k].stu_level);
        printf("Term:\n%d\n",a[k].stu_term);
        printf("Batch:\n%d\n",a[k].stu_batch);
        puts("ID No:");
        puts(a[k].stu_id);
        puts("Name:");
        puts(a[k].stu_name);
        puts("Depertment:");
        puts(a[k].stu_dprtmnt);
        puts("Section:");
        puts(a[k].stu_sec);
        puts("CGPA in 1.1: ");
        printf("%.2f\n",a[k].stu_cgpa11);
        puts("CGPA in 1.2: ");
        printf("%.2f\n",a[k].stu_cgpa12);
        puts("CGPA in 2.1: ");
        printf("%.2f\n",a[k].stu_cgpa21);
        puts("CGPA in 2.2: ");
        printf("%.2f\n",a[k].stu_cgpa22);
        puts("CGPA in 3.1: ");
        printf("%.2f\n",a[k].stu_cgpa31);
        puts("CGPA in 3.2: ");
        printf("%.2f\n",a[k].stu_cgpa32);
        puts("CGPA in 4.1: ");
        printf("%.2f\n",a[k].stu_cgpa41);
        puts("CGPA in 4.2: ");
        printf("%.2f\n",a[k].stu_cgpa42);
        puts("Gender:");
        puts(a[k].stu_gender);
        printf("Age:\n%d\n",a[k].stu_age);
        puts("Date Of Birth:");
        puts(a[k].stu_bdate);
        puts("Blood Group:");
        puts(a[k].stu_bgrp);
        puts("Contact Number:");
        puts(a[k].stu_cnmbr);
        printf("\n\n");
     }


}

void EditData(void)
{
       printf("\nEnter the Id no. you want to change the Cgpa:");
   gets(given_id);
   //fflush(stdin);
   printf("\n!!WARNING!!\nFirst enter the level,then the term without any Blank places or any words\n\n");
   printf("\nEnter the semester no. you want to change the Cgpa:");
   scanf("%d",&given_term);
   printf("\nEnter the Cgpa you want to give:");
   scanf("%f",&given_cgpa);

   for(int k=0;k<j;k++)
    {
        if(strcmp(a[k].stu_id,given_id)==0)
        {
            if(given_term ==11)
            {
               a[k].stu_cgpa11 = given_cgpa;
            }
            else if(given_term ==12)
            {
               a[k].stu_cgpa12 = given_cgpa;
            }
            else if(given_term ==21)
            {
               a[k].stu_cgpa21 = given_cgpa;
            }
            else if(given_term ==22)
            {
               a[k].stu_cgpa22= given_cgpa;
            }
            else if(given_term ==31)
            {
               a[k].stu_cgpa31 = given_cgpa;
            }
            else if(given_term ==32)
            {
               a[k].stu_cgpa32 = given_cgpa;
            }
            else if(given_term ==41)
            {
               a[k].stu_cgpa41 = given_cgpa;
            }
            else if(given_term ==42)
            {
               a[k].stu_cgpa42 = given_cgpa;
            }

        }


    }


   readFile= fopen("x.txt","r+");

    for(int k=0;k<j;k++)
    {
        char p[20];
        char s1[20];
        char s2[20];
        char s3[20];
        if(k != 0)
        {
            fputc('\n',readFile);
        }

        fputs("stu_level:",readFile);
        itoa(a[k].stu_level,s1,10);
        fputs(s1,readFile);
        fputc('\n',readFile);

        fputs("stu_term:",readFile);
        itoa(a[k].stu_term,s2,10);
        fputs(s2,readFile);
        fputc('\n',readFile);

        fputs("stu_batch:",readFile);
        itoa(a[k].stu_batch,s3,10);
        fputs(s3,readFile);
        fputc('\n',readFile);

        fputs("stu_id:",readFile);
        fputs(a[k].stu_id,readFile);
        fputc('\n',readFile);

        fputs("stu_name:",readFile);
        fputs(a[k].stu_name,readFile);
        fputc('\n',readFile);

        fputs("stu_dprtmnt:",readFile);
        fputs(a[k].stu_dprtmnt,readFile);
        fputc('\n',readFile);

        fputs("stu_sec:",readFile);
        fputs(a[k].stu_sec,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa1/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa11);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa1/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa12);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa2/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa21);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa2/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa22);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa3/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa31);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa3/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa32);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa4/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa41);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa4/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa42);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_gender:",readFile);
        fputs(a[k].stu_gender,readFile);
        fputc('\n',readFile);

        fputs("stu_age:",readFile);
        itoa(a[k].stu_age,s1,10);
        fputs(s1,readFile);
        fputc('\n',readFile);

        fputs("stu_bdate:",readFile);
        fputs(a[k].stu_bdate,readFile);
        fputc('\n',readFile);

        fputs("stu_bgrp:",readFile);
        fputs(a[k].stu_bgrp,readFile);
        fputc('\n',readFile);

        fputs("stu_cnmbr:",readFile);
        fputs(a[k].stu_cnmbr,readFile);
        fputc(';',readFile);



    }

   fclose(readFile);
}

void AddData(void)
{
    j++;
        char p[20];
        char s1[20];
        char s2[20];
        char s3[20];

    printf("\nEnter The Student's Level:");
    scanf("%d",&a[k].stu_level);
    fflush(stdin);

    printf("\nEnter The Student's term:");
    scanf("%d",&a[k].stu_term);
    fflush(stdin);

    printf("\nEnter The Student's batch:");
    scanf("%d",&a[k].stu_batch);
    fflush(stdin);

    printf("\nEnter The Student's ID No :");
    gets(a[k].stu_id);
    fflush(stdin);

    printf("\nEnter The Student's Name :");
    gets(a[k].stu_name);
    fflush(stdin);

    printf("\nEnter The Student's Dept. :");
    gets(a[k].stu_dprtmnt);
    fflush(stdin);

    printf("\nEnter The Student's Section :");
    gets(a[k].stu_sec);
    fflush(stdin);

    printf("\nEnter The Student's Cgpa in 1.1 :");
    scanf("%f",&a[k].stu_cgpa11);
    fflush(stdin);

    printf("\nEnter The Student's Cgpa in 1.2 :");
    scanf("%f",&a[k].stu_cgpa12);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 2.1 :");
    scanf("%f",&a[k].stu_cgpa21);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 2.2 :");
    scanf("%f",&a[k].stu_cgpa22);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 3.1 :");
    scanf("%f",&a[k].stu_cgpa31);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 3.2 :");
    scanf("%f",&a[k].stu_cgpa32);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 4.1 :");
    scanf("%f",&a[k].stu_cgpa41);
    fflush(stdin);

     printf("\nEnter The Student's Cgpa in 4.2 :");
    scanf("%f",&a[k].stu_cgpa42);
    fflush(stdin);

    printf("\nEnter The Student's Gender :");
    gets(a[k].stu_gender);
    fflush(stdin);

    printf("\nEnter The Student's Age :");
    scanf("%d",&a[k].stu_age);
    fflush(stdin);

    printf("\nEnter The Student's Birth date :");
    gets(a[k].stu_bdate);
    fflush(stdin);

    printf("\nEnter The Student's blood group :");
    gets(a[k].stu_bgrp);
    fflush(stdin);

    printf("\nEnter The Student's Contact  number :");
    gets(a[k].stu_cnmbr);
    fflush(stdin);



    readFile= fopen("x.txt","a");


        fputc('\n',readFile);
        fputs("stu_level:",readFile);
        itoa(a[k].stu_level,s1,10);
        fputs(s1,readFile);
        fputc('\n',readFile);

        fputs("stu_term:",readFile);
        itoa(a[k].stu_term,s2,10);
        fputs(s2,readFile);
        fputc('\n',readFile);

        fputs("stu_batch:",readFile);
        itoa(a[k].stu_batch,s3,10);
        fputs(s3,readFile);
        fputc('\n',readFile);

        fputs("stu_id:",readFile);
        fputs(a[k].stu_id,readFile);
        fputc('\n',readFile);

        fputs("stu_name:",readFile);
        fputs(a[k].stu_name,readFile);
        fputc('\n',readFile);

        fputs("stu_dprtmnt:",readFile);
        fputs(a[k].stu_dprtmnt,readFile);
        fputc('\n',readFile);

        fputs("stu_sec:",readFile);
        fputs(a[k].stu_sec,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa1/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa11);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa1/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa12);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa2/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa21);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa2/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa22);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa3/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa31);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa3/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa32);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa4/1:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa41);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_cgpa4/2:",readFile);
        sprintf(p,"%.2f",a[k].stu_cgpa42);
        fputs(p,readFile);
        fputc('\n',readFile);

        fputs("stu_gender:",readFile);
        fputs(a[k].stu_gender,readFile);
        fputc('\n',readFile);

        fputs("stu_age:",readFile);
        itoa(a[k].stu_age,s1,10);
        fputs(s1,readFile);
        fputc('\n',readFile);

        fputs("stu_bdate:",readFile);
        fputs(a[k].stu_bdate,readFile);
        fputc('\n',readFile);

        fputs("stu_bgrp:",readFile);
        fputs(a[k].stu_bgrp,readFile);
        fputc('\n',readFile);

        fputs("stu_cnmbr:",readFile);
        fputs(a[k].stu_cnmbr,readFile);
        fputc(';',readFile);

        fclose(readFile);

    }

void NameBasedSearch(void)
{
    system("cls");
    fflush(stdin);
    printf("Enter the name you want to search:  ");
    gets(SeachName);

    for(int k=0;k<j;k++)
    {
        if(strcmp(SeachName,a[k].stu_name)==0)
        {
          SearchNameCount++;
        }
    }
    if(SearchNameCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SearchNameCount);

      printf("Showing all Matched data\n\n");

    for(int k=0;k<j;k++)
    {
        if(strcmp(SeachName,a[k].stu_name)==0)
        {
        printf("Level:\n%d\n",a[k].stu_level);
        printf("Term:\n%d\n",a[k].stu_term);
        printf("Batch:\n%d\n",a[k].stu_batch);
        puts("ID No:");
        puts(a[k].stu_id);
        puts("Depertment:");
        puts(a[k].stu_dprtmnt);
        puts("Section:");
        puts(a[k].stu_sec);
        puts("CGPA in 1.1: ");
        printf("%.2f\n",a[k].stu_cgpa11);
        puts("CGPA in 1.2: ");
        printf("%.2f\n",a[k].stu_cgpa12);
        puts("CGPA in 2.1: ");
        printf("%.2f\n",a[k].stu_cgpa21);
        puts("CGPA in 2.2: ");
        printf("%.2f\n",a[k].stu_cgpa22);
        puts("CGPA in 3.1: ");
        printf("%.2f\n",a[k].stu_cgpa31);
        puts("CGPA in 3.2: ");
        printf("%.2f\n",a[k].stu_cgpa32);
        puts("CGPA in 4.1: ");
        printf("%.2f\n",a[k].stu_cgpa41);
        puts("CGPA in 4.2: ");
        printf("%.2f\n",a[k].stu_cgpa42);
        puts("Gender:");
        puts(a[k].stu_gender);
        printf("Age:\n%d\n",a[k].stu_age);
        puts("Date Of Birth:");
        puts(a[k].stu_bdate);
        puts("Blood Group:");
        puts(a[k].stu_bgrp);
        puts("Contact Number:");
        puts(a[k].stu_cnmbr);
        printf("\n\n");
        }
    }

}


void AgeBasedSearch(void)
{
    system("cls");
    fflush(stdin);
    printf("Enter the age you want to search:  ");
    scanf("%d",&SerachAge);

    for(int k=0;k<j;k++)
    {
        if(a[k].stu_age==SerachAge)
        {
          SerachAgeCount++;
        }
    }
    if(SerachAgeCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachAgeCount);

      printf("Showing all Matched data\n\n");

    for(int k=0;k<j;k++)
    {
        if(a[k].stu_age==SerachAge)
        {
        printf("Level:\n%d\n",a[k].stu_level);
        printf("Term:\n%d\n",a[k].stu_term);
        printf("Batch:\n%d\n",a[k].stu_batch);
        puts("ID No:");
        puts(a[k].stu_id);
        puts("Name:");
        puts(a[k].stu_name);
        puts("Depertment:");
        puts(a[k].stu_dprtmnt);
        puts("Section:");
        puts(a[k].stu_sec);
        puts("CGPA in 1.1: ");
        printf("%.2f\n",a[k].stu_cgpa11);
        puts("CGPA in 1.2: ");
        printf("%.2f\n",a[k].stu_cgpa12);
        puts("CGPA in 2.1: ");
        printf("%.2f\n",a[k].stu_cgpa21);
        puts("CGPA in 2.2: ");
        printf("%.2f\n",a[k].stu_cgpa22);
        puts("CGPA in 3.1: ");
        printf("%.2f\n",a[k].stu_cgpa31);
        puts("CGPA in 3.2: ");
        printf("%.2f\n",a[k].stu_cgpa32);
        puts("CGPA in 4.1: ");
        printf("%.2f\n",a[k].stu_cgpa41);
        puts("CGPA in 4.2: ");
        printf("%.2f\n",a[k].stu_cgpa42);
        puts("Gender:");
        puts(a[k].stu_gender);
        puts("Date Of Birth:");
        puts(a[k].stu_bdate);
        puts("Blood Group:");
        puts(a[k].stu_bgrp);
        puts("Contact Number:");
        puts(a[k].stu_cnmbr);
        printf("\n\n");
        }
    }





}

void CgpaBasedSearch(void)
{

    system("cls");
    fflush(stdin);
    printf("\nEnter the CGPa you want to search:  ");
    scanf("%f",&SerachCgpa);
     printf("\n!!WARNING!!\nFirst enter the level,then the term without any Blank places or any words\n\n");
    printf("\nEnter the Semester you want to Concentrate:  ");
    scanf("%d",&SearchSem);

    if(SearchSem==11){
            for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa11==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa11==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);
                    printf("\n\n");
                }
            }


    }
    if(SearchSem==12){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa12==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa12==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }
    }
    if(SearchSem==21){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa21==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa21==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }
    }
    if(SearchSem==22){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa22==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa22==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }
    }
    if(SearchSem==31){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa31==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa31==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }
    }
    if(SearchSem==32){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa32==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa32==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);
                }
    }
    }
    if(SearchSem==41){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa41==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa41==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }
    }
    if(SearchSem==42){
        for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa42==SerachCgpa)
                {
                    SerachCgpaCount++;
                }
            }
            if(SerachCgpaCount==0){
        printf("\nNo Match Found\n");
        exit(1);
    }
     printf("Match found %d\n",SerachCgpaCount);

      printf("Showing all Matched data\n\n");
      for(int k=0;k<j;k++)
            {
                if(a[k].stu_cgpa42==SerachCgpa)
                {
                    printf("Level:\n%d\n",a[k].stu_level);
                    printf("Term:\n%d\n",a[k].stu_term);
                    printf("Batch:\n%d\n",a[k].stu_batch);
                    puts("ID No:");
                    puts(a[k].stu_id);
                    puts("Name:");
                    puts(a[k].stu_name);
                    puts("Depertment:");
                    puts(a[k].stu_dprtmnt);
                    puts("Section:");
                    puts(a[k].stu_sec);printf("\n\n");
                }
    }

    }
   // return 0;



}


