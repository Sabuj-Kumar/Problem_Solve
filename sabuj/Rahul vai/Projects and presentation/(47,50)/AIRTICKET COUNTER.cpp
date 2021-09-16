#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct info{
    char ename[100];
    char pname[100];
	char route[100];
	char departure[100];
	char arrival[100];
	char ticket_price[100];
	int capacity;
	int booking_available;
	char p_list[100][100];

}db[100];


int main()
{
	FILE *fp;
	fp=fopen("input.txt","r");
	char ch,str[200];
	int i=0,j=0,k=0,ename_flag=0,pname_flag=0,route_flag=0,departure_flag=0,arrival_flag=0;
	int capacity_flag=0,booking_flag=0,price_flag=0,pass_flag=0,pass_list_flag=0;
	while(1)
    {

	while((ch=fgetc(fp))!=EOF)
	{
		if((ch=='\n') && (ename_flag==1))
		{
			str[i]='\0';
			i=0;
		//	printf("%d	",k);
			strcpy(db[k].ename,str);
			ename_flag=0;
			continue;
		}
		if((ch=='\n') && (pname_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].pname,str);
			pname_flag=0;
			continue;
		}
		if((ch=='\n') && (route_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].route,str);
			route_flag=0;
			continue;
		}
		if((ch=='\n') && (departure_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].departure,str);
			departure_flag=0;
			continue;
		}
		if((ch=='\n') && (arrival_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].arrival,str);
			arrival_flag=0;
			continue;
		}
		if((ch=='\n') && (capacity_flag==1))
		{
			str[i]='\0';
			i=0;
			db[k].capacity=atoi(str);
			capacity_flag=0;
			continue;
		}
		if((ch=='\n') && (booking_flag==1))
		{
			str[i]='\0';
			i=0;
			db[k].booking_available=atoi(str);
			booking_flag=0;
			continue;
		}
		if((ch=='\n') && (price_flag==1))
		{
			str[i]='\0';
			i=0;
			strcpy(db[k].ticket_price,str);
			price_flag=0;
			continue;
		}
		if((ch=='\n') && (pass_flag==1))
		{
			pass_flag=0;
			pass_list_flag=1;
			continue;
		}
		if(ch==':')
		{
			str[i]='\0';
			i=0;
			if(strcmp(str,"ename")==0)
			{
				ename_flag=1;
				//printf("%d	",k);
			}
			if(strcmp(str,"pname")==0)
			{
				pname_flag=1;
				//printf("%d	",k);
			}
			if(strcmp(str,"route")==0)
			{
				route_flag=1;
			}
			if(strcmp(str,"departure")==0)
			{
				departure_flag=1;
			}
			if(strcmp(str,"arrival")==0)
			{
				arrival_flag=1;
			}
			if(strcmp(str,"capacity")==0)
			{
				capacity_flag=1;
			}
			if(strcmp(str,"booking_available")==0)
			{
				booking_flag=1;
			}
			if(strcmp(str,"ticket_price")==0)
			{
				price_flag=1;
			}

			if(strcmp(str,"p_list")==0)
			{
				pass_flag=1;
			}
			continue;
		}

		else if((pass_list_flag==1) && (ch=='\n'))
		{

			str[i]='\0';
			i=0;
			strcpy(db[k].p_list[j],str);

			j++;
			continue;
		}
		else if(ch==';')
		{

			str[i]='\0';
			i=0;
			strcpy(db[k].p_list[j],str);

			k++;

			j=0;
			pass_list_flag=0;
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
	printf("********************oooooooooooooooooooooooo*********************\n");
    printf("*                         AIR TICKET COUNTER                    *\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("*                                                               *\n");
    printf("*********************ooooooooooooooooooooooo*********************\n\n");
	int n;
	scanf("%d",&n);
    for(i=n-1; i<n; i++)
	{
		puts(db[i].ename);
		puts(db[i].pname);
		puts(db[i].route);
		puts(db[i].departure);
		puts(db[i].arrival);
		printf("capacity=%d\n",db[i].capacity);
		printf("booking available=%d\n",db[i].booking_available);
		puts(db[i].ticket_price);
		for(j=0;j<5;j++)
		{
			puts(db[i].p_list[j]);
		}
		printf("\n\n");
	}
    }
}
