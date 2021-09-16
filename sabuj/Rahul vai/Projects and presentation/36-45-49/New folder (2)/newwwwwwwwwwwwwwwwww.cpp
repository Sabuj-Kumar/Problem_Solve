#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct hospital_info
{
	char hospital_name[100];
	int branch_count;
	int branch_id;
	char branch_name[100][100];
	char id_list[100][100];
}db[2];

             struct doctor_info
{
    char doctorname[100];
} doctor[50];
             struct patient_info
{
    char patientname[100];
} patient[50];
struct nurse_info
{
    char nursename[100];
} nurse[50];
struct branch_info
{
    char branchname[100];
} branch[50];



int main()
{
	FILE *fp;
	fp=fopen("8.txt","r");
	char ch,str[200];
	int i=0,j=0,d=0,k=0,q=0,id_flag=0,id_list_flag=0,hospital_flag=0,branch_name_flag=0,count_flag=0,branch_list_flag=0;
	while((ch=fgetc(fp))!=EOF)
	{
		if((ch=='\n') && (hospital_flag==1))
		{
			str[i]='\0';
			i=0;

			strcpy(db[k].hospital_name,str);
			hospital_flag=0;
			continue;
		}
		if((ch=='\n') && (count_flag==1))
		{
			str[i]='\0';
			i=0;

			db[k].branch_count=atoi(str);
			count_flag=0;
			continue;
		}
		if((ch=='\n') && (branch_name_flag==1))
		{
			branch_name_flag=0;
			branch_list_flag=1;
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

			if(strcmp(str,"hospital_name")==0)
			{
				hospital_flag=1;

			}
			if(strcmp(str,"branch_count")==0)
			{
				count_flag=1;

			}
			if(strcmp(str,"branch_list")==0)
			{
				branch_name_flag=1;
			}
			if(strcmp(str,"id_list")==0)
			{
				id_flag=1;
			}
			continue;
		}

		else if((branch_list_flag==1) && (ch=='\n'))
		{

			str[i]='\0';
			i=0;
			strcpy(db[k].branch_name[j],str);

			j++;
			continue;
		}
		else if((id_list_flag==1) && (ch=='\n'))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].id_list[d],str);
			d++;
			continue;
		}
		else if(ch==';' && branch_list_flag==1)
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].branch_name[j],str);

			j=0;
			branch_list_flag=0;
			continue;
		}
		else if(ch==';' && id_list_flag==1)
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].id_list[d],str);
			k++;

			d=0;
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
	  printf("************** <WELCOME TO OUR HOSPITAL MANAGEMENT SYSTEM > **************");
	    printf("*************<                         > **************");
	      printf("**************<                 > **************");
	        printf("*******************< > **************");
	        printf("\n\n\n");
	fclose(fp);
	for(i=0;i<2;i++)
	{
		puts(db[i].hospital_name);
		printf("branch count = %d\n",db[i].branch_count);
		for(j=0;j<2;j++)
		{
			puts(db[i].branch_name[j]);

		}
		for(j=0;j<2;j++)
		{
			puts(db[i].id_list[j]);
		}
		printf("\n");

	}
	fclose(fp);
	  FILE *dn;
    int l;
	//printf("IBNA SINA DOCTOR LIST:");
	 dn=fopen("0.txt","r");

    for(l=0;l<21;l++)
    {
        fscanf(dn,"%s\n",&doctor[l].doctorname);
    }
    	  FILE *dm;
    int x;
	//printf("IBNA SINA DOCTOR LIST:");
	 dm=fopen("00.txt","r");

    for(x=0;x<21;x++)
    {
        fscanf(dm,"%s\n",&patient[x].patientname);
        }
          	  FILE *dr;
    int y;
	//printf("IBNA SINA DOCTOR LIST:");
	 dr=fopen("000.txt","r");

    for(y=0;y<21;y++)
    {
        fscanf(dr,"%s\n",&nurse[y].nursename);
    }
            	  FILE *dz;
    int z;
	//printf("IBNA SINA DOCTOR LIST:");
	 dz=fopen("0000.txt","r");

    for(z=0;z<21;z++)
    {
        fscanf(dz,"%s\n",&branch[z].branchname);
    }



	    printf("\n\t\t------------------------------------------------\n");
    int searchingMode=10;
    char s1[100];

    while(searchingMode != 0)
    {
    printf("\n\tPress 1 for detail IBNA SINA HOSPITAL danmondi branch>> \n\n");
    printf("Press 2 for detail IBNA SINA HOSPITAL kolyanpur branch>> \n\n");
    printf("Press 3 for detail CARE HOSPITAL asadgate branch>> \n\n");
    printf("Press 4 for detail CARE HOSPITAL collegegate branch>> \n\n");
    printf("\n\t\t------------------------------------------------\n\n");
    printf("\n\t\t\tSelect any one iteam------>\n\n");


    scanf("%d",&searchingMode);



        if(searchingMode == 1)
        {
                           printf("IBNA SINA..>>BRANCH=01\n");

             for(l=0;l<21;l++)
                {

                    printf("\n %s",doctor[l].doctorname);
                }
            printf("\nEnter: ");
           scanf("%s",&s1);
           }
          if(searchingMode == 2)
            //printf("IBNA SINA..>>BRANCH=02\n");
        {
            printf("IBNA SINA..>>BRANCH=02\n");
            for(x=0;x<21;x++)
                {
                    printf("\n %s",patient[x].patientname);
                }
                          printf("\nEnter: ");
            scanf("%s",&s1);
        }
        if(searchingMode == 3)
          //printf("CARE HOSPITAL..>>BRANCH=01\n ");
        {
          printf("CARE HOSPITAL..>>BRANCH=01\n ");
            for(y=0;y<21;y++)
                {
                    printf("\n %s",nurse[y].nursename);
                }
            printf("\nEnter: ");
            scanf("%s",&s1);
        }
        if(searchingMode == 4)
         // printf("CARE HOSPITAL..>>BRANCH=02\n");
        {
           printf("CARE HOSPITAL..>>BRANCH=02\n");
            for(z=0;z<21;z++)
                {
                    printf("\n %s",branch[z].branchname);
                }
            printf("\nEnter: ");
            scanf("%s",&s1);
        }
        }
getch();
return 0;
}




