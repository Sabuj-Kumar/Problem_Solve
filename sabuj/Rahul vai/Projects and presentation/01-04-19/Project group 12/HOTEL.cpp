#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct hotel
{
    char Branch_Name[100];
    char Price[100];
    char contact[100];
    int room_count;

}s[10];
int main()
{
    printf("_____By pressing number you can choose your favourite Hotel in Bangladesh____\n\n");
    FILE *a,*b;
    system("color 70");
    a=fopen("Hotel_Name.txt","r");
    char ch;
    while((ch=fgetc(a))!=EOF)

    {
        printf("%c",ch);
    }

    fclose(a);
    int m;
         /*****selection of Catagory******/
    printf("Choose any number of Hotel= ");
    scanf("%d",&m);
    FILE *fp1;

    if(m==1)
    {
        fp1=fopen("Pan_Pacific_Sonargaon.txt","r");
    }
    else if(m==2)
    {
        fp1=fopen("Hotel_Ruposhi_Bangla.txt","r");
    }
    else if(m==3)
    {
        fp1=fopen("Hotel_Regency.txt","r");
    }
    else if(m==4)
    {
        fp1=fopen("Radisson.txt","r");
    }
    else if(m==5)
    {
        fp1=fopen("Westin.txt","r");
    }
     else if(m==6)
    {
        fp1=fopen("Hotel_Washington.txt","r");
    }
     else if(m==7)
    {
        fp1=fopen("Hotel_Royal Park.txt","r");
    }
     else if(m==8)
    {
        fp1=fopen("Hotel_Sarina.txt","r");
    }
     else if(m==9)
    {
        fp1=fopen("Hotel_lake_castale.txt","r");
    }
     else if(m==10)
    {
        fp1=fopen("Hotel_swiss_park.txt","r");
    }
    else
    {
        printf("sorry your number is not correct");

    }




    int i=0,j=0,k,Branch_Name_flag=0,room_count_flag=0,price_flag=0,contact_flag=0;
    char str[100];
    while((ch=fgetc(fp1))!=EOF)
    {
        if(ch=='\n' && Branch_Name_flag==1)
        {
            str[i]='\0';
            i=0;

            Branch_Name_flag=0;
            strcpy(s[j].Branch_Name,str);
        }
        if(ch=='\n' && room_count_flag==1)
        {
            str[i]='\0';
            i=0;

            room_count_flag=0;
            s[j].room_count=atoi(str);
            //j++;
        }
        if(ch=='\n' && contact_flag==1)
        {
            str[i]='\0';
            i=0;
            contact_flag=0;
            strcpy(s[j].contact,str);
            //j++;
        }
         if(ch=='\n' && price_flag==1)
        {
            str[i]='\0';
            i=0;

            price_flag=0;
            strcpy(s[j].Price,str);
            j++;
        }


        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"Branch_Name")==0)
            {
                Branch_Name_flag=1;
            }
            if(strcmp(str,"room_count")==0)
            {
                room_count_flag=1;
            }
             if(strcmp(str,"Price")==0)
            {
                price_flag=1;
            }
            if(strcmp(str,"contact")==0)
            {
                contact_flag=1;
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
    // printf("...............Branch Name: ");
    for(i=0; i<j; i++)
    {
        printf("\n%d...............",i+1);

        puts(s[i].Branch_Name);
        printf("\n\n");
    }
    char t[100];
    printf("Please Enter the branch name : ");
    fflush(stdin);
    gets(t);

    for(i=0; i<j; i++)
    {
        if(strcmp(t,s[i].Branch_Name)==0)
        {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n%d",i+1);
        printf("...............Branch Name: ");
        puts(s[i].Branch_Name);
        fflush(stdin);
        printf("\t\tRoom count: %d\n",s[i].room_count);
        printf("\t\tPrice: ");
        puts(s[i].Price);
        printf("\t\tContact: ");
        puts(s[i].contact);
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
       }
    }


    /*printf("\nDo you want to Book any hotel's Branch in Online\n\n\t\tif YES then press 1 \n\t\tif No then press 2\n");
    int p;
    scanf("%d",&p);

    if(p==1)
    {
        printf("\nPlease choose your favourite branch of hotel= ");
        int z;
        scanf("%d",&z);
        if(z>10)
        {
           printf("\n\n\tthis number is not match the id of branchs\n\n\tif you want to book room than run this software again ");
        }
        else
        {
        printf("\n\nHow many rooms do you want to Book= ");
        int n;
        scanf("%d",&n);
        if(n>100)
        {
                 printf("\n\n\tsorry sir we do not have so mach room that you want");
        }
        else
        {
        printf("\n\nplease give your mastar card's acount number= ");
        int h;
        scanf("%d",&h);
        if(h!=0)
        {
            puts("\n\n\tYOUR ROOM IS BOOKED . THANK YOU SIR FOR THIS BOOKING");

        }
        }
        }

    }
    else
    {
        puts("\n\n\tThank you");
    }
    */
    getch();
    return 0;
}


