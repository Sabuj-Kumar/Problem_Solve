#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct info{
      char st_id[10];
	char st_name[100];
	char st_gender[6];
	int st_age;
	char year[5];
	char sem[5];
	float cgpa;
}s[24];

int main()
{

    FILE *fp1;
    fp1=fopen("all student_info.txt","r");
    int i=0,j=0,k=0,q=0,st_id_flag=0,st_name_flag=0,st_gender_flag=0,st_age_flag=0,year_flag=0,sem_flag=0,cgpa_flag=0;
    char ch;
    char str[100];
    while((ch=fgetc(fp1))!=EOF)
    {
        if(ch=='\n' && st_id_flag==1)
        {
            str[i]='\0';
            i=0;

            st_id_flag=0;
            strcpy(s[j].st_id,str);
        }

        if(ch=='\n' && st_name_flag==1)
        {
            str[i]='\0';
            i=0;

            st_name_flag=0;
            strcpy(s[j].st_name,str);
        }



        if(ch=='\n' && st_gender_flag==1)
        {
            str[i]='\0';
            i=0;

            st_gender_flag=0;
            strcpy(s[j].st_gender,str);
        }/////////////


        if(ch=='\n' && st_age_flag==1)
        {
            str[i]='\0';
            i=0;
            st_age_flag=0;
            s[j].st_age = atoi(str);
           // j++;
        }

         if(ch=='\n' && year_flag==1)
        {
            str[i]='\0';
            i=0;

            year_flag=0;
            strcpy(s[j].year,str);
        }

         if(ch=='\n' && sem_flag==1)
        {
            str[i]='\0';
            i=0;

            sem_flag=0;
            strcpy(s[j].sem,str);
        }

  //int formate


        if(ch=='\n' && cgpa_flag==1)
        {
            str[i]='\0';
            i=0;
            cgpa_flag=0;
            s[j]. cgpa = atof(str);
            j++;
        }



        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"stdent_id")==0)
            {
                st_id_flag=1;
            }


             if(strcmp(str,"student_name")==0)
            {
                st_name_flag=1;
            }


             if(strcmp(str,"student_gender")==0)
            {
                st_gender_flag=1;
            }/////

             if(strcmp(str,"student_age")==0)
            {
                st_age_flag=1;
            }


            if(strcmp(str,"student_year")==0)
            {
                year_flag=1;
            }

            if(strcmp(str,"student_semester")==0)
            {
                sem_flag=1;
            }

            if(strcmp(str,"student_cgpa")==0)
            {
                cgpa_flag=1;
            }






        }
        else
        {
            if(ch!='\n'){
            str[i]=ch;
            i++;
            }
        }

    }
    if(cgpa_flag==1)
        {
            str[i]='\0';
            i=0;
            cgpa_flag=0;
            s[j].cgpa=atof(str);
            j++;
        }


        /////////////////////////
    fclose(fp1);


    for(i=0;i<24;i++)
    {
    	printf("student id :");
    	puts(s[i].st_id);
    	printf("\nstudent name :");
        puts(s[i].st_name);
        printf("\nstudent gender :");
        puts(s[i].st_gender);
       // printf("\nstudent age :");
        printf("student age is=%d\n",s[i].st_age);
        printf("\nsem year :");
        puts(s[i].year);
        printf("\nsemester :");
        puts(s[i].sem);
        printf("\nstudent cgpa :");
       // puts(s[i].st_name);
        printf("student cgpa is=%0.2f\n",s[i].cgpa);
        printf("\n\n\n");

    }


    fp1=fopen("output.txt","a+");
    for(i=0;i<24;i++)
    {

        fputs("student NAME     :",fp1);
        fputs(s[i].st_name,fp1);
        fputc('\n',fp1);

        fputs("student gender  :",fp1);
        fputs(s[i].st_gender,fp1);
        fputc('\n',fp1);
    }
    fclose(fp1);


    return 0;
}
