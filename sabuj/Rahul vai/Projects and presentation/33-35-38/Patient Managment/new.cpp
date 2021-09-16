#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct patient_info
{
    int patient_id;
    char patientname[100];
    int age;
    char gender[10];
    char contuct[15];
    char doctor_name[100];
    char cabin[10];
    char date[100];
    char national_id[100];
} patient[100];
struct branch_info
{
    char branch_name[100];
    int doc_count;
    int patient_at_counter;
    int patients_ids[10];
} branch[100];

int main()
{
    FILE *fp;
    system("color 74");
    fp = fopen("branch.txt", "r");
    
    int i = 0, j = 0, k = 0, doc_flag = 0, branch_flag = 0, patient_flag = 0, patient_i_flag = 0;
    int branchIndex = 0, patientIndex = 0;
    char ch;
    char str[100];
    while(1){
    while((ch = fgetc(fp)) != EOF)
    {
        if((ch == '\n') && (branch_flag == 1))
        {
            str[i] = '\0';
            i = 0;
            strcpy(branch[branchIndex].branch_name, str);
            branch_flag = 0;
            continue;
        }
        if((ch == '\n') && (doc_flag == 1))
        {
            str[i] = '\0';
            i = 0;
            branch[branchIndex].doc_count = atoi(str);
             doc_flag = 0;
            continue;
        }
        if(ch == '\n' && patient_i_flag == 1)
        {
            str[i] = '\0';
            i = 0;
            patient_i_flag = 0;
            branch[branchIndex].patients_ids[patientIndex] = atoi(str);
            patientIndex++;
            continue;
        }
        if(ch == ':')
        {
            str[i] = '\0';
            i = 0;
            if(strcmp(str, "Branch_name") == 0)
            {
                branch_flag = 1;
            }
            if(strcmp(str, "Doctor_count") == 0)
            {
                doc_flag = 1;
            }
            if(strcmp(str, "Patient_id") == 0)
            {
                patient_i_flag = 1;
            }
            continue;
        }
        if(ch == ';' && patient_i_flag == 1)
        {
            str[i] = '\0';
            i = 0;
            patient_i_flag = 0;
            branch[branchIndex].patients_ids[patientIndex] = atoi(str);
            //branch[branchIndex].patient_at_counter = patientIndex + 1;
            branchIndex++;
            patientIndex = 0;
            continue;
        }
        if(ch == '\n')
        {
            i = 0;
            continue;
        }
        str[i] = ch;
        i++;
    }
    fclose(fp);


    FILE *fp1;
    fp1 = fopen("details.txt", "r");
    int patient_id_flag = 0, patient_name_flag = 0,cabin_flag=0,contuct_flag=0, gender_flag = 0, national_id_flag = 0, age_flag = 0,doctor_name_flag=0,date_flag=0;
    char c;
    patientIndex = 0;
    i = 0;
    char str2[100];
    while((c = fgetc(fp1)) != EOF)
    {
        if(c == '\n' && patient_id_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            patient_id_flag = 0;
            patient[patientIndex].patient_id = atoi(str2);
            continue;
        }
        if(c == '\n' && patient_name_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            patient_name_flag = 0;
            strcpy(patient[patientIndex].patientname, str2);
            continue;
        }
        if(c == '\n' && gender_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            gender_flag = 0;
            strcpy(patient[patientIndex].gender, str2);
            continue;
        }

        if(c == '\n' && age_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            age_flag = 0;
            patient[patientIndex].age = atoi(str2);
            continue;
        }
        if(c == '\n' && doctor_name_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            doctor_name_flag = 0;
            strcpy(patient[patientIndex].doctor_name, str2);
            continue;
        }
        if(c == '\n' && contuct_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            contuct_flag = 0;
            strcpy(patient[patientIndex].contuct, str2);
            continue;
        }
        if(c == '\n' && cabin_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            cabin_flag = 0;
            strcpy(patient[patientIndex].cabin, str2);
            continue;
        }
        if(c == '\n' && date_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            date_flag = 0;
            strcpy(patient[patientIndex].date, str2);
            continue;
        }
        if(c == '\n' && national_id_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            national_id_flag = 0;
            strcpy(patient[patientIndex].national_id, str2);
            patientIndex++;
            continue;
        }
        if(c == ':')
        {
            str2[i] = '\0';
            i = 0;
            if(strcmp(str2, "PATIENT_ID") == 0)
            {
                patient_id_flag = 1;
            }
            if(strcmp(str2, "PATIENT_NAME") == 0)
            {
                patient_name_flag = 1;
            }
            if(strcmp(str2, "AGE") == 0)
            {
                age_flag = 1;
            }
            if(strcmp(str2, "GENDER") == 0)
            {
                gender_flag = 1;
            }
            if(strcmp(str2, "DOCTOR_NAME") == 0)
            {
                doctor_name_flag = 1;
            }

            if(strcmp(str2, "CABIN") == 0)
            {
                cabin_flag= 1;
            }

            if(strcmp(str2, "CONTUCT") == 0)
            {
                contuct_flag= 1;
            }
            if(strcmp(str2, "DATE") == 0)
            {
                date_flag= 1;
            }
            if(strcmp(str2, "NATIONAL_ID") == 0)
            {
                national_id_flag = 1;
            }
            continue;
        }
        if(ch == '\n')
        {
            i = 0;
            continue;
        }
        str2[i] = c;
        i++;
    }
    fclose(fp1);

    int searchId;
    printf("*****************************************************************\n");
    printf("********************PATEINT MANAGMENT SYSTEM*********************\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("********************                        *********************\n\n");
    printf("Enter ID Number to find all information about a Patient:\n");
    printf("ID:");
    scanf("%d", &searchId);

    int found_branch_index = 1, found_patient_index = 1;

    for(int i = 0; i < branchIndex; i++)
    {
        for(int p = 0; p < branch[i].patient_at_counter; p++)
        {
            if(branch[i].patients_ids[p] == searchId)
            {
                found_branch_index = i;
                break;
            }
        }
        if(found_branch_index != -1)break;
    }
    for(i = 0; i < patientIndex; i++)
    {
        if(patient[i].patient_id == searchId)
        {
            found_patient_index = i;
            break;
        }
    }

    if(found_branch_index != -1 && found_patient_index != -1)
    {
    printf("*****************************************************************\n");
    printf("********************->Patient's Details Info:********************\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("********************                        *********************\n");

        printf("ID:               %d\n", patient[found_patient_index].patient_id);
        printf("NAME:             ");
        puts(patient[found_patient_index].patientname);
        printf("AGE:              %d\n", patient[found_patient_index].age);
        printf("GENDER:           ");
        puts(patient[found_patient_index].gender);
        printf("CONTUCT NO:       ");
        puts(patient[found_patient_index].contuct);
        printf("CABIN NO:         ");
        puts(patient[found_patient_index].cabin);
        printf("DOCTOR:           ");
        puts(patient[found_patient_index].doctor_name);
        printf("DATE OF ADMISSION:");
        puts(patient[found_patient_index].date);
        printf("NATIONAL ID:      ");
        puts(patient[found_patient_index].national_id);
        
        printf("BRANCH:           ");
        puts(branch[found_branch_index].branch_name);
        printf("Doctor Count:     %d\n", branch[found_branch_index].doc_count);
    }
    else
    {
        printf("There's no patient with id %d\n", searchId);
    }
  }
    return 0;
}
