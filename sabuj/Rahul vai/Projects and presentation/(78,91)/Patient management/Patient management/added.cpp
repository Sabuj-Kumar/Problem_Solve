#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct info
{
    char patient_id[100], contact[20], branch[100];
    char patient_name[100], cabin[100];
    int age;
    char gender[10], entry_day[100];
    char national_id[100], ref_doct[100];

} s[100];

int main()
{
    FILE *fp1;
    fp1=fopen("input.txt","r");
    int i=0,j=0,k,patient_id_flag=0,patient_name_flag=0,gender_flag=0,national_id_flag=0,age_flag=0;
    int contact_f=0, branch_f=0, cabin_f=0, entry_day_f=0, ref_doct_f=0;
    char ch;
    char str[100];
    while(1)
    {
        while((ch=fgetc(fp1))!=EOF)
        {
            if(ch=='\n' && contact_f==1)
            {
                str[i]='\0';
                i=0;
                contact_f=0;
                strcpy(s[j].contact,str);
            }
            if(ch=='\n' && branch_f==1)
            {
                str[i]='\0';
                i=0;
                branch_f=0;
                strcpy(s[j].branch,str);
            }
            if(ch=='\n' && cabin_f==1)
            {
                str[i]='\0';
                i=0;
                cabin_f=0;
                strcpy(s[j].cabin,str);
            }
            if(ch=='\n' && entry_day_f==1)
            {
                str[i]='\0';
                i=0;
                entry_day_f=0;
                strcpy(s[j].entry_day,str);
            }
            if(ch=='\n' && ref_doct_f==1)
            {
                str[i]='\0';
                i=0;
                ref_doct_f=0;
                strcpy(s[j].ref_doct,str);
                j++;
            }
            if(ch=='\n' && patient_id_flag==1)
            {
                str[i]='\0';
                i=0;
                patient_id_flag=0;
                strcpy(s[j].patient_id,str);
            }
            if(ch=='\n' && patient_name_flag==1)
            {
                str[i]='\0';
                i=0;
                patient_name_flag=0;
                strcpy(s[j].patient_name,str);
            }
            if(ch=='\n' && gender_flag==1)
            {
                str[i]='\0';
                i=0;
                gender_flag=0;
                strcpy(s[j].gender,str);
            }
            if(ch=='\n' && national_id_flag==1)
            {
                str[i]='\0';
                i=0;
                national_id_flag=0;
                strcpy(s[j].national_id,str);
            }
            if(ch=='\n' && age_flag==1)
            {
                str[i]='\0';
                i=0;
                age_flag=0;
                s[j].age=atoi(str);
            }
            if(ch==':')
            {
                str[i]='\0';
                i=0;
                if(strcmp(str,"PATIENT_ID")==0)
                {
                    patient_id_flag=1;
                }
                if(strcmp(str,"PATIENT_NAME")==0)
                {
                    patient_name_flag=1;
                }
                if(strcmp(str,"AGE")==0)
                {
                    age_flag=1;
                }
                if(strcmp(str,"GENDER")==0)
                {
                    gender_flag=1;
                }
                if(strcmp(str,"NATIONAL_ID")==0)
                {
                    national_id_flag=1;
                }
                if(strcmp(str,"CONTACT_NO")==0)
                {
                    contact_f=1;
                }
                if(strcmp(str,"BRANCH")==0)
                {
                    branch_f=1;
                }
                if(strcmp(str,"CABIN")==0)
                {
                    cabin_f=1;
                }
                if(strcmp(str,"DAY-OF-ENTRY")==0)
                {
                    entry_day_f=1;
                }
                if(strcmp(str,"REFERENCE_DOCTOR")==0)
                {
                    ref_doct_f=1;
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
        fclose(fp1);
        printf("********************########################*********************\n");
        printf("*                   PATIENT MANAGMENT SYSTEM                    *\n");
        printf("*                                                               *\n");
        printf("*                                                               *\n");
        printf("*                                                               *\n");
        printf("*****************************************************************\n\n");
        int n,p;
        printf("TO SEEK BRANCH INFO PRESS 1\n");
        printf("TO SEEK PATIENT INFO PRESS 2\n");
        puts("TO SEE A DOCTOR AND HIS PATIENTS PRESS 3");

        scanf("%d",&n);
        printf("\n\n");
        if(n==2)
        {
            printf("\nENTER PATIENT ID:");
            scanf("%d",&p);
            for(i=p-1; i<p; i++)
            {
                printf("PATIENT DETAILS->:::\n\n");
                printf("PATIENT ID:  ");
                puts(s[i].patient_id);
                printf("AGE:         %d\n",s[i].age);
                printf("PATIENT NAME:");
                puts(s[i].patient_name);
                printf("GENDER:      ");
                puts(s[i].gender);
                printf("NATIONAL ID: ");
                puts(s[i].national_id);
                printf("BRANCH:      ");
                puts(s[i].branch);
                printf("CONTACT NUM: ");
                puts(s[i].contact);
                printf("CABIN NO:    ");
                puts(s[i].cabin);
                printf("ENTRY DATE:  ");
                puts(s[i].entry_day);
                printf("REF DOCTOR:  ");
                puts(s[i].ref_doct);
                puts("\n");
            }
        }
        char r[100];
        if(n==1)
        {
            for(i=0; i<100; i++)
            {
                printf("BRANCH:");
                puts(s[i].branch);

            }
            puts("ENTER BRANCH NAME:");
            fflush(stdin);
            gets(r);
            int counter=0;
            for(i=0; i<100; i++)
            {
                if(strcmp(s[i].branch,r)==0)
                {
                    counter++;
                    printf("PATIENT DETAILS->:::\n\n");
                    printf("PATIENT ID:  ");
                    puts(s[i].patient_id);
                    printf("AGE:         %d\n",s[i].age);
                    printf("PATIENT NAME:");
                    puts(s[i].patient_name);
                    printf("GENDER:      ");
                    puts(s[i].gender);
                    printf("NATIONAL ID: ");
                    puts(s[i].national_id);
                    printf("BRANCH:      ");
                    puts(s[i].branch);
                    printf("CONTACT NUM: ");
                    puts(s[i].contact);
                    printf("CABIN NO:    ");
                    puts(s[i].cabin);
                    printf("ENTRY DATE:  ");
                    puts(s[i].entry_day);
                    printf("REF DOCTOR:  ");
                    puts(s[i].ref_doct);
                    puts("\n");
                }
            }
            printf("Number of Patient = %d\n",counter);
            counter=0;
        }
        if(n==3)
        {
            puts("all the doctors names are given bellow");
            for(i=0; i<100; i++)
            {
                printf("REF DOCTOR:  ");
                puts(s[i].ref_doct);
            }
            printf("Enter the Doctor's name ...");
            char dname[100];
            getchar();
            gets(dname);
            puts(dname);
            puts("following patients are under his or her treatment");
            for(int i=0; i<100; i++)
            {
                if(!strcmp(s[i].ref_doct,dname))
                {
                    printf("PATIENT DETAILS->:::\n\n");
                    printf("PATIENT ID:  ");
                    puts(s[i].patient_id);
                    printf("AGE:         %d\n",s[i].age);
                    printf("PATIENT NAME:");
                    puts(s[i].patient_name);
                    printf("GENDER:      ");
                    puts(s[i].gender);
                    printf("NATIONAL ID: ");
                    puts(s[i].national_id);
                    printf("BRANCH:      ");
                    puts(s[i].branch);
                    printf("CONTACT NUM: ");
                    puts(s[i].contact);
                    printf("CABIN NO:    ");
                    puts(s[i].cabin);
                    printf("ENTRY DATE:  ");
                    puts(s[i].entry_day);
                }
            }
        }
    }
    return 0;
}
