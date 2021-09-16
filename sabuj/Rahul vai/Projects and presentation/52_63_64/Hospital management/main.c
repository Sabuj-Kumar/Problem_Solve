#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct doctor_info
{
    char doctorname[100];
    //char doctor_consult[100];
} doctor[50];

struct patient2_info
{
    char patientName[100];
    //char patient_blood[50];
} patient2[50];

struct nurse_info
{
    char nursename[100];
} nurse[50];



struct patient_info
{
    char patient_blood[50];
    char doctor_consult[100];
    int patient_id;
    char patientname[100];
    int age;
    char gender[10];
    char doctor_name[100];
    char cabin[10];
    char problem[100];
    char nurse_name[100];

} patient[50];



int main()
{
    FILE *dn;
    int l;

    dn=fopen("doctor.txt","r");

    for(l=0;l<25;l++)
    {
        fscanf(dn,"%s\n",&doctor[l].doctorname);
    }

    FILE *pn;
    int x;

    pn=fopen("patient.txt","r");

    for(x=0;x<50;x++)
    {
        fscanf(pn,"%s\n",&patient2[x].patientName);
    }

    FILE *nn;
    int y;

    nn=fopen("nurse.txt","r");

    for(y=0;y<25;y++)
    {
        fscanf(nn,"%s\n",&nurse[y].nursename);
    }



    FILE *fp;
    char ch,s1[100];
    int i,j,k;

    fp=fopen("data.txt","r");

    for(i=0;i<50;i++)
    {
        fscanf(fp,"%d %s %d %s %s %s %s %s %s %s",&patient[i].patient_id,&patient[i].patientname,&patient[i].age,&patient[i].gender,&patient[i].doctor_name,&patient[i].cabin,&patient[i].problem,&patient[i].nurse_name,&patient[i].doctor_consult,&patient[i].patient_blood);
    }



    //Menu for HMS
    printf("\n\n\n\n ************** < Welcome to P N M Hospital Management System > **************");
    printf("\n\t\t------------------------------------------------\n");
    int searchingMode=10;

    while(searchingMode != 0)
    {

    printf("\n\t\t\tPress 1 for searching doctors");
    printf("\n\t\t\tPress 2 for searching patient");
    printf("\n\t\t\tPress 3 for searching nurse");
    printf("\n\t\t\tPress 0 for end searching\n");
    printf("\n\t\t------------------------------------------------\n");
    printf("\n\t\t\tSelect any one iteam------");


    scanf("%d",&searchingMode);

    //gets(s1);//for doctors name

    if(searchingMode !=0)
    {
        if(searchingMode == 1)
        {
            printf("Choose doctor name: ");

             for(l=0;l<50;l++)
                {
                    printf("\n %s",doctor[l].doctorname);
                }
            printf("\nEnter: ");
            scanf("%s",&s1);

        }else if(searchingMode == 2)
        {
            printf("Choose patient name: ");
            for(l=0;l<50;l++)
                {
                    printf("\n %s",patient2[l].patientName);
                }
            printf("\nEnter: ");
            scanf("%s",&s1);
        }else if(searchingMode == 3)
        {
            printf("Choose nurse name: ");
            for(l=0;l<50;l++)
                {
                    printf("\n %s",nurse[l].nursename);
                }
            printf("\nEnter: ");
            scanf("%s",&s1);
        }
    }


    if(searchingMode == 1)
    {
         int doctorsPresent=0;

        for(i=0;i<50;i++)
        {
            if(strcmp(patient[i].doctor_name,s1)==0)
            {
                printf("\nPatientID:%d\nName:%s\nProblem:%s\nNurse:%s\nConsultation:%s\n\n",patient[i].patient_id,patient[i].patientname, patient[i].problem,patient[i].nurse_name,patient[i].doctor_consult);
                doctorsPresent = 1;
            }
        }
        if(doctorsPresent != 1)//if doctors not present with the given name
                {
                    printf("No doctors available with this name");
                }

    }
    else if(searchingMode == 2)
    {
        int patientPresent=0;

         for(i=0;i<50;i++)
            {
                if(strcmp(patient[i].patientname,s1)==0)
                {
                    printf("\nPatient_ID:%d\nDoctor_Name:%s\nProblem:%s\nNurse_Name:%s\nBlood_Group:%s\n\n",patient[i].patient_id,patient[i].doctor_name,patient[i].problem,patient[i].nurse_name,patient[i].patient_blood);
                    patientPresent = 1;
                }
            }
            if(patientPresent != 1)//if patients not present with the given name
                {
                    printf("No patient available with this name");
                }
    }
    else if(searchingMode == 3)
    {
        int nursePresent=0;

          for(i=0;i<50;i++)
            {
                if(strcmp(patient[i].nurse_name,s1)==0)
                {
                    printf("\nPatientID:%d\nPatientName:%s\nProblem:%s\nDoctorName:%s\n\n",patient[i].patient_id,patient[i].patientname,patient[i].problem,patient[i].doctor_name);
                    nursePresent = 1;
                }
            }
            if(nursePresent != 1)//if nurses not present with the given name
                {
                    printf("No nurse available with this name");
                }
    }


 }

    return 0;
}
