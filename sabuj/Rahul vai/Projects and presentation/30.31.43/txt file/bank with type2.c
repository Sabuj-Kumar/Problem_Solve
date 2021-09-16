#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct bank_info
{
	char type[100];
    char branch[100];
	char id[100][100];
}db1[100];

struct info
{
	char id[100];
    char name[100];
    int age;
    char gender[10];
    char blood[4];
    char total[100];
    char last_dep[100];
    char last_wid[100];
    char total_t[100];
    char contact[100];
    char acc_no[100];
}db[100];
int main()
{
/********** first text *********/
    FILE *fp1;
    fp1=fopen("type.txt","r");
    int i=0,j=0,k=0;
    int type_flag=0,branch_flag=0,id_list_flag=0;
    int id_flag=0,blood_flag=0,last_wid_flag=0,total_t_flag=0,contact_flag=0,name_flag=0,gender_flag=0,total_flag=0,last_dep_flag,acc_flag=0,age_flag=0;
    char ch,str[200];
    while((ch=fgetc(fp1))!=EOF)
        {
		if((ch=='\n') && (type_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db1[k].type,str);
			type_flag=0;
			continue;
		}
		if((ch=='\n') && (branch_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db1[k].branch,str);
			branch_flag=0;
			continue;
		}
		if((ch=='\n') && (id_flag==1))
		{
			id_flag=0;
			id_list_flag=1;
			continue;
		}
		if(ch==':')
		{
			str[i]='\0';
			i=0;
			if(strcmp(str,"type")==0)
			{
				type_flag=1;

			}
			if(strcmp(str,"branch")==0)
			{
				branch_flag=1;

			}
			if(strcmp(str,"id")==0)
			{
				id_flag=1;
			}
			continue;
		}

		else if((id_list_flag==1) && (ch=='\n'))
		{

			str[i]='\0';
			i=0;
			strcpy(db1[k].id[j],str);

			j++;
			continue;
		}
		else if(ch==';')
		{

			str[i]='\0';
			i=0;
			strcpy(db1[k].id[j],str);


			k++;

			j=0;
			id_list_flag=0;
			continue;
		}
		else if(ch=='\n')
		{
			continue;
		}


        str[i]=ch;
		i++;
	}
	fclose(fp1);
	for(i=0;i<10;i++)
    {
     	puts(db1[i].branch);

    }
	char search[100];
    gets(search);

	for(i=0;i<10;i++)
    {
        if((strcmp(db1[i].branch,search)==0))

	{
		for(j=0;j<10;j++)
		{
			puts(db1[i].id[j]);
		}
	}
    }
	/**********2nd text**********/
    FILE *fp2;
    fp2=fopen("new.txt","r");
    id_flag=0;
    i=0;j=0;k=0;
    while((ch=fgetc(fp2))!=EOF)
    {
        if(ch=='\n' && id_flag==1)
        {
            str[i]='\0';
            i=0;

            id_flag=0;
            strcpy(db[j].id,str);
        }
        if(ch=='\n' && name_flag==1)
        {
            str[i]='\0';
            i=0;

            name_flag=0;
            strcpy(db[j].name,str);
        }
        if(ch=='\n' && gender_flag==1)
        {
            str[i]='\0';
            i=0;

            gender_flag=0;
            strcpy(db[j].gender,str);
        }
        if(ch=='\n' && blood_flag==1)
        {
            str[i]='\0';
            i=0;

            blood_flag=0;
            strcpy(db[j].blood,str);
        }
        if(ch=='\n' && total_flag==1)
        {
            str[i]='\0';
            i=0;

            total_flag=0;
            strcpy(db[j].total,str);
        }
        if(ch=='\n' && last_dep_flag==1)
        {
            str[i]='\0';
            i=0;

            last_dep_flag=0;
            strcpy(db[j].last_dep,str);
        }
        if(ch=='\n' && last_wid_flag==1)
        {
            str[i]='\0';
            i=0;

            last_wid_flag=0;
            strcpy(db[j].last_wid,str);
        }
        if(ch=='\n' && total_t_flag==1)
        {
            str[i]='\0';
            i=0;

            total_t_flag=0;
            strcpy(db[j].total_t,str);
        }
        if(ch=='\n' && contact_flag==1)
        {
            str[i]='\0';
            i=0;

            contact_flag=0;
            strcpy(db[j].contact,str);
        }
        if(ch=='\n' && acc_flag==1)
        {
            str[i]='\0';
            i=0;

            acc_flag=0;
            strcpy(db[j].acc_no,str);
            j++;
        }
        if(ch=='\n' && age_flag==1)
        {
            str[i]='\0';
            i=0;
            age_flag=0;
            db[j].age=atoi(str);
        }
        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"ID")==0)
            {
                id_flag=1;
            }
            if(strcmp(str,"NAME")==0)
            {
                name_flag=1;
            }
            if(strcmp(str,"AGE")==0)
            {
                age_flag=1;
            }
            if(strcmp(str,"GENDER")==0)
            {
                gender_flag=1;
            }
            if(strcmp(str,"BLOOD_GROUP")==0)
            {
                blood_flag=1;
            }
            if(strcmp(str,"TOTAL")==0)
            {
                total_flag=1;
            }
            if(strcmp(str,"LAST_DEP")==0)
            {
                last_dep_flag=1;
            }
             if(strcmp(str,"LAST_WID")==0)
            {
                last_wid_flag=1;
            }
             if(strcmp(str,"TOTAL_T")==0)
            {
                total_t_flag=1;
            }
             if(strcmp(str,"CONTACT_NUM")==0)
            {
                contact_flag=1;
            }
            if(strcmp(str,"ACC_NO")==0)
            {
                acc_flag=1;
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
    fclose(fp2);

    gets(search);
    j=0;
    k=0;
    for(i=0;i<10;i++)
    {
    for(j=0;j<2;j++)
    {
        if((strcmp(db1[i].id[j],search)==0))
    {
        for(k=0;k<100;k++)
        {
    if((strcmp(db[k].id,search)==0))
        {
        printf("ID:");
        puts(db[i].id);
        printf("AGE:%d\n",db[i].age);
        printf("NAME:");
        puts(db[i].name);
        printf("GENDER:");
        puts(db[i].gender);
        printf("BLOOD GROUP:");
        puts(db[i].blood);
        printf("TOTAL AMOUNT:");
        puts(db[i].total);
        printf("LAST DEPOSITE:");
        puts(db[i].last_dep);
        printf("LAST WITHDRAW:");
        puts(db[i].last_wid);
        printf("TOTAL TRANSACTION:");
        puts(db[i].total_t);
        printf("CONTACT NUMBER:");
        puts(db[i].contact);
        printf("ACCOUNT NO:");
        puts(db[i].acc_no);
        }
        }
    }
    }
    }



        return 0;
}
