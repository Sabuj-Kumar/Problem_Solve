#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct plane_info
{
     char planename[100];
     int plane_id;
     int seatno;
     char time[100];
     char gate[100];
     char date[100];

}db[50];
struct airline_info
{
	char e_name[100];
	char p_name[100][100];
}db1[5];


int main()
{
    system("color 34");
    FILE *a,*b;
    a=fopen("airline.txt","r");
    char ch;
    while((ch=fgetc(a))!=EOF)

    {
        printf("%c",ch);
    }
    printf("\n");
    FILE *fp;//*fp1;



    fp=fopen("input.txt","r");

	char str[600];
	int i=0,j=0,k=0,q=0,p_name_flag=0,e_name_flag=0,p_list_flag=0;
	while((ch=fgetc(fp))!=EOF)
	{
		if((ch=='\n') && (e_name_flag==1))
		{
			str[i]='\0';
			i=0;

			strcpy(db1[k].e_name,str);
			e_name_flag=0;
			continue;
		}
		if((ch=='\n') && (p_name_flag==1))
		{
			p_name_flag=0;
			p_list_flag=1;
			continue;
		}
		if(ch==':')
		{
			str[i]='\0';
			i=0;
			if(strcmp(str,"E_NAME")==0)
			{
				e_name_flag=1;

			}
			if(strcmp(str,"P_LIST")==0)
			{
				p_name_flag=1;
				//printf("%d	",k);
			}
			continue;
		}

		else if((p_list_flag==1) && (ch=='\n'))
		{

			str[i]='\0';
			i=0;
			strcpy(db1[k].p_name[j],str);

			j++;
			continue;
		}
		else if(ch==';')
		{

			str[i]='\0';
			i=0;
			strcpy(db1[k].p_name[j],str);


			k++;

			j=0;
			p_list_flag=0;
			continue;
		}
		else if(ch=='\n')
		{
			continue;
		}


        str[i]=ch;
		i++;
	}
   fclose(fp);

	printf("\nDo you want to PLANE LIST?\n\n\t\tif YES then press 1 \n\n\t\tif NO, then press 2\n");

	int p;
	scanf("%d",&p);
    for(i=0;i<5;i++)
	{
	    if(p-1==i)
	    {
	        printf("AIRLINES_NAME:");
		puts(db1[i].e_name);
		for(j=0;j<10;j++)
		{
		    printf("        PLANE_NAME:");
		puts(db1[i].p_name[j]);
		}
		}
	}
	fp=fopen("detail.txt","r");
    int plane_name_flag = 0,plane_id_flag = 0,  seatno_flag = 0,time_flag=0,gate_flag=0,date_flag=0;
    char c;

    k = 0;
    i = 0;
    char str2[100];
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n' && plane_name_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            plane_name_flag = 0;
            strcpy(db[k].planename, str2);
            continue;
        }




        if(c == '\n' && plane_id_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            plane_id_flag = 0;
            db[k].plane_id = atoi(str2);
            continue;
        }

        if(c == '\n' && seatno_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            seatno_flag = 0;
            db[k].seatno = atoi(str2);
            continue;
        }



        if(c == '\n' && time_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            time_flag = 0;
            strcpy(db[k].time, str2);
            continue;
        }


        if(c == '\n' && gate_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            gate_flag = 0;
            strcpy(db[k].gate, str2);
            continue;
        }
        if(c == '\n' && date_flag == 1)
        {
            str2[i] = '\0';
            i = 0;
            date_flag = 0;
            strcpy(db[k].date, str2);
            k++;

            continue;
        }

        if(c == ':')
        {
            str2[i] = '\0';
            i = 0;
            if(strcmp(str2, "ID") == 0)
            {
                plane_id_flag = 1;
            }
            if(strcmp(str2, "Plane name") == 0)
            {
                plane_name_flag = 1;
            }
            if(strcmp(str2, "Seat no") == 0)
            {
                seatno_flag = 1;
            }
            if(strcmp(str2, "Time") == 0)
            {
                time_flag = 1;
            }
            if(strcmp(str2, "Gate") == 0)
            {
                gate_flag = 1;
            }

            if(strcmp(str2, "Date") == 0)
            {
                date_flag= 1;
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
    fclose(fp);
   char name[100];
	printf("////////write plane name to know about detail///////\n");

	fflush(stdin);
	gets(name);
   for(i=0;i<10;i++)
	{
	    if(strcmp(db[i].planename,name)==0)
	{

        printf(" \t\t\t\tplane_id =%d\n",db[i].plane_id);
		printf(" \t\t\t\tseatno = %d\n",db[i].seatno);
		printf(" \t\t\t\tTIME:");
		puts(db[i].time);
		printf(" \t\t\t\tGate:");
		puts(db[i].gate);
		printf(" \t\t\t\tDate:");
        puts(db[i].date);

	}

	}
   int l =  db[i].seatno;

	printf("\nDo you want BOOKING TICKET?\n\n\t\t");

	{

        printf("\tPassenger Name.....\n");
        char mn[32];
        gets(mn);
        printf("\t\t\tPassenger Phone NO.....\n");
        char h[15];
        gets(h);
        l--;
        printf("\t\tNow total seat NO:%d\n", l);
        printf("\t\tPassenger Name: ");
        puts(mn);
        printf("\t\tPassenger Phn. NO.: ");
        puts(h);
    }





return 0;
}


